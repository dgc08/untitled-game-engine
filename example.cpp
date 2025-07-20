#include <iostream>

#include "game.hpp"
#include "objects.hpp"

using namespace core;

class Lobby: public Node {
    void load(GameTree* ctx);
};

class Button: public Node {
    void load(GameTree* ctx);
};

void Lobby::load(GameTree* ctx) {
    std::cout << "mogus" << std::endl;
}
void Button::load(GameTree* ctx) {
    std::cout << "bogus" << std::endl;
}

int main(void) {
    core::GameTree* tree = core::get_tree();

    tree->height = 480;
    tree->width = 800;
    tree->window_name = "Hello from engine";
    tree->window_name = "Jajaa";

    tree->background_color = Colors::black;

    load_scene(new Lobby);
    core::reg_obj(core::get_root(), new Button, nullptr);
    auto t = new Text("Hello and welcome", "PixelOperator.ttf", 20, Colors::lightgray);
    t->pos.x = 190;
    t->pos.y = 200,

    core::reg_obj(core::get_root(), t, nullptr);

    run_game_loop();

    return 0;
}
