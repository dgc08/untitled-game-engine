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

typedef void (*GameObjFunc)(struct GameObject* self, struct GameTree* tree);
typedef struct { u8 r; u8 g; u8 b; u8 a;} Color;

typedef struct { float x; float y;} Vector2;
typedef struct { float x; float y; float z;} Vector3;

const int GameObjectType_Generic = 0;
const int GameObjectType_Text = -1;
const int GameObjectType_Rect = -2;

// GAME OBJECTS
typedef struct GameObject {
    int type;
    bool is_generic_node; // if the object is a Node (only C++)
    
    GameObjFunc on_load;
    GameObjFunc on_update;
    GameObjFunc on_draw;
    GameObjFunc on_end;

    Vector2 pos;
    float rotation;
    Vector2 origin; // origin of rotation (if the type implements it)

    void* data; // DO NOT USE THIS
                // Data is of type GameObjectData and is private for the Game Engine
    void* c_extra; // Use this for extra data
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
void reg_obj(GameObject* parent, GameObject* child, const char* name);

GameObject** get_children (GameObject* g);
GameObject* get_parent (GameObject* g);

void run_game_loop();

float rand_float();
int rand_int(int min, int max);

#endif // GAME_CORE_H_
