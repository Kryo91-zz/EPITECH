/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** draw_demon.c
*/

#include "../include/my_rpg.h"

static void move_rect(glb_t *global, int offset, int max)
{
    global->demon1.rect.left = (global->demon1.rect.left + offset) % max;
}

int demon1_create(glb_t *global)
{
    global->demon1.clock = sfClock_create();
    global->demon1.seconds = 0;
    global->demon1.size.x = 2.5f;
    global->demon1.size.y = 2.5f;
    global->demon1.position.x = 1030;
    global->demon1.position.y = 1450;
    global->demon1.rect.top = 0;
    global->demon1.rect.left = 0;
    global->demon1.rect.width = 63;
    global->demon1.rect.height = 44;
    global->demon1.texture = sfTexture_createFromFile
    ("./texture/mob/demonface.png", NULL);
    if (!global->demon1.texture) {
        write (2, "The texture is missing!\n", 26);
        return (84);
    }
    global->demon1.sprite = sfSprite_create();
    texture_demon1(global);
    global->demon2.clock = sfClock_create();
    global->demon2.seconds = 0;
    global->demon2.size.x = 2.5f;
    global->demon2.size.y = 2.5f;
    global->demon2.position.x = 1570;
    global->demon2.position.y = 3250;
    global->demon2.rect.top = 0;
    global->demon2.rect.left = 0;
    global->demon2.rect.width = 63;
    global->demon2.rect.height = 44;
    global->demon2.texture = sfTexture_createFromFile
    ("./texture/mob/demonface.png", NULL);
    if (!global->demon1.texture) {
        write (2, "The texture is missing!\n", 26);
        return (84);
    }
    global->demon2.sprite = sfSprite_create();
    texture_demon2(global);
    global->demon3.clock = sfClock_create();
    global->demon3.seconds = 0;
    global->demon3.size.x = 2.5f;
    global->demon3.size.y = 2.5f;
    global->demon3.position.x = 6400;
    global->demon3.position.y = 3150;
    global->demon3.rect.top = 0;
    global->demon3.rect.left = 0;
    global->demon3.rect.width = 63;
    global->demon3.rect.height = 44;
    global->demon3.texture = sfTexture_createFromFile
    ("./texture/mob/demonface.png", NULL);
    if (!global->demon1.texture) {
        write (2, "The texture is missing!\n", 26);
        return (84);
    }
    global->demon3.sprite = sfSprite_create();
    texture_demon3(global);
    return (0);

}

void anim_demon1(glb_t *global)
{
    if (global->demon1.seconds > 0.10) {
        sfSprite_setTextureRect(global->demon1.sprite, global->demon1.rect);
        move_rect(global, 63, 252);
        sfClock_restart(global->demon1.clock);
    }
}

void texture_demon1(glb_t *global)
{
    sfSprite_setPosition(global->demon1.sprite, global->demon1.position);
    sfSprite_setScale(global->demon1.sprite, global->demon1.size);
    sfSprite_setTexture(global->demon1.sprite, global->demon1.texture, sfTrue);
    sfSprite_setTextureRect(global->demon1.sprite, global->demon1.rect);
}

void time_clock_demon1(glb_t *global)
{
    global->demon1.time = sfClock_getElapsedTime(global->demon1.clock);
    global->demon1.seconds = global->demon1.time.microseconds / 1000000.0;
    anim_demon1(global);
}
