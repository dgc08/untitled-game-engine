#include <stdlib.h>

extern "C" {
#include "game_core.h"
}

#include "cpp_utils.hpp"

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

void stub_impl (GameObject*, GameTree*) {}

GameObject* gameObject_initialize (GameObject* g, void(*draw)(GameObject*, GameTree*), void(*update)(GameObject*, GameTree*)) {
    g->on_draw = draw ? draw : stub_impl;
    g->on_update = update ? update : stub_impl;

    return g;
}

void load_scene (GameObject* scene) {
    if (game_data.scene) {
        dequeue(game_data.scene);
    }
    game_data.scene = scene;
}

void run_game_loop () {
    if (game.width == 0 || game.height == 0) {
        return;
    }
    rl::InitWindow(game.width, game.height, game.window_name);

    bool is_running = game_data.scene != nullptr;
    while (is_running) {
        is_running &= !rl::WindowShouldClose();
        game_data.scene->on_update(game_data.scene, &game);

        rl::BeginDrawing();
            ClearBackground( *(rl::Color*)(&game.background_color) );
            rl::DrawText("Congrats! You created your first window!", 190, 200, 20, rl::LIGHTGRAY);
        rl::EndDrawing();

    }

    rl::CloseWindow();
}

void dequeue(GameObject* g) {
    if (g->use_cpp_alloc)
        delete g;
    else
        free(g);
}
