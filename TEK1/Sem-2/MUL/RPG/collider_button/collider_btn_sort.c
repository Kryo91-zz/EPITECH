/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** collider_btn_sort.c
*/

#include "../include/my_rpg.h"

void hitbox_button_sort_feu(glb_t *global)
{
    int x = sfSprite_getGlobalBounds(global->hud_sort_feu.sprite).width;
    int y = sfSprite_getGlobalBounds(global->hud_sort_feu.sprite).height;
    global->cursor.mouseposition =
    sfMouse_getPositionRenderWindow(global->wind.window);
    global->cursor.mouseposition.x -= 37.5;
    global->cursor.mouseposition.y -= 37.5;
    if (global->cursor.mouseposition.x < global->hud_sort_feu.position.x + x &&
    global->cursor.mouseposition.x > global->hud_sort_feu.position.x &&
    global->cursor.mouseposition.y > global->hud_sort_feu.position.y &&
    global->cursor.mouseposition.y < global->hud_sort_feu.position.y + y) {
        anim_hud_sort_feu(global);
    }
}

void hitbox_button_sort_foudre(glb_t *global)
{
    int x = sfSprite_getGlobalBounds(global->hud_sort_foudre.sprite).width;
    int y = sfSprite_getGlobalBounds(global->hud_sort_foudre.sprite).height;
    global->cursor.mouseposition =
    sfMouse_getPositionRenderWindow(global->wind.window);
    global->cursor.mouseposition.x -= 37.5;
    global->cursor.mouseposition.y -= 37.5;
    if (global->cursor.mouseposition.x <
    global->hud_sort_foudre.position.x + x &&
    global->cursor.mouseposition.x > global->hud_sort_foudre.position.x &&
    global->cursor.mouseposition.y > global->hud_sort_foudre.position.y &&
    global->cursor.mouseposition.y < global->hud_sort_foudre.position.y + y) {
        anim_hud_sort_foudre(global);
    }
}

void hitbox_button_sort_epee(glb_t *global)
{
    int x = sfSprite_getGlobalBounds(global->hud_sort_epee.sprite).width;
    int y = sfSprite_getGlobalBounds(global->hud_sort_epee.sprite).height;
    global->cursor.mouseposition =
    sfMouse_getPositionRenderWindow(global->wind.window);
    global->cursor.mouseposition.x -= 37.5;
    global->cursor.mouseposition.y -= 37.5;
    if (global->cursor.mouseposition.x <
    global->hud_sort_epee.position.x + x &&
    global->cursor.mouseposition.x > global->hud_sort_epee.position.x &&
    global->cursor.mouseposition.y > global->hud_sort_epee.position.y &&
    global->cursor.mouseposition.y < global->hud_sort_epee.position.y + y) {
        anim_hud_sort_epee(global);
    }
}