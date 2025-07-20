#ifndef OBJECTS_HPP_
#define OBJECTS_HPP_

#include "game.hpp"

extern "C" {
    #include "objects.h"
}

class Text: public Node {
    public:
        Text(std::string text, const char* font_path, float font_size, core::Color color);
        
        std::string text;
        float font_size;
        core::Color color;

        rl::Font font;
        const char* font_path;
        float spacing;
};

class Rect: public Node {
    public:
        Rect(Vector2 pos, Vector2 size, Color color);

        core::Vector2 size;
        core::Color color;
};

#endif // OBJECTS_H_
