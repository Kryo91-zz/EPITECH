/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** destroy_all.c
*/

#include "../include/my_rpg.h"

void destroy_1(glb_t *global)
{
    sfSprite_destroy(global->cursor.sprite);
    sfTexture_destroy(global->cursor.texture);
    sfSprite_destroy(global->test.sprite);
    sfTexture_destroy(global->test.texture);
    sfSprite_destroy(global->pause.sprite);
    sfTexture_destroy(global->pause.texture);
    sfSprite_destroy(global->hud_sort_feu.sprite);
    sfTexture_destroy(global->hud_sort_feu.texture);
    sfSprite_destroy(global->hud_sort_foudre.sprite);
    sfTexture_destroy(global->hud_sort_foudre.texture);
    sfSprite_destroy(global->hud_sort_epee.sprite);
    sfTexture_destroy(global->hud_sort_epee.texture);
    sfSprite_destroy(global->demon1.sprite);
    sfTexture_destroy(global->demon1.texture);
    sfMusic_destroy(global->music_menu.music);
    sfSprite_destroy(global->chara->sprite);
    sfTexture_destroy(global->chara->texture);
}