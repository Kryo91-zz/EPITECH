/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** menu_pause.c
*/

#include "../include/my_rpg.h"

int background_pause(glb_t *global)
{
    global->back_pause.pos.x = 750;
    global->back_pause.pos.y = 300;
    global->back_pause.texture = sfTexture_createFromFile
    ("./texture/background/paused1.png", NULL);
    if (!global->back_pause.texture) {
        write(2, "The background is missing!\n", 27);
        return (84);
    }
    global->back_pause.sprite = sfSprite_create();
    sfSprite_setTexture(global->back_pause.sprite,
    global->back_pause.texture, sfTrue);
    sfSprite_setPosition(global->back_pause.sprite, global->back_pause.pos);
    return (0);
}

int the_menu_pause(glb_t *global)
{
    hitbox_button_reprendre_in_menu_pause(global);
    hitbox_button_quiter_in_menu_pause(global);
    hitbox_button_sauvegarder_in_menu_pause(global);
    hitbox_button_option_in_menu_pause(global);
    hitbox_button_menu_prin_in_menu_pause(global);
    return (0);
}

void draw_for_the_menu_pause(glb_t *global)
{
    sfRenderWindow_clear(global->wind.window, sfBlack);
    for (int i = 0; i < 7; i++)
        sfRenderWindow_drawSprite(global->wind.window,
        global->obj[i]->sprite, NULL);
    sfRenderWindow_drawSprite(global->wind.window,
    global->back_pause.sprite, NULL);
    sfRenderWindow_drawSprite(global->wind.window,
    global->reprendre.sprite, NULL);
    sfRenderWindow_drawSprite(global->wind.window,
    global->quitter_MP.sprite, NULL);
    sfRenderWindow_drawSprite(global->wind.window,
    global->sauvegarder.sprite, NULL);
    sfRenderWindow_drawSprite(global->wind.window,
    global->option_MP.sprite, NULL);
    sfRenderWindow_drawSprite(global->wind.window,
    global->menu_principal.sprite, NULL);
    sfRenderWindow_drawSprite(global->wind.window,
    global->cursor.sprite, NULL);
    sfRenderWindow_display(global->wind.window);
    get_mouse_position(global);
}

void destroy_for_the_menu_pause(glb_t *global)
{
    sfSprite_destroy(global->back_pause.sprite);
    sfTexture_destroy(global->back_pause.texture);
    sfSprite_destroy(global->cursor.sprite);
    sfTexture_destroy(global->cursor.texture);
    sfSprite_destroy(global->quitter_MP.sprite);
    sfTexture_destroy(global->quitter_MP.texture);
    sfSprite_destroy(global->reprendre.sprite);
    sfTexture_destroy(global->reprendre.texture);
    sfSprite_destroy(global->sauvegarder.sprite);
    sfTexture_destroy(global->sauvegarder.texture);
    sfSprite_destroy(global->option_MP.sprite);
    sfTexture_destroy(global->option_MP.texture);
    sfSprite_destroy(global->menu_principal.sprite);
    sfTexture_destroy(global->menu_principal.texture);
    sfRenderWindow_destroy(global->wind.window);
}