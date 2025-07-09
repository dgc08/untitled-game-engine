#include <raylib.h>
#include "game.hpp"

static GameTree game;

GameTree* get_tree() {
    return &game;
}

void run_game_loop() {
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
