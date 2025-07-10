#include <stdio.h>

//#include "src/game.hpp"
#include "src/game_core.h"

void on_update (GameObject* self, GameTree* ctx) {
    printf("Hello from C!!\n");
}

int main(void) {
    GameTree* tree = get_tree();

    tree->height = 480;
    tree->width = 800;
    tree->window_name = "Hello from engine";
    tree->window_name = "Jajaa";

    tree->background_color = (Color) { 0, 0, 0, 255 };

    GameObject* g = make_gameObject(NULL, on_update);
    //gameObject_initialize(g, NULL, on_update);
    load_scene(g);

    run_game_loop();

    return 0;
}
