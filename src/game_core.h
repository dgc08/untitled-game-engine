#ifndef GAME_CORE_H_
#define GAME_CORE_H_

#include <stdint.h>

// C / C++ shared header file

typedef uint32_t u32;
typedef int32_t i32 ;
typedef uint8_t u8;

#ifndef __cplusplus
typedef u8 bool;
#endif

// Raylib redef
#ifndef RAYLIB_H
typedef struct { u8 r; u8 g; u8 b; u8 a;} Color;
#endif


struct GameTree;

// GAME OBJECTS
typedef struct GameObject {
    bool is_available;
    void (*on_update)(struct GameTree*);
    void (*on_draw)(struct GameTree*);
} GameObject;

// Game
typedef struct GameTree {
    u32 width;
    u32 height;
    const char* window_name;
    Color background_color;
    GameObject* scene;
} GameTree;

void gameObject_initialize (GameObject* g, void(*draw)(GameTree*), void(*update)(GameTree*));

GameTree* get_tree();
void run_game_loop();

#endif // GAME_CORE_H_
