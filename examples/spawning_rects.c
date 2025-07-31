#include "game.h"
#include "objects.h"

#define RECT_INTERVAL 0.05
float new_rect_time = RECT_INTERVAL;

void rect_update (GameObject* self, GameTree* ctx) {
    Vector3* data = self->c_extra;
    GameObject* parent = get_parent(self);
    if (data->z <= 0) {
        dequeue(parent);
    }
    data->z-=ctx->delta;
    parent->pos.x += data->x;
    parent->pos.y += data->y;
}

void game_update (GameObject* self, GameTree* ctx) {
    new_rect_time-=ctx->delta;
    if (new_rect_time > 0) {
        return;
    }
    new_rect_time = RECT_INTERVAL;

    GameObject* rect = make_gameRect((Vector2){400-5,240-5}, (Vector2){10,10}, RED);

    GameObject* script = make_gameObject(NULL, rect_update, NULL, NULL, sizeof(Vector3));
    Vector3* data = script->c_extra;

    float speed = rand_float();
    data->x = (rand_float()*2-1)*10;
    data->y = (10-fabs(data->x)) * (rand_int(0, 1)*2 - 1);
    data->x *= speed;
    data->y *= speed;

    data->z = 3; // time until deletion

    reg_obj(rect, script, NULL);

    reg_obj(self, rect, NULL);
}

int main(void) {
    GameTree* tree = get_tree();

    tree->width = 800;
    tree->height = 480;
    tree->window_name = "Jajaa";

    tree->background_color = BLACK;

    GameObject* root = make_gameObject(NULL, game_update, NULL, NULL, 0);

    load_scene(root);

    run_game_loop();

    return 0;
}
