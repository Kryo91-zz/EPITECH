/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** menu_defeat.c
*/

#include "../include/my_rpg.h"

int create_game_over(glb_t *global)
{
    global->game_over.pos.x = 650;
    global->game_over.pos.y = 300;
    global->game_over.texture = sfTexture_createFromFile
    ("./texture/titre/gameover.png", NULL);
    if (!global->game_over.texture) {
        write(2, "The background is missing!\n", 27);
        return (84);
    }
    global->game_over.sprite = sfSprite_create();
    sfSprite_setTexture(global->game_over.sprite,
    global->game_over.texture, sfTrue);
    sfSprite_setPosition(global->game_over.sprite,
    global->game_over.pos);
    return (0);
}

int the_menu_defeat(glb_t *global)
{
    hitbox_btn_retour_menu_defeat(global);
    return (0);
}

void draw_for_the_menu_defeat(glb_t *global)
{
    sfRenderWindow_clear(global->wind.window, sfBlack);
    for (int i = 0; i < 7; i++)
        sfRenderWindow_drawSprite(global->wind.window,
        global->obj[i]->sprite, NULL);
    sfRenderWindow_drawSprite(global->wind.window,
    global->game_over.sprite, NULL);
    sfRenderWindow_drawSprite(global->wind.window,
    global->retour_defeat.sprite, NULL);
    sfRenderWindow_drawSprite(global->wind.window,
    global->cursor.sprite, NULL);
    sfRenderWindow_display(global->wind.window);
    get_mouse_position(global);
}

void destroy_for_the_menu_defeat(glb_t *global)
{
    sfSprite_destroy(global->game_over.sprite);
    sfTexture_destroy(global->game_over.texture);
    sfRenderWindow_destroy(global->wind.window);
}