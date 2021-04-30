/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** hud_sort_feu.c
*/

#include "../include/my_rpg.h"

static void move_rect(glb_t *global, int offset, int max)
{
    global->hud_sort_feu.rect.left =
    (global->hud_sort_feu.rect.left + offset) % max;
}

int hud_sort_feu_create(glb_t *global)
{
    global->hud_sort_feu.size.x = 1.0f;
    global->hud_sort_feu.size.y = 1.0f;
    global->hud_sort_feu.position.x = 20;
    global->hud_sort_feu.position.y = 920;
    global->hud_sort_feu.rect.top = 0;
    global->hud_sort_feu.rect.left = 0;
    global->hud_sort_feu.rect.width = 100;
    global->hud_sort_feu.rect.height = 100;
    global->hud_sort_feu.texture = sfTexture_createFromFile
    ("./texture/HUD/hudsortfeu.png", NULL);
    if (!global->hud_sort_feu.texture) {
        write (2, "The texture is missing!\n", 26);
        return (84);
    }
    global->hud_sort_feu.sprite = sfSprite_create();
    texture_hud_sort_feu(global);
    return (0);
}

void texture_hud_sort_feu(glb_t *global)
{
    sfSprite_setPosition(global->hud_sort_feu.sprite,
    global->hud_sort_feu.position);
    sfSprite_setScale(global->hud_sort_feu.sprite,
    global->hud_sort_feu.size);
    sfSprite_setTexture(global->hud_sort_feu.sprite,
    global->hud_sort_feu.texture, sfTrue);
    sfSprite_setTextureRect(global->hud_sort_feu.sprite,
    global->hud_sort_feu.rect);
}

void anim_hud_sort_feu(glb_t *global)
{
    move_rect(global, 100, 200);
    sfSprite_setTextureRect(global->hud_sort_feu.sprite,
    global->hud_sort_feu.rect);
}