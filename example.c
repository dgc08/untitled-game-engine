#include <stdio.h>

//#include "src/game.hpp"
#include "src/game_core.h"

void on_update (GameTree* ctx) {
    printf("hihhk\n");
}


int main(void) {
    GameTree* tree = get_tree();

    tree->height = 480;
    tree->width = 800;
    tree->window_name = "Hello from engine";
    tree->window_name = "Jajaa";

    tree->background_color = (Color) { 0, 0, 0, 255 };

    GameObject g;
    tree->scene = &g;
    gameObject_initialize(tree->scene, NULL, on_update);

    run_game_loop();

    return 0;
}
