/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** collider_btn_option.c
*/

#include "../include/my_rpg.h"

void hitbox_btn_moins(glb_t *global)
{
    int x = sfSprite_getGlobalBounds(global->moins.sprite).width;
    int y = sfSprite_getGlobalBounds(global->moins.sprite).height;
    global->cursor.mouseposition =
    sfMouse_getPositionRenderWindow(global->wind.window);
    global->cursor.mouseposition.x -= 37.5;
    global->cursor.mouseposition.y -= 37.5;
    if (global->cursor.mouseposition.x < global->moins.pos.x + x &&
    global->cursor.mouseposition.x > global->moins.pos.x &&
    global->cursor.mouseposition.y > global->moins.pos.y &&
    global->cursor.mouseposition.y < global->moins.pos.y + y) {
        anim_btn_moins(global);
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            sfMusic_setVolume(global->music_menu.music, (5));
        }
    } else
        sfSprite_setTextureRect(global->moins.sprite, rect(0, 0, 55, 53));
}

void hitbox_btn_plus(glb_t *global)
{
    int x = sfSprite_getGlobalBounds(global->plus.sprite).width;
    int y = sfSprite_getGlobalBounds(global->plus.sprite).height;
    global->cursor.mouseposition =
    sfMouse_getPositionRenderWindow(global->wind.window);
    global->cursor.mouseposition.x -= 37.5;
    global->cursor.mouseposition.y -= 37.5;
    if (global->cursor.mouseposition.x < global->plus.pos.x + x &&
    global->cursor.mouseposition.x > global->plus.pos.x &&
    global->cursor.mouseposition.y > global->plus.pos.y &&
    global->cursor.mouseposition.y < global->plus.pos.y + y) {
        anim_btn_plus(global);
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            sfMusic_setVolume(global->music_menu.music, (80));
        }
    } else
        sfSprite_setTextureRect(global->plus.sprite, rect(0, 0, 56, 56));
}