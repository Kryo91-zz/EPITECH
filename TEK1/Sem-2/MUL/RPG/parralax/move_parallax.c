/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** move_parallax.c
*/

#include "../include/my_rpg.h"

void set_wood_red_1_1(game_object_t *obj)
{
    obj->position.x = 0;
    obj->position.y = 0;

    sfSprite_setPosition(obj->sprite, obj->position);
}

void set_wood_red_1_2(game_object_t *obj)
{
    obj->position.x = 1536;
    obj->position.y = 0;

    sfSprite_setPosition(obj->sprite, obj->position);
}

void move_wood_red_1_1(game_object_t *obj)
{
    obj->time = sfClock_getElapsedTime(obj->clock);
    obj->seconds = obj->time.microseconds / 1000000.0;
    if (obj->seconds > 0.05) {
        obj->position.x -= 10;
        sfSprite_setPosition(obj->sprite, obj->position);
        sfClock_restart(obj->clock);
    }
    if (obj->position.x <= -1526) {
        obj->position.x = 1526;
        sfSprite_setPosition(obj->sprite, obj->position);
    }
}

void move_wood_red_1_2(game_object_t *obj)
{
    obj->time = sfClock_getElapsedTime(obj->clock);
    obj->seconds = obj->time.microseconds / 1000000.0;
    if (obj->position.x <= -1526) {
        obj->position.x = 1526;
        sfSprite_setPosition(obj->sprite, obj->position);
    }
    if (obj->seconds > 0.05) {
        obj->position.x -= 2;
        sfSprite_setPosition(obj->sprite, obj->position);
        sfClock_restart(obj->clock);
    }
}