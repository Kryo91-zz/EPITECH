/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** loop_and_tools.c
*/

#include "../include/my_rpg.h"

void init_particule3(const particle_environment_t *particle_environment, \
particle_t *particule, const sfVector2f pos)
{
    float angle = ((float)rand()/(float)(RAND_MAX)) * \
    (particle_environment->angle_max - particle_environment->angle_min) \
    + particle_environment->angle_min;
    particule->vel.x = cos(angle) * ((float)rand()/(float)(RAND_MAX)) * (1.0f);
    particule->vel.y = sin(angle) * ((float)rand()/(float)(RAND_MAX)) * (1.0f);
    particule->pos = pos;
    particule->color.a = rand() % 255;
    particule->color.r = rand() % 1;
    particule->color.g = rand() % 1;
    particule->color.b = rand() % 1;
    particule->living = true;
    particule->radius = 15;
}

void add_particle3(const particle_environment_t *particle_environment, \
particle_t *particule, const size_t particle_num, const sfVector2f pos)
{
    int n = particle_num;

    for (unsigned int i = 0; i < 100 && n > 0; i += 1) {
        if (particule[i].living == false) {
            init_particule3(particle_environment, &particule[i], pos);
            n -= 1;
        }
    }
}

void init_particule2(const particle_environment_t *particle_environment, \
particle_t *particule, const sfVector2f pos)
{
    float angle = ((float)rand()/(float)(RAND_MAX)) * \
    (particle_environment->angle_max - particle_environment->angle_min) \
    + particle_environment->angle_min;
    particule->vel.x = cos(angle) * ((float)rand()/(float)(RAND_MAX)) * (1.0f);
    particule->vel.y = sin(angle) * ((float)rand()/(float)(RAND_MAX)) * (1.0f);
    particule->pos = pos;
    particule->color.a = rand() % 255;
    particule->color.r = rand() % 1;
    particule->color.g = rand() % 1;
    particule->color.b = rand() % 255;
    particule->living = true;
    particule->radius = 15;
}

void add_particle2(const particle_environment_t *particle_environment, \
particle_t *particule, const size_t particle_num, const sfVector2f pos)
{
    int n = particle_num;

    for (unsigned int i = 0; i < 100 && n > 0; i += 1) {
        if (particule[i].living == false) {
            init_particule2(particle_environment, &particule[i], pos);
            n -= 1;
        }
    }
}