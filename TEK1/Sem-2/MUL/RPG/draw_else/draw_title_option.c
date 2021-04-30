/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** draw_title_option.c
*/

#include "../include/my_rpg.h"

int create_title_option(glb_t *global)
{
    global->title_option.pos.x = 650;
    global->title_option.pos.y = 150;
    global->title_option.texture = sfTexture_createFromFile
    ("./texture/titre/option.png", NULL);
    if (!global->title_option.texture) {
        write(2, "The background is missing!\n", 27);
        return (84);
    }
    global->title_option.sprite = sfSprite_create();
    sfSprite_setTexture(global->title_option.sprite,
    global->title_option.texture, sfTrue);
    sfSprite_setPosition(global->title_option.sprite, global->title_option.pos);
    return (0);
}