#include "game.hpp"
#include "cpp_core.hpp"

#include <stdlib.h>

void on_update_node (core::GameObject* self, core::GameTree* ctx) {
    ((Node*)self)->update(ctx);
}

void on_draw_node (core::GameObject* self, core::GameTree* ctx) {
    ((Node*)self)->draw(ctx);
}

Node::Node () {
    this->data = new GameObjectData;

    this->x = 0;
    this->y = 0;

    this->on_update = on_update_node;
    this->on_draw = on_draw_node;
}

Node::~Node () {
    core::dequeue(this);
}
