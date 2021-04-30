/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** loop_and_tools3.c
*/

#include "../include/my_rpg.h"

void reset_to_default_view(sfRenderWindow *window)
{
    const sfView *view = sfRenderWindow_getDefaultView(window);

    sfRenderWindow_setView(window, view);
}

cam_t *camera_create(void)
{
    cam_t *camera = malloc(sizeof(cam_t));

    if (camera == NULL)
        return (NULL);
    camera->rect = (sfFloatRect) {0.0f, 0.0f, 1920.0f, 1080.0f};
    camera->pos = (sfVector2f) {0.0f, 0.0f};
    camera->zoom = 0.8f;
    camera->view = sfView_createFromRect(camera->rect);
    sfView_setCenter(camera->view, camera->pos);
    sfView_zoom(camera->view, camera->zoom);
    return (camera);
}

void appel_of_bool(glb_t *global)
{
    global->map = malloc(sizeof(map_t) * 2);
    global->obj = malloc(sizeof(game_object_t *) * 7);
    global->wind.particle = malloc(sizeof(particle_t) * 101);
    global->wind.particle_environment = malloc(sizeof(particle_environment_t));
    global->cam = camera_create();
    for (int i = 0; i < 7; i++)
        global->obj[i] = malloc(sizeof(game_object_t));
    global->bool_main_menu = 1;
    global->bool_menu_htp = 0;
    global->bool_menu_option = 0;
    global->bool_menu_pause = 0;
    global->defeat = 0;
    global->health = 100;
    global->healthmax = 100;
    global->minhealth = 0;
    global->mana = 75;
    global->manamax = 75;
    global->exp = 1;
    global->expmax = 5;
    init_particle_environment(global->wind.particle_environment, \
    (sfVector2f){PARICULE_ANGLE_MIN, PARICULE_ANGLE_MAX}, \
    (sfVector2f){(1.0f * 0), (1.0f * 0)}, 1);
    global->chara = init_chara();
}