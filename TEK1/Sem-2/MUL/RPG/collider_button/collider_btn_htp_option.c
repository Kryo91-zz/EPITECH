/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** collider_btn_htp_option.c
*/

#include "../include/my_rpg.h"

void hitbox_button_retour_main_menu(glb_t *global)
{
    int x = sfSprite_getGlobalBounds(global->pause.sprite).width;
    int y = sfSprite_getGlobalBounds(global->retour_htp.sprite).height;
    global->cursor.mouseposition =
    sfMouse_getPositionRenderWindow(global->wind.window);
    global->cursor.mouseposition.x -= 37.5;
    global->cursor.mouseposition.y -= 37.5;
    if (global->cursor.mouseposition.x < global->retour_htp.pos.x + x &&
    global->cursor.mouseposition.x > global->retour_htp.pos.x &&
    global->cursor.mouseposition.y > global->retour_htp.pos.y &&
    global->cursor.mouseposition.y < global->retour_htp.pos.y + y) {
        anim_button_retour_main_menu(global);
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            global->bool_menu_htp = 0;
            global->bool_main_menu = 1;
        }
    } else
        sfSprite_setTextureRect(global->retour_htp.sprite, rect(0, 0, 95, 39));
}

void hitbox_button_pause_in_game(glb_t *global)
{
    int x = sfSprite_getGlobalBounds(global->pause.sprite).width;
    int y = sfSprite_getGlobalBounds(global->pause.sprite).height;
    global->cursor.mouseposition =
    sfMouse_getPositionRenderWindow(global->wind.window);
    global->cursor.mouseposition.x -= 37.5;
    global->cursor.mouseposition.y -= 37.5;
    if (global->cursor.mouseposition.x < global->pause.pos.x + x &&
    global->cursor.mouseposition.x > global->pause.pos.x &&
    global->cursor.mouseposition.y > global->pause.pos.y &&
    global->cursor.mouseposition.y < global->pause.pos.y + y) {
        anim_button_pause_in_game(global);
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            global->bool_menu_pause = 1;
        }
    } else
        sfSprite_setTextureRect(global->pause.sprite, rect(0, 0, 95, 39));
}

void hitbox_button_retour_menu_option(glb_t *global)
{
    int x = sfSprite_getGlobalBounds(global->retour_MO.sprite).width;
    int y = sfSprite_getGlobalBounds(global->retour_MO.sprite).height;
    global->cursor.mouseposition =
    sfMouse_getPositionRenderWindow(global->wind.window);
    global->cursor.mouseposition.x -= 37.5;
    global->cursor.mouseposition.y -= 37.5;
    if (global->cursor.mouseposition.x < global->retour_MO.pos.x + x && \
    global->cursor.mouseposition.x > global->retour_MO.pos.x && \
    global->cursor.mouseposition.y > global->retour_MO.pos.y && \
    global->cursor.mouseposition.y < global->retour_MO.pos.y + y) {
        anim_button_retour_menu_option(global);
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            global->bool_menu_option = 0;
            global->bool_main_menu = 1;
        }
    } else
        sfSprite_setTextureRect(global->retour_MO.sprite, rect(0, 0, 95, 39));
}

void hitbox_btn_retour_menu_defeat(glb_t *global)
{
    int x = sfSprite_getGlobalBounds(global->retour_defeat.sprite).width;
    int y = sfSprite_getGlobalBounds(global->retour_defeat.sprite).height;
    global->cursor.mouseposition =
    sfMouse_getPositionRenderWindow(global->wind.window);
    global->cursor.mouseposition.x -= 37.5;
    global->cursor.mouseposition.y -= 37.5;
    if (global->cursor.mouseposition.x < global->retour_defeat.pos.x + x && \
    global->cursor.mouseposition.x > global->retour_defeat.pos.x && \
    global->cursor.mouseposition.y > global->retour_defeat.pos.y && \
    global->cursor.mouseposition.y < global->retour_defeat.pos.y + y) {
        anim_retour_defeat(global);
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            sfRenderWindow_close(global->wind.window);
        }
    } else
        sfSprite_setTextureRect(global->retour_defeat.sprite,
        rect(0, 0, 95, 39));
}