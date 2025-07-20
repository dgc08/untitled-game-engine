#include "objects.hpp"
#include "cpp_core.hpp"

static void on_draw_rect(core::GameObject* self, core::GameTree *) {
      Rect* r = (Rect*)self;
      rl::DrawRectanglePro({r->pos.x, r->pos.y, r->size.x, r->size.y}, CONV(r->origin, rl::Vector2), r->rotation, CONV(r->color, rl::Color));
}

Rect::Rect(Vector2 pos, Vector2 size, Color color) {
    this->type = core::GameObjectType_Rect;
    this->pos = CONV(pos, core::Vector2);
    this->color = CONV(color, core::Color);
    this->size = CONV(size, core::Vector2);

    this->on_draw = on_draw_rect;
}

GameObject* make_gameRect (Vector2 pos, Vector2 size, Color color) {
    core::GameObject* ret = (core::GameObject*) new Rect(pos, size, color);
    return (GameObject*) ret;
}

void configure_gameRect(GameObject* self, Vector2 size, Color color) {
    Rect* r = (Rect*) (core::GameObject*) self;
    r->size = CONV(size, core::Vector2);
    r->color = CONV(color, core::Color);
}
