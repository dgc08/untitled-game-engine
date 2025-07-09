#ifndef GAME_H_
#define GAME_H_

#include <cstdint>
#include <string>
#include <memory>

typedef uint32_t u32;
typedef int32_t i32 ;
typedef uint8_t u8;

// Raylib redef
#ifndef RAYLIB_H
typedef struct { u8 r; u8 g; u8 b; u8 a;} Color;
#endif

// COLORS

namespace Colors {
    const Color lightgray  = { 200, 200, 200, 255 };   // Light Gray
    const Color gray       = { 130, 130, 130, 255 };   // Gray
    const Color darkgray   = { 80, 80, 80, 255 };      // Dark Gray
    const Color yellow     = { 253, 249, 0, 255 };     // Yellow
    const Color gold       = { 255, 203, 0, 255 };     // Gold
    const Color orange     = { 255, 161, 0, 255 };     // Orange
    const Color pink       = { 255, 109, 194, 255 };   // Pink
    const Color red        = { 230, 41, 55, 255 };     // Red
    const Color maroon     = { 190, 33, 55, 255 };     // Maroon
    const Color green      = { 0, 228, 48, 255 };      // Green
    const Color lime       = { 0, 158, 47, 255 };      // Lime
    const Color darkgreen  = { 0, 117, 44, 255 };      // Dark Green
    const Color skyblue    = { 102, 191, 255, 255 };   // Sky Blue
    const Color blue       = { 0, 121, 241, 255 };     // Blue
    const Color darkblue   = { 0, 82, 172, 255 };      // Dark Blue
    const Color purple     = { 200, 122, 255, 255 };   // Purple
    const Color violet     = { 135, 60, 190, 255 };    // Violet
    const Color darkpurple = { 112, 31, 126, 255 };    // Dark Purple
    const Color beige      = { 211, 176, 131, 255 };   // Beige
    const Color brown      = { 127, 106, 79, 255 };    // Brown
    const Color darkbrown  = { 76, 63, 47, 255 };      // Dark Brown
    
    const Color white      = { 255, 255, 255, 255 };   // White
    const Color black      = { 0, 0, 0, 255 };         // Black
    const Color blank      = { 0, 0, 0, 0 };           // Blank (Transparent)
    const Color magenta    = { 255, 0, 255, 255 };     // Magenta
    const Color raywhite   = { 245, 245, 245, 255 };   // White raylib logo
}

struct GameTree;

// GAME OBJECTS
class GameObject {
    public:
        virtual void on_update(GameTree* ctx) {};
        virtual void on_draw(GameTree* ctx) {};
};

// Game
struct GameTree {
    u32 width;
    u32 height;

    const char* window_name;

    Color background_color;
    std::shared_ptr<GameObject> scene;
};


GameTree* get_tree();

void run_game_loop();

#endif // GAME_H_
