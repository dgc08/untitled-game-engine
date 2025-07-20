#ifndef OBJECTS_H_
#define OBJECTS_H_

#ifndef GAME_CORE_H_
#include "game_core.h"
#else
struct Color {unsigned int color;};
struct GameObject;
struct Vector2 {float x; float y;};
#endif

GameObject* make_gameText(const char* text, const char* font_path, float font_size, Color color);
void configure_gameText(GameObject* self, float fontSize, float spacing, Color color);
void set_gameText_text(GameObject* self, const char* text);

GameObject* make_gameRect(Vector2 pos, Vector2 size, Color color);
void configure_gameRect(GameObject* self, Vector2 size, Color color);

#endif // OBJECTS_H_
