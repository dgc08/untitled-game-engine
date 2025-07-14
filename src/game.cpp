#include "cpp_core.hpp"

#include <stdlib.h>
#include <iostream>
#include <string>
#include <execinfo.h>

namespace rl {
#include <raylib.h>
}

static GameTree game;

struct {
    GameObject* scene;
} game_data;

GameTree* get_tree () {
    return &game;
}

GameObject* get_root () {
    return game_data.scene;
}

static void stub_impl (GameObject*, GameTree*) {}

void load_scene (GameObject* scene) {
    if (game_data.scene) {
        dequeue(game_data.scene);
    }
    game_data.scene = scene;
}

GameObject* make_gameObject (void(*load)(GameObject*, GameTree*), void(*update)(GameObject*, GameTree*), void(*draw)(GameObject*, GameTree*), void(*end)(GameObject*, GameTree*),size_t extra_size) {
    GameObject* g = new GameObject;

    g->data = new GameObjectData;
    if (extra_size)
        g->c_extra = ::operator new(extra_size);

    g->type = GameObjectType_Generic;

    g->x = 0;
    g->y = 0;

    g->on_end = end ? end : stub_impl;
    g->on_draw = draw ? draw : stub_impl;
    g->on_update = update ? update : stub_impl;
    g->on_load = load ? load : stub_impl;

    return g;
}

void dequeue(GameObject* g) {
    g->on_end(g, &game);

    GameObjectData* data = (GameObjectData*)g->data;

    for (auto& child : data->children) {
        dequeue(child);
    }

    if (g->c_extra)
        ::operator delete (g->c_extra);
    delete data;
    delete g;
}

void do_update (GameObject* g) {
    GameObjectData* data = (GameObjectData*)g->data;

    g->on_update(g, &game);

    for (auto& child : data->children) {
        do_update(child);
    }
}

void do_load (GameObject* g) {
    GameObjectData* data = (GameObjectData*)g->data;

    g->on_load(g, &game);

    for (auto& child : data->children) {
        do_load(child);
    }
}

void do_draw (GameObject* g) {
    GameObjectData* data = (GameObjectData*)g->data;

    g->on_draw(g, &game);

    for (auto& child : data->children) {
        child->x += g->x;
        child->y += g->y;
        do_draw(child);
        child->y -= g->y;
        child->x -= g->x;
    }
}

GameObject** get_children (GameObject* g) {
    return ((GameObjectData*)g->data)->children.data();
}

GameObject* get_parent (GameObject* g) {
    return ((GameObjectData*)g->data)->parent;
}

void reg_obj (GameObject* parent, GameObject* child, char* name) {
    // Discard name for now
    (void)name;

    GameObjectData* data = (GameObjectData*)parent->data;

    GameObjectData* data_child = (GameObjectData*)child->data;

    data_child->parent = parent;
    data->children.push_back(child);
}

void run_game_loop () {
    bool raylib = true;
    if (game.width == 0 || game.height == 0) {
        raylib = false;
    }

    if (raylib)
        rl::InitWindow(game.width, game.height, game.window_name);

    bool is_running = game_data.scene != nullptr;
    do_load(get_root());
    while (is_running) {
        if (raylib)
            is_running &= !rl::WindowShouldClose();

        game.delta = rl::GetFrameTime();
        game.time = rl::GetTime();

        do_update(game_data.scene);

        if (raylib) {
            rl::BeginDrawing();
                ClearBackground( CONV(game.background_color, rl::Color) );
                do_draw(game_data.scene);
            rl::EndDrawing();
        }

    }
    if (raylib)
        rl::CloseWindow();
}

void engine_error(std::string msg) {
    // Print your error message
    std::cerr << "Engine error: " << msg << std::endl;

    std::vector<void*> stack(10);
    int size = backtrace(stack.data(), stack.size());
    char** symbols = backtrace_symbols(stack.data(), size);

    if (symbols) {
        std::cerr << "Backtrace:\n";
        for (int i = 0; i < size; ++i)
            std::cerr << symbols[i] << '\n';
        free(symbols);
    }
    
    exit(EXIT_FAILURE);
}
