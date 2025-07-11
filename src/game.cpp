#include "cpp_core.hpp"

#include <stdlib.h>

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

GameObject* make_gameObject (void(*draw)(GameObject*, GameTree*), void(*update)(GameObject*, GameTree*)) {
    GameObject* g = new GameObject;

    g->data = new GameObjectData;

    g->x = 0;
    g->y = 0;

    g->on_draw = draw ? draw : stub_impl;
    g->on_update = update ? update : stub_impl;

    return g;
}

void dequeue(GameObject* g) {
    GameObjectData* data = (GameObjectData*)g->data;

    for (auto& child : data->children) {
        dequeue(child);
    }

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
    while (is_running) {
        if (raylib)
            is_running &= !rl::WindowShouldClose();
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
