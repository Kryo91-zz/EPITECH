/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** draw_cursor.c
*/

#include "../include/my_rpg.h"

int draw_cursor(glb_t *global)
{
    global->cursor.texture = sfTexture_createFromFile
    ("./texture/cursor/cursor.png", NULL);
    if (!global->cursor.texture) {
        write(2, "The cursor is missing!\n", 23);
        return (84);
    }
    global->cursor.sprite = sfSprite_create();
    sfSprite_setTexture(global->cursor.sprite, global->cursor.texture, sfTrue);
    return (0);
}

void get_mouse_position(glb_t *global)
{
    sfVector2f pos;

    global->cursor.mouseposition = sfMouse_getPositionRenderWindow
    (global->wind.window);
    pos.x = global->cursor.mouseposition.x - 37.5;
    pos.y = global->cursor.mouseposition.y - 37.5;
    sfSprite_setPosition(global->cursor.sprite, pos);
}