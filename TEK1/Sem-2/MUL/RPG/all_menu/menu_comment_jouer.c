/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** menu_comment_jouer.c
*/

#include "../include/my_rpg.h"

int background_htp(glb_t *global)
{
    global->back_htp.pos.x = 150;
    global->back_htp.pos.y = 50;
    global->back_htp.texture = sfTexture_createFromFile
    ("./texture/background/htp.png", NULL);
    if (!global->back_htp.texture) {
        write(2, "The background is missing!\n", 27);
        return (84);
    }
    global->back_htp.sprite = sfSprite_create();
    sfSprite_setTexture(global->back_htp.sprite,
    global->back_htp.texture, sfTrue);
    sfSprite_setPosition(global->back_htp.sprite, global->back_htp.pos);
    return (0);
}

int the_menu_htp(glb_t *global)
{
    hitbox_button_retour_main_menu(global);
    return (0);
}

void draw_for_the_menu_htp(glb_t *global)
{
    sfRenderWindow_clear(global->wind.window, sfBlack);
    for (int i = 0; i < 7; i++)
        sfRenderWindow_drawSprite(global->wind.window,
        global->obj[i]->sprite, NULL);
    sfRenderWindow_drawSprite(global->wind.window,
    global->back_htp.sprite, NULL);
    sfRenderWindow_drawSprite(global->wind.window,
    global->retour_htp.sprite, NULL);
    sfRenderWindow_drawSprite(global->wind.window,
    global->cursor.sprite, NULL);
    sfRenderWindow_display(global->wind.window);
    get_mouse_position(global);
}

void destroy_for_the_menu_htp(glb_t *global)
{
    sfSprite_destroy(global->back_htp.sprite);
    sfTexture_destroy(global->back_htp.texture);
    sfSprite_destroy(global->cursor.sprite);
    sfTexture_destroy(global->cursor.texture);
    sfSprite_destroy(global->retour_htp.sprite);
    sfTexture_destroy(global->retour_htp.texture);
    sfRenderWindow_destroy(global->wind.window);
}