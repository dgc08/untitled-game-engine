#include "game.hpp"
#include <stdlib.h>

using namespace core;

void on_update_node (GameObject* self, GameTree* ctx) {
    ((Node*)self)->update(ctx);
}

void on_draw_node (GameObject* self, GameTree* ctx) {
    ((Node*)self)->draw(ctx);
}

Node::Node() {
    this->on_update = on_update_node;
    this->on_draw = on_draw_node;

    this->use_cpp_alloc = true;
}

Node::~Node() {
    core::dequeue(this);
}
