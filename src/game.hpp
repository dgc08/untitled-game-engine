#ifndef GAME_H_
#define GAME_H_

#include <string>
#include <memory>

#include "cpp_utils.hpp"


extern "C" namespace core {
    #include "game_core.h"
}

// COLORS

namespace Colors {
    const core::Color lightgray  = { 200, 200, 200, 255 };   // Light Gray
    const core::Color gray       = { 130, 130, 130, 255 };   // Gray
    const core::Color darkgray   = { 80, 80, 80, 255 };      // Dark Gray
    const core::Color yellow     = { 253, 249, 0, 255 };     // Yellow
    const core::Color gold       = { 255, 203, 0, 255 };     // Gold
    const core::Color orange     = { 255, 161, 0, 255 };     // Orange
    const core::Color pink       = { 255, 109, 194, 255 };   // Pink
    const core::Color red        = { 230, 41, 55, 255 };     // Red
    const core::Color maroon     = { 190, 33, 55, 255 };     // Maroon
    const core::Color green      = { 0, 228, 48, 255 };      // Green
    const core::Color lime       = { 0, 158, 47, 255 };      // Lime
    const core::Color darkgreen  = { 0, 117, 44, 255 };      // Dark Green
    const core::Color skyblue    = { 102, 191, 255, 255 };   // Sky Blue
    const core::Color blue       = { 0, 121, 241, 255 };     // Blue
    const core::Color darkblue   = { 0, 82, 172, 255 };      // Dark Blue
    const core::Color purple     = { 200, 122, 255, 255 };   // Purple
    const core::Color violet     = { 135, 60, 190, 255 };    // Violet
    const core::Color darkpurple = { 112, 31, 126, 255 };    // Dark Purple
    const core::Color beige      = { 211, 176, 131, 255 };   // Beige
    const core::Color brown      = { 127, 106, 79, 255 };    // Brown
    const core::Color darkbrown  = { 76, 63, 47, 255 };      // Dark Brown
    
    const core::Color white      = { 255, 255, 255, 255 };   // White
    const core::Color black      = { 0, 0, 0, 255 };         // Black
    const core::Color blank      = { 0, 0, 0, 0 };           // Blank (Transparent)
    const core::Color magenta    = { 255, 0, 255, 255 };     // Magenta
    const core::Color raywhite   = { 245, 245, 245, 255 };   // White raylib logo
}

class Node: public core::GameObject {
    public:
        ~Node();
        Node();

        virtual void update(core::GameTree*) {};
        virtual void draw(core::GameTree*) {};
};

#endif // GAME_H_
