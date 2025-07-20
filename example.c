#include <stdlib.h>
#include <string.h>
#include <stdio.h>

//#include "src/game.hpp"
#include "game.h"
#include "game_core.h"
#include "objects.h"

typedef struct {
    float last;
    char* msg;
    size_t len;
    int pos;
} text_ctr;

void text_ctr_load (GameObject* self, GameTree* ctx) {
    text_ctr *data = self->c_extra;
    data->last = ctx->time;
    data->msg = strdup("Hello Good Morning");
    data->len = strlen(data->msg);
    data->pos = 0;

    printf("loaded text ctr\n");
}

void text_ctr_update (GameObject* self, GameTree* ctx) {
    text_ctr *data = self->c_extra;

    if (ctx->time-data->last < 0.5) {
        return;
    }
    data->last = ctx->time;


    data->pos = (data->pos+1) % (data->len+1);
    int pos = data->pos;

    char tmp = data->msg[pos];
    data->msg[pos] = '\0';
    set_gameText_text(get_parent(self), data->msg);
    data->msg[pos] = tmp;
}


int main(void) {
    GameTree* tree = get_tree();

    tree->height = 480;
    tree->width = 800;
    tree->window_name = "Jajaa";

    tree->background_color = BLACK;

    GameObject* text = make_gameText("", "PixelOperator.ttf", 35, LIGHTGRAY);
    text->pos.x = 30;
    text->pos.y = 200;

    GameObject* text_ctr_obj = make_gameObject(text_ctr_load, text_ctr_update, NULL, NULL, sizeof(text_ctr));
    reg_obj(text, text_ctr_obj, NULL);

    load_scene(text);

    run_game_loop();

    return 0;
}
