#ifndef GAME_CORE_H_
#define GAME_CORE_H_

// C / C++ shared header file

#include <stdint.h>

typedef uint32_t u32;
typedef int32_t i32 ;
typedef uint8_t u8;

#ifndef __cplusplus
typedef u8 bool;
#include <stdlib.h>
#endif

typedef struct { u8 r; u8 g; u8 b; u8 a;} Color;
struct GameTree;
typedef struct GameObject GameObject;

// GAME OBJECTS
typedef struct GameObject {
    void (*on_update)(GameObject* self, struct GameTree*);
    void (*on_draw)(GameObject* self, struct GameTree*);

    void* private_d;
} GameObject;

// Game
typedef struct GameTree {
    u32 width;
    u32 height;
    const char* window_name;
    Color background_color;
} GameTree;

GameObject* make_gameObject (void(*draw)(GameObject*, GameTree*), void(*update)(GameObject*, GameTree*));

GameTree* get_tree();
GameObject* get_root();
void load_scene(GameObject*);

void run_game_loop();
void dequeue(GameObject*);


#endif // GAME_CORE_H_
