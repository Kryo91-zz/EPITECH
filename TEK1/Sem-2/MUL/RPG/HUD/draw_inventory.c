/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** draw_inventory.c
*/

#include "../include/my_rpg.h"

int inventory_base(glb_t *global)
{
    global->inventory_base.position.x = 10;
    global->inventory_base.position.y = 750;
    global->inventory_base.texture = sfTexture_createFromFile
    ("./texture/inventaire/inventairefinal.png", NULL);
    if (!global->inventory_base.texture) {
        write (2, "The texture is missing!\n", 26);
        return (84);
    }
    global->inventory_base.sprite = sfSprite_create();
    sfSprite_setPosition(global->inventory_base.sprite,
    global->inventory_base.position);
    sfSprite_setTexture(global->inventory_base.sprite,
    global->inventory_base.texture, sfTrue);
    return (0);
}

int inventory_bague(glb_t *global)
{
    global->inventory_1.position.x = 10;
    global->inventory_1.position.y = 750;
    global->inventory_1.texture = sfTexture_createFromFile
    ("./texture/inventaire/inventairebague.png", NULL);
    if (!global->inventory_1.texture) {
        write (2, "The texture is missing!\n", 26);
        return (84);
    }
    global->inventory_1.sprite = sfSprite_create();
    sfSprite_setPosition(global->inventory_1.sprite,
    global->inventory_1.position);
    sfSprite_setTexture(global->inventory_1.sprite,
    global->inventory_1.texture, sfTrue);
    return (0);
}