/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** pnj.c
*/

#include "../include/my_rpg.h"

int pnj_base(glb_t *global)
{
    global->pnj.clock = sfClock_create();
    global->pnj.seconds = 0;
    global->pnj.size.x = 2.5f;
    global->pnj.size.y = 2.5f;
    global->pnj.position.x = 4100;
    global->pnj.position.y = 1330;
    global->pnj.rect.top = 0;
    global->pnj.rect.left = 0;
    global->pnj.rect.width = 63;
    global->pnj.rect.height = 44;
    global->pnj.texture = sfTexture_createFromFile
    ("./texture/mob/pnj.png", NULL);
    if (!global->pnj.texture) {
        write (2, "The texture is missing!\n", 26);
        return (84);
    }
    global->pnj.sprite = sfSprite_create();
    sfSprite_setPosition(global->pnj.sprite, global->pnj.position);
    sfSprite_setTexture(global->pnj.sprite, global->pnj.texture, sfTrue);
    return (0);
}