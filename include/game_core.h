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

#define CONV(val, T) ( *(T*)&val )

typedef struct { u8 r; u8 g; u8 b; u8 a;} Color;

typedef struct GameTree GameTree;
typedef struct GameObject GameObject;

// GAME OBJECTS
typedef struct GameObject {
    void (*on_load)(GameObject* self, struct GameTree*);
    void (*on_update)(GameObject* self, struct GameTree*);
    void (*on_draw)(GameObject* self, struct GameTree*);
    void (*on_end)(GameObject* self, struct GameTree*);

    float x;
    float y;

    void* data; // DO NOT USE THIS
                // Data is of type GameObjectData and is private for the Game Engine
    void* c_extra; // Use this, for extra data
} GameObject;

// Game
typedef struct GameTree {
    u32 width;
    u32 height;
    const char* window_name;
    Color background_color;
} GameTree;

GameTree* get_tree();
GameObject* get_root();
void load_scene(GameObject*);

GameObject* make_gameObject (void(*load)(GameObject*, GameTree*), void(*update)(GameObject*, GameTree*), void(*draw)(GameObject*, GameTree*), void(*dequeue)(GameObject*, GameTree*),size_t extra_c_size);
void dequeue(GameObject*);
GameObject** get_children (GameObject* g);
void reg_obj(GameObject* parent, GameObject* child, char* name);

void run_game_loop();


#endif // GAME_CORE_H_
