/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** draw_inventory2.c
*/

#include "../include/my_rpg.h"

int inventory_collier(glb_t *global)
{
    global->inventory_2.position.x = 10;
    global->inventory_2.position.y = 750;
    global->inventory_2.texture = sfTexture_createFromFile
    ("./texture/inventaire/inventairecollier.png", NULL);
    if (!global->inventory_2.texture) {
        write (2, "The texture is missing!\n", 26);
        return (84);
    }
    global->inventory_2.sprite = sfSprite_create();
    sfSprite_setPosition(global->inventory_2.sprite,
    global->inventory_2.position);
    sfSprite_setTexture(global->inventory_2.sprite,
    global->inventory_2.texture, sfTrue);
    return (0);
}

int inventory_sceptre(glb_t *global)
{
    global->inventory_3.position.x = 10;
    global->inventory_3.position.y = 750;
    global->inventory_3.texture = sfTexture_createFromFile
    ("./texture/inventaire/inventairesceptre.png", NULL);
    if (!global->inventory_3.texture) {
        write (2, "The texture is missing!\n", 26);
        return (84);
    }
    global->inventory_3.sprite = sfSprite_create();
    sfSprite_setPosition(global->inventory_3.sprite,
    global->inventory_3.position);
    sfSprite_setTexture(global->inventory_3.sprite,
    global->inventory_3.texture, sfTrue);
    return (0);
}