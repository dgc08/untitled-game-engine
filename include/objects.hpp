#ifndef OBJECTS_HPP_
#define OBJECTS_HPP_

#include "game.hpp"

extern "C" {
    #include "objects.h"
}

class Text: public Node {
    public:
        Text(std::string text, int font_size, core::Color color);
        
        std::string text;
        int font_size;
        core::Color color;
};

#endif // OBJECTS_H_
