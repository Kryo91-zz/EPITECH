/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** loop_and_tools.c
*/

#include "../include/my_rpg.h"

void init_particle_environment(particle_environment_t *particle_environment, \
const sfVector2f angle, const sfVector2f gravity, const sfUint8 alpha)
{
    sfCircleShape *particle = sfCircleShape_create();
    sfClock *parti_clock = sfClock_create();
    particle_environment->angle_min = angle.x;
    particle_environment->angle_max = angle.y;
    particle_environment->gravity = gravity;
    particle_environment->alpha = alpha;
    particle_environment->circle_shape = particle;
    particle_environment->clock = parti_clock;
    particle_environment->speed = (0.6f);
}

void manage_event_window(sfRenderWindow *window, sfKeyCode *key)
{
    sfEvent event;

    *key = sfKeyUnknown;
    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
        else if (event.type == sfEvtKeyPressed)
            *key = event.key.code;
    }
}

void init_particule(const particle_environment_t *particle_environment, \
particle_t *particule, const sfVector2f pos)
{
    float angle = ((float)rand()/(float)(RAND_MAX)) * \
    (particle_environment->angle_max - particle_environment->angle_min) \
    + particle_environment->angle_min;
    particule->vel.x = cos(angle) * ((float)rand()/(float)(RAND_MAX)) * (1.0f);
    particule->vel.y = sin(angle) * ((float)rand()/(float)(RAND_MAX)) * (1.0f);
    particule->pos = pos;
    particule->color.a = rand() % 255;
    particule->color.r = rand() % 255;
    particule->color.g = rand() % 1;
    particule->color.b = rand() % 1;
    particule->living = true;
    particule->radius = 15;
}

void add_particle(const particle_environment_t *particle_environment, \
particle_t *particule, const size_t particle_num, const sfVector2f pos)
{
    int n = particle_num;

    for (unsigned int i = 0; i < 100 && n > 0; i += 1) {
        if (particule[i].living == false) {
            init_particule(particle_environment, &particule[i], pos);
            n -= 1;
        }
    }
}

void manage_key_window(window_t *screen, const sfKeyCode *key, glb_t *global)
{
    sfVector2i pos;

    if (*key == sfKeyLShift && global->mana >= 5 && global->exp >= 2) {
        global->mana -= 5;
        pos = sfMouse_getPositionRenderWindow(screen->window);
        add_particle(screen->particle_environment, global->wind.particle, \
        100, (sfVector2f){pos.x, pos.y});
    } else if (*key == sfKeyE && global->mana >= 7 && global->exp >= 3) {
        global->mana -= 7;
        pos = sfMouse_getPositionRenderWindow(screen->window);
        add_particle2(screen->particle_environment, screen->particle, \
        100, (sfVector2f){pos.x, pos.y});
    } else if (*key == sfKeyA && global->mana >= 10 && global->exp >= 4) {
        global->mana -= 10;
        pos = sfMouse_getPositionRenderWindow(screen->window);
        add_particle3(screen->particle_environment, screen->particle, \
        100, (sfVector2f){pos.x, pos.y});
    }
}