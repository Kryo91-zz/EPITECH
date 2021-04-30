/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** hud_sort_epee.c
*/

#include "../include/my_rpg.h"

static void move_rect(glb_t *global, int offset, int max)
{
    global->hud_sort_epee.rect.left =
    (global->hud_sort_epee.rect.left + offset) % max;
}

int hud_sort_epee_create(glb_t *global)
{
    global->hud_sort_epee.size.x = 1.0f;
    global->hud_sort_epee.size.y = 1.0f;
    global->hud_sort_epee.position.x = 200;
    global->hud_sort_epee.position.y = 920;
    global->hud_sort_epee.rect.top = 0;
    global->hud_sort_epee.rect.left = 0;
    global->hud_sort_epee.rect.width = 100;
    global->hud_sort_epee.rect.height = 100;
    global->hud_sort_epee.texture = sfTexture_createFromFile
    ("./texture/HUD/hudsortepee.png", NULL);
    if (!global->hud_sort_epee.texture) {
        write (2, "The texture is missing!\n", 26);
        return (84);
    }
    global->hud_sort_epee.sprite = sfSprite_create();
    texture_hud_sort_epee(global);
    return (0);
}

void texture_hud_sort_epee(glb_t *global)
{
    sfSprite_setPosition(global->hud_sort_epee.sprite,
    global->hud_sort_epee.position);
    sfSprite_setScale(global->hud_sort_epee.sprite,
    global->hud_sort_epee.size);
    sfSprite_setTexture(global->hud_sort_epee.sprite,
    global->hud_sort_epee.texture, sfTrue);
    sfSprite_setTextureRect(global->hud_sort_epee.sprite,
    global->hud_sort_epee.rect);
}

void anim_hud_sort_epee(glb_t *global)
{
    move_rect(global, 100, 200);
    sfSprite_setTextureRect(global->hud_sort_epee.sprite,
    global->hud_sort_epee.rect);
}