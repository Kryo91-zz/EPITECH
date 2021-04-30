/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** main_menu.c
*/

#include "../include/my_rpg.h"

int main_menu(glb_t *global)
{
    hitbox_button_play_main_menu(global);
    hitbox_button_charger_main_menu(global);
    hitbox_button_quit_main_menu(global);
    hitbox_button_option_main_menu(global);
    hitbox_button_aide_main_menu(global);
    return (0);
}

void draw_for_the_main_menu(glb_t *global)
{
    sfRenderWindow_clear(global->wind.window, sfBlack);
    for (int i = 0; i < 7; i++)
        sfRenderWindow_drawSprite(global->wind.window,
        global->obj[i]->sprite, NULL);
    sfRenderWindow_drawSprite(global->wind.window,
    global->title.sprite, NULL);
    sfRenderWindow_drawSprite(global->wind.window,
    global->play_MM.sprite, NULL);
    sfRenderWindow_drawSprite(global->wind.window,
    global->quit_MM.sprite, NULL);
    sfRenderWindow_drawSprite(global->wind.window,
    global->option_MM.sprite, NULL);
    sfRenderWindow_drawSprite(global->wind.window,
    global->aide_MM.sprite, NULL);
    sfRenderWindow_drawSprite(global->wind.window,
    global->charger_MM.sprite, NULL);
    sfRenderWindow_drawSprite(global->wind.window,
    global->cursor.sprite, NULL);
    sfRenderWindow_display(global->wind.window);
}

void destroy_for_the_main_menu(glb_t *global)
{
    for (int i = 0; i < 7; i++) {
        sfSprite_destroy(global->obj[i]->sprite);
        sfTexture_destroy(global->obj[i]->texture);
    }
    sfSprite_destroy(global->title.sprite);
    sfTexture_destroy(global->title.texture);
    sfSprite_destroy(global->play_MM.sprite);
    sfTexture_destroy(global->play_MM.texture);
    sfSprite_destroy(global->quit_MM.sprite);
    sfTexture_destroy(global->quit_MM.texture);
    sfSprite_destroy(global->option_MM.sprite);
    sfTexture_destroy(global->option_MM.texture);
    sfSprite_destroy(global->aide_MM.sprite);
    sfTexture_destroy(global->aide_MM.texture);
    sfSprite_destroy(global->charger_MM.sprite);
    sfTexture_destroy(global->charger_MM.texture);
    sfRenderWindow_destroy(global->wind.window);
}