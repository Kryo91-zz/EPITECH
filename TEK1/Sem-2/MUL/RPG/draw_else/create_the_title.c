/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** create_the_title.c
*/

#include "../include/my_rpg.h"

int create_title(glb_t *global)
{
    global->title.pos.x = 570;
    global->title.pos.y = 150;
    global->title.texture = sfTexture_createFromFile
    ("./texture/titre/titre.png", NULL);
    if (!global->title.texture) {
        write(2, "The background is missing!\n", 27);
        return (84);
    }
    global->title.sprite = sfSprite_create();
    sfSprite_setTexture(global->title.sprite, global->title.texture, sfTrue);
    sfSprite_setPosition(global->title.sprite, global->title.pos);
    return (0);
}