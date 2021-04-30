/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** hud_sort_foudre.c
*/

#include "../include/my_rpg.h"

static void move_rect(glb_t *global, int offset, int max)
{
    global->hud_sort_foudre.rect.left =
    (global->hud_sort_foudre.rect.left + offset) % max;
}

int hud_sort_foudre_create(glb_t *global)
{
    global->hud_sort_foudre.size.x = 1.0f;
    global->hud_sort_foudre.size.y = 1.0f;
    global->hud_sort_foudre.position.x = 110;
    global->hud_sort_foudre.position.y = 920;
    global->hud_sort_foudre.rect.top = 0;
    global->hud_sort_foudre.rect.left = 0;
    global->hud_sort_foudre.rect.width = 100;
    global->hud_sort_foudre.rect.height = 100;
    global->hud_sort_foudre.texture = sfTexture_createFromFile
    ("./texture/HUD/hudsortfoudre.png", NULL);
    if (!global->hud_sort_foudre.texture) {
        write (2, "The texture is missing!\n", 26);
        return (84);
    }
    global->hud_sort_foudre.sprite = sfSprite_create();
    texture_hud_sort_foudre(global);
    return (0);
}

void texture_hud_sort_foudre(glb_t *global)
{
    sfSprite_setPosition(global->hud_sort_foudre.sprite,
    global->hud_sort_foudre.position);
    sfSprite_setScale(global->hud_sort_foudre.sprite,
    global->hud_sort_foudre.size);
    sfSprite_setTexture(global->hud_sort_foudre.sprite,
    global->hud_sort_foudre.texture, sfTrue);
    sfSprite_setTextureRect(global->hud_sort_foudre.sprite,
    global->hud_sort_foudre.rect);
}

void anim_hud_sort_foudre(glb_t *global)
{
    move_rect(global, 100, 200);
    sfSprite_setTextureRect(global->hud_sort_foudre.sprite,
    global->hud_sort_foudre.rect);
}