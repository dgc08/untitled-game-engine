#include <stdio.h>

//#include "src/game.hpp"
#include "game.h"
#include "objects.h"

void on_update (GameObject* self, GameTree* ctx) {
    printf("Hello from C!!\n");
}

int main(void) {
    GameTree* tree = get_tree();

    tree->height = 480;
    tree->width = 800;
    tree->window_name = "Hello from engine";
    tree->window_name = "Jajaa";

    tree->background_color = BLACK;

    GameObject* g = make_gameObject(NULL, on_update);
    GameObject* text = make_gameText("hello my guys", 20, LIGHTGRAY);
    text->x = 190;
    text->y = 200;
    //gameObject_initialize(g, NULL, on_update);
    load_scene(text);

    run_game_loop();

    return 0;
}
