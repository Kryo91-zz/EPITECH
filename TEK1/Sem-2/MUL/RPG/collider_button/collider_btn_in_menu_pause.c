/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** collider_btn_in_menu_pause.c
*/

#include "../include/my_rpg.h"

void hitbox_button_reprendre_in_menu_pause(glb_t *global)
{
    int x = sfSprite_getGlobalBounds(global->reprendre.sprite).width;
    int y = sfSprite_getGlobalBounds(global->reprendre.sprite).height;
    global->cursor.mouseposition =
    sfMouse_getPositionRenderWindow(global->wind.window);
    global->cursor.mouseposition.x -= 37.5;
    global->cursor.mouseposition.y -= 37.5;
    if (global->cursor.mouseposition.x < global->reprendre.pos.x + x && \
    global->cursor.mouseposition.x > global->reprendre.pos.x && \
    global->cursor.mouseposition.y > global->reprendre.pos.y && \
    global->cursor.mouseposition.y < global->reprendre.pos.y + y) {
        anim_button_reprendre_in_pause_menu(global);
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            global->bool_menu_pause = 0;
        }
    } else
        sfSprite_setTextureRect(global->reprendre.sprite, rect(0, 0, 95, 39));
}

void hitbox_button_quiter_in_menu_pause(glb_t *global)
{
    int x = sfSprite_getGlobalBounds(global->quitter_MP.sprite).width;
    int y = sfSprite_getGlobalBounds(global->quitter_MP.sprite).height;
    global->cursor.mouseposition =
    sfMouse_getPositionRenderWindow(global->wind.window);
    global->cursor.mouseposition.x -= 37.5;
    global->cursor.mouseposition.y -= 37.5;
    if (global->cursor.mouseposition.x < global->quitter_MP.pos.x + x &&
    global->cursor.mouseposition.x > global->quitter_MP.pos.x &&
    global->cursor.mouseposition.y > global->quitter_MP.pos.y &&
    global->cursor.mouseposition.y < global->quitter_MP.pos.y + y) {
        anim_button_quitter_in_pause_menu(global);
        if (sfMouse_isButtonPressed(sfMouseLeft))
            sfRenderWindow_close(global->wind.window);
    } else
        sfSprite_setTextureRect(global->quitter_MP.sprite, rect(0, 0, 95, 39));
}

void hitbox_button_sauvegarder_in_menu_pause(glb_t *global)
{
    int x = sfSprite_getGlobalBounds(global->sauvegarder.sprite).width;
    int y = sfSprite_getGlobalBounds(global->sauvegarder.sprite).height;
    global->cursor.mouseposition =
    sfMouse_getPositionRenderWindow(global->wind.window);
    global->cursor.mouseposition.x -= 37.5;
    global->cursor.mouseposition.y -= 37.5;
    if (global->cursor.mouseposition.x < global->sauvegarder.pos.x + x &&
    global->cursor.mouseposition.x > global->sauvegarder.pos.x &&
    global->cursor.mouseposition.y > global->sauvegarder.pos.y &&
    global->cursor.mouseposition.y < global->sauvegarder.pos.y + y) {
        anim_button_sauvegarder_in_pause_menu(global);
        if (sfMouse_isButtonPressed(sfMouseLeft))
            save_game(global);
    } else
        sfSprite_setTextureRect(global->sauvegarder.sprite, rect(0, 0, 95, 39));
}

void hitbox_button_option_in_menu_pause(glb_t *global)
{
    int x = sfSprite_getGlobalBounds(global->option_MP.sprite).width;
    int y = sfSprite_getGlobalBounds(global->option_MP.sprite).height;
    global->cursor.mouseposition =
    sfMouse_getPositionRenderWindow(global->wind.window);
    global->cursor.mouseposition.x -= 37.5;
    global->cursor.mouseposition.y -= 37.5;
    if (global->cursor.mouseposition.x < global->option_MP.pos.x + x &&
    global->cursor.mouseposition.x > global->option_MP.pos.x &&
    global->cursor.mouseposition.y > global->option_MP.pos.y &&
    global->cursor.mouseposition.y < global->option_MP.pos.y + y) {
        anim_button_option_in_pause_menu(global);
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            global->bool_menu_option = 1;
            global->bool_main_menu = 1;
        }
    } else
        sfSprite_setTextureRect(global->option_MP.sprite, rect(0, 0, 95, 39));
}

void hitbox_button_menu_prin_in_menu_pause(glb_t *global)
{
    int x = sfSprite_getGlobalBounds(global->menu_principal.sprite).width;
    int y = sfSprite_getGlobalBounds(global->menu_principal.sprite).height;
    global->cursor.mouseposition =
    sfMouse_getPositionRenderWindow(global->wind.window);
    global->cursor.mouseposition.x -= 37.5;
    global->cursor.mouseposition.y -= 37.5;
    if (global->cursor.mouseposition.x < global->menu_principal.pos.x + x &&
    global->cursor.mouseposition.x > global->menu_principal.pos.x &&
    global->cursor.mouseposition.y > global->menu_principal.pos.y &&
    global->cursor.mouseposition.y < global->menu_principal.pos.y + y) {
        anim_button_menu_prin_in_pause_menu(global);
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            global->bool_main_menu = 1;
        }
    } else
        sfSprite_setTextureRect(global->menu_principal.sprite,
        rect(0, 0, 95, 39));
}