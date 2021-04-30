/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** menu_option.c
*/

#include "../include/my_rpg.h"

int the_menu_option(glb_t *global)
{
    hitbox_button_retour_menu_option(global);
    hitbox_btn_moins(global);
    hitbox_btn_plus(global);
    return (0);
}

void draw_for_the_menu_option(glb_t *global)
{
    sfRenderWindow_clear(global->wind.window, sfBlack);
    for (int i = 0; i < 7; i++)
        sfRenderWindow_drawSprite(global->wind.window,
        global->obj[i]->sprite, NULL);
    sfRenderWindow_drawSprite(global->wind.window,
    global->title_option.sprite, NULL);
    sfRenderWindow_drawSprite(global->wind.window,
    global->retour_MO.sprite, NULL);
    sfRenderWindow_drawSprite(global->wind.window,
    global->plus.sprite, NULL);
    sfRenderWindow_drawSprite(global->wind.window,
    global->moins.sprite, NULL);
    sfRenderWindow_drawSprite(global->wind.window,
    global->cursor.sprite, NULL);
    sfRenderWindow_display(global->wind.window);
    get_mouse_position(global);
}

void destroy_for_the_menu_option(glb_t *global)
{
    sfSprite_destroy(global->back_htp.sprite);
    sfTexture_destroy(global->back_htp.texture);
    sfSprite_destroy(global->cursor.sprite);
    sfTexture_destroy(global->cursor.texture);
    sfSprite_destroy(global->retour_MO.sprite);
    sfTexture_destroy(global->retour_MO.texture);
    sfRenderWindow_destroy(global->wind.window);
}