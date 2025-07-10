#include <iostream>

#include "src/game.hpp"
#include "src/game_core.h"

using namespace core;

class Lobby: public Node {
    void update(GameTree* ctx);
};

void Lobby::update(GameTree* ctx) {
    std::cout << "mogus" << std::endl;
}

int main(void) {
    GameTree* tree = get_tree();

    tree->height = 480;
    tree->width = 800;
    tree->window_name = "Hello from engine";
    tree->window_name = "Jajaa";

    tree->background_color = Colors::black;

    load_scene(new Lobby);
    //gameObject_initialize(tree->scene, nullptr, Lobby::on_update);

    run_game_loop();

    return 0;
}
