/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** draw_font_parallax.c
*/

#include "../include/my_rpg.h"

int draw_red_sky(game_object_t *obj)
{
    obj->clock = sfClock_create();
    obj->seconds = 0;
    obj->texture = sfTexture_createFromFile
    ("./texture/parallax_départ/1/sky1_1.png", NULL);
    if (!obj->texture) {
        write(2, "The sky1 is missing !\n", 28);
        return (84);
    }
    obj->sprite = sfSprite_create();
    sfSprite_setTexture(obj->sprite, obj->texture, sfTrue);
    return (0);
}

int draw_wood_red_1_1(game_object_t *obj)
{
    obj->clock = sfClock_create();
    obj->seconds = 0;
    obj->texture = sfTexture_createFromFile
    ("./texture/parallax_départ/2/wood_red1_1.png", NULL);
    if (!obj->texture) {
        write(2, "The sky1 is missing !\n", 28);
        return (84);
    }
    obj->sprite = sfSprite_create();
    sfSprite_setTexture(obj->sprite, obj->texture, sfTrue);
    set_wood_red_1_1(obj);
    return (0);
}

int draw_wood_red_1_2(game_object_t *obj)
{
    obj->clock = sfClock_create();
    obj->seconds = 0;
    obj->texture = sfTexture_createFromFile
    ("./texture/parallax_départ/2/wood_red1_2.png", NULL);
    if (!obj->texture) {
        write(2, "The sky1 is missing !\n", 28);
        return (84);
    }
    obj->sprite = sfSprite_create();
    sfSprite_setTexture(obj->sprite, obj->texture, sfTrue);
    set_wood_red_1_2(obj);
    return (0);
}