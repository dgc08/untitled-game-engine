#include "objects.hpp"
#include "cpp_core.hpp"
#include <string.h>
#include <string>

#include <iostream>

namespace rl {
    #include <raylib.h>
}


static void on_load_text (core::GameObject* self, core::GameTree *) {
    Text* t = (Text*)self;

    if (t->font_path) {
        t->font = rl::LoadFontEx(t->font_path, 32, 0, 250);
    }
    else {
        t->font = rl::GetFontDefault();
    }
}

static void on_draw_text(core::GameObject* self, core::GameTree *) {
      Text* t = (Text*)self;
      rl::Font font = t->font;
      rl::DrawTextPro(font, t->text.c_str(), CONV(t->pos, rl::Vector2), CONV(t->origin, rl::Vector2), t->rotation, t->font_size, t->spacing, CONV(t->color, rl::Color));
}

Text::Text(std::string text, const char* font_path, float font_size, core::Color color) {
    this->type = core::GameObjectType_Text;
    this->text = text;
    this->font_size = font_size;
    this->color = color;

    this->spacing = 2;

    this->font_path = font_path;

    this->on_draw = on_draw_text;
    this->on_load = on_load_text;
}


GameObject* make_gameText (const char* text, const char* font_path, float font_size, Color color) {
    core::GameObject* ret = (core::GameObject*) new Text(std::string(text), font_path, font_size, CONV(color, core::Color));
    return (GameObject*) ret;
}

void configure_gameText(GameObject* self, float fontSize, float spacing, Color color) {
    Text* t = (Text*) (core::GameObject*) self;
    t->font_size = fontSize;
    t->spacing = spacing;
    t->color = CONV(color, core::Color);
}

void set_gameText_text(GameObject* self, const char* text) {
    core::GameObject* g = (core::GameObject*) self;
    if (g->type != core::GameObjectType_Text) {
        engine_error("GameObject supplied to set_gameText_text is not a Text");
    }
    Text* t = (Text*) g;
    t->text = std::string(text);
}
