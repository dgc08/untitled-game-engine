#include <raylib.h>
#include "game.hpp"
#include "game_core.h"

static GameTree game;

GameTree* get_tree () {
    return &game;
}

void stub_impl (GameTree*) {}

void gameObject_initialize (GameObject* g, void(*draw)(GameTree*), void(*update)(GameTree*)) {
    g->on_draw = draw ? draw : stub_impl;
    g->on_update = update ? update : stub_impl;

    g->is_available = true;
}

void run_game_loop () {
    if (game.width == 0 || game.height == 0) {
        return;
    }
    InitWindow(game.width, game.height, game.window_name);

    bool is_running = game.scene != nullptr;
    while (is_running) {
        is_running &= !WindowShouldClose();
        game.scene->on_update(&game);

        BeginDrawing();
            ClearBackground( *(Color*)(&game.background_color) );
            DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);
        EndDrawing();

    }

    CloseWindow();
}
