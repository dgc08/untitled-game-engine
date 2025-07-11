#include "objects.hpp"
#include "objects.h"
#include <string>

namespace rl {
    #include <raylib.h>
}

Text::Text(std::string text, int font_size, core::Color color) {
    this->text = text;
    this->font_size = font_size;
    this->color = color;
}

static void on_draw_text(core::GameObject* self, core::GameTree *) {
      Text* t = (Text*)self;
      rl::DrawText(t->text.c_str(), t->x, t->y, t->font_size, CONV(t->color, rl::Color));
}

GameObject* make_gameText (char* text, int font_size, Color color) {
    core::GameObject* ret = (core::GameObject*) new Text(std::string(text), font_size, CONV(color, core::Color));
    ret->on_update = on_draw_text;
    return (GameObject*) ret;
}
