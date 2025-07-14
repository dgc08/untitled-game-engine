#include "game.hpp"
#include "cpp_core.hpp"

#include <stdlib.h>

void on_load_node (core::GameObject* self, core::GameTree* ctx) {
    ((Node*)self)->load(ctx);
}

void on_update_node (core::GameObject* self, core::GameTree* ctx) {
    ((Node*)self)->update(ctx);
}

void on_draw_node (core::GameObject* self, core::GameTree* ctx) {
    ((Node*)self)->draw(ctx);
}

void on_end_node (core::GameObject* self, core::GameTree* ctx) {
    ((Node*)self)->end(ctx);
}

Node::Node () {
    this->data = new GameObjectData;

    this->type = core::GameObjectType_Generic;

    this->x = 0;
    this->y = 0;

    this->on_load = on_load_node;
    this->on_update = on_update_node;
    this->on_draw = on_draw_node;
    this->on_end = on_end_node;
}

Node::~Node () {
    core::dequeue(this);
}
