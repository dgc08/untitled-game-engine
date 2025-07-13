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
typedef void (*GameObjFunc)(struct GameObject* self, struct GameTree* tree);

// GAME OBJECTS
typedef struct GameObject {
    GameObjFunc on_load;
    GameObjFunc on_update;
    GameObjFunc on_draw;
    GameObjFunc on_end;

    float x;
    float y;

    void* data; // DO NOT USE THIS
                // Data is of type GameObjectData and is private for the Game Engine
    void* c_extra; // Use this, for extra data
} GameObject;

// Game
typedef struct GameTree {
    float delta;
    float time;

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
void reg_obj(GameObject* parent, GameObject* child, char* name);

GameObject** get_children (GameObject* g);
GameObject* get_parent (GameObject* g);

void run_game_loop();


#endif // GAME_CORE_H_
