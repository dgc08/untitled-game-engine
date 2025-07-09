#include <iostream>

#include "src/game.hpp"
#include "src/game_core.h"

namespace Lobby {
    void on_update (GameTree* ctx) {
        std::cout << "hieiohe" << std::endl;
    }
}

int main(void) {
    GameTree* tree = get_tree();

    tree->height = 480;
    tree->width = 800;
    tree->window_name = "Hello from engine";
    tree->window_name = "Jajaa";

    tree->background_color = Colors::black;

    tree->scene = new GameObject;
    gameObject_initialize(tree->scene, nullptr, Lobby::on_update);

    run_game_loop();

    return 0;
}
