/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** loop_for_all_menu.c
*/

#include "../include/my_rpg.h"

void condition_for_menu(glb_t *global)
{
    if (global->bool_main_menu == 1) {
        if (global->bool_menu_htp == 1) {
            the_menu_htp(global);
            draw_for_the_menu_htp(global);
        } else if (global->bool_menu_option == 1) {
            the_menu_option(global);
            draw_for_the_menu_option(global);
        } else {
            main_menu(global);
            draw_for_the_main_menu(global);
        }
    } else {
        if (global->bool_menu_pause == 1) {
            the_menu_pause(global);
            draw_for_the_menu_pause(global);
        }
        else if (global->health <= 0 || global->defeat == 1) {
            the_menu_defeat(global);
            draw_for_the_menu_defeat(global);
        } else {
            sfView_setCenter(global->cam->view,
            sfSprite_getPosition(global->chara->sprite));
            sfRenderWindow_setView(global->wind.window, global->cam->view);
            draw_1(global);
            reset_to_default_view(global->wind.window);
            draw_2(global);
            power_xp(global);
            power_mana(global);
            power_life(global);
            tree_competence(global);
        }
    }
}