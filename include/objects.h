#ifndef OBJECTS_H_
#define OBJECTS_H_

#ifndef GAME_CORE_H_
#include "game_core.h"
#else
struct Color {unsigned int color;};
struct GameObject;
#endif

GameObject* make_gameText(char* text, int font_size, Color color);

#endif // OBJECTS_H_
