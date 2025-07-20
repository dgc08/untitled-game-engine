#include "game.hpp"
#include "cpp_core.hpp"
#include "game_core.h"

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
    this->is_generic_node = true;

    this->pos = {0,0};

    this->on_load = on_load_node;
    this->on_update = on_update_node;
    this->on_draw = on_draw_node;
    this->on_end = on_end_node;

}

Node::~Node () {
    core::dequeue(this);
}

inline void Node::dequeue() {
    core::dequeue(this);
}

inline void Node::reg_obj(core::GameObject* child, char* name) {
    core::reg_obj(this, child, name);
}

inline void Node::reg_obj(Node* child, std::string name) {
    core::reg_obj(this, child, name.c_str());
}


std::vector<Node*> Node::get_children() {
    GameObjectData* data = CONV(this->data, GameObjectData*);
    std::vector<Node*> ret = {};
    for (auto child: data->children) {
        core::GameObject* tmp = (core::GameObject*) child;
        if (tmp->is_generic_node) {
            ret.push_back((Node*)tmp);
        }
    }
    return ret;
}

Node* Node::get_parent() {
    GameObjectData* data = CONV(this->data, GameObjectData*);
    core::GameObject* parent = CONV(data->parent, core::GameObject*);
    if (parent && parent->is_generic_node) {
        return (Node*) parent;
    }
    else
        return nullptr;
}


inline core::GameObject** Node::get_children_all() {
    return core::get_children(this);
}

inline core::GameObject* Node::get_parent_all() {
    return core::get_parent(this);
}
