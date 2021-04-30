/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** collider_btn_main_menu.c
*/

#include "../include/my_rpg.h"

void hitbox_button_play_main_menu(glb_t *global)
{
    int x = sfSprite_getGlobalBounds(global->play_MM.sprite).width;
    int y = sfSprite_getGlobalBounds(global->play_MM.sprite).height;
    global->cursor.mouseposition =
    sfMouse_getPositionRenderWindow(global->wind.window);
    global->cursor.mouseposition.x -= 37.5;
    global->cursor.mouseposition.y -= 37.5;
    if (global->cursor.mouseposition.x < global->play_MM.pos.x + x && \
    global->cursor.mouseposition.x > global->play_MM.pos.x && \
    global->cursor.mouseposition.y > global->play_MM.pos.y && \
    global->cursor.mouseposition.y < global->play_MM.pos.y + y) {
        anim_button_play_main_menu(global);
        if (sfMouse_isButtonPressed(sfMouseLeft))
            global->bool_main_menu = 0;
    } else
        sfSprite_setTextureRect(global->play_MM.sprite, rect(0, 0, 95, 39));
}

void hitbox_button_quit_main_menu(glb_t *global)
{
    int x = sfSprite_getGlobalBounds(global->quit_MM.sprite).width;
    int y = sfSprite_getGlobalBounds(global->quit_MM.sprite).height;
    global->cursor.mouseposition =
    sfMouse_getPositionRenderWindow(global->wind.window);
    global->cursor.mouseposition.x -= 37.5;
    global->cursor.mouseposition.y -= 37.5;
    if (global->cursor.mouseposition.x < global->quit_MM.pos.x + x && \
    global->cursor.mouseposition.x > global->quit_MM.pos.x && \
    global->cursor.mouseposition.y > global->quit_MM.pos.y && \
    global->cursor.mouseposition.y < global->quit_MM.pos.y + y) {
        anim_button_quit_main_menu(global);
        if (sfMouse_isButtonPressed(sfMouseLeft))
            sfRenderWindow_close(global->wind.window);
    } else
        sfSprite_setTextureRect(global->quit_MM.sprite, rect(0, 0, 95, 39));
}

void hitbox_button_option_main_menu(glb_t *global)
{
    int x = sfSprite_getGlobalBounds(global->option_MM.sprite).width;
    int y = sfSprite_getGlobalBounds(global->option_MM.sprite).height;
    global->cursor.mouseposition =
    sfMouse_getPositionRenderWindow(global->wind.window);
    global->cursor.mouseposition.x -= 37.5;
    global->cursor.mouseposition.y -= 37.5;
    if (global->cursor.mouseposition.x < global->option_MM.pos.x + x && \
    global->cursor.mouseposition.x > global->option_MM.pos.x && \
    global->cursor.mouseposition.y > global->option_MM.pos.y && \
    global->cursor.mouseposition.y < global->option_MM.pos.y + y) {
        anim_button_option_main_menu(global);
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            global->bool_menu_option = 1;
        }
    } else
        sfSprite_setTextureRect(global->option_MM.sprite, rect(0, 0, 95, 39));
}

void hitbox_button_aide_main_menu(glb_t *global)
{
    int x = sfSprite_getGlobalBounds(global->aide_MM.sprite).width;
    int y = sfSprite_getGlobalBounds(global->aide_MM.sprite).height;
    global->cursor.mouseposition =
    sfMouse_getPositionRenderWindow(global->wind.window);
    global->cursor.mouseposition.x -= 37.5;
    global->cursor.mouseposition.y -= 37.5;
    if (global->cursor.mouseposition.x < global->aide_MM.pos.x + x && \
    global->cursor.mouseposition.x > global->aide_MM.pos.x && \
    global->cursor.mouseposition.y > global->aide_MM.pos.y && \
    global->cursor.mouseposition.y < global->aide_MM.pos.y + y) {
        anim_button_aide_main_menu(global);
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            global->bool_menu_htp = 1;
        }
    } else
        sfSprite_setTextureRect(global->aide_MM.sprite, rect(0, 0, 95, 39));
}

void hitbox_button_charger_main_menu(glb_t *global)
{
    int x = sfSprite_getGlobalBounds(global->charger_MM.sprite).width;
    int y = sfSprite_getGlobalBounds(global->charger_MM.sprite).height;
    global->cursor.mouseposition =
    sfMouse_getPositionRenderWindow(global->wind.window);
    global->cursor.mouseposition.x -= 37.5;
    global->cursor.mouseposition.y -= 37.5;
    if (global->cursor.mouseposition.x < global->charger_MM.pos.x + x && \
    global->cursor.mouseposition.x > global->charger_MM.pos.x && \
    global->cursor.mouseposition.y > global->charger_MM.pos.y && \
    global->cursor.mouseposition.y < global->charger_MM.pos.y + y) {
        anim_button_charger_main_menu(global);
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            global->bool_main_menu = 0;
            load_game(global);
        }
    } else
        sfSprite_setTextureRect(global->charger_MM.sprite, rect(0, 0, 95, 39));
}