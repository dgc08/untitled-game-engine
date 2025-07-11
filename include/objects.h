#ifndef OBJECTS_H_
#define OBJECTS_H_

#ifndef GAME_CORE_H_
#include "game_core.h"
#else
struct Color {unsigned int color;};
struct GameObject;
#endif

GameObject* make_gameText(char* text, const char* font_path, float font_size, Color color);
void configure_gameText(GameObject* self, float fontSize, float spacing, Color color);

#endif // OBJECTS_H_
