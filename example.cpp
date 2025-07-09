#include "src/game.hpp"
#include <iostream>

class Lobby: public GameObject {
    public:
        void on_update(GameTree*);
};

void Lobby::on_update(GameTree* ctx) {
    std::cout << "hello from lobby" << std::endl;
}

int main(void) {
    GameTree* tree = get_tree();

    tree->height = 480;
    tree->width = 800;
    tree->window_name = "Hello from engine";
    tree->window_name = "Jajaa";

    tree->background_color = Colors::black;

    tree->scene = std::make_shared<Lobby>();

    run_game_loop();

    return 0;
}
