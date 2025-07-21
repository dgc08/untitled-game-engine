#ifndef CPP_UTILS_H_
#define CPP_UTILS_H_

#include <string>
#include <map>
#include <vector>

extern "C" {
    #ifndef GAME_CORE_H_
        #include "game_core.h"
    #else
        struct GameObject;
    #endif
}

typedef struct {
    std::vector<GameObject*> children;
    std::map<std::string, GameObject*> named_children;
    GameObject* parent;
} GameObjectData;

void perform_dequeue(GameObject* g);

void engine_error(std::string msg);
#endif // CPP_UTILS_H_
