/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** functional_inventory.c
*/

#include "../include/my_rpg.h"

int get_obj(glb_t *global, HUD_t obj)
{
    sfIntRect player;
    sfVector2f vec;
    sfVector2f vec2;

    vec = sfSprite_getPosition(global->chara->sprite);
    vec2 = sfSprite_getPosition(obj.sprite);
    player = sfSprite_getTextureRect(global->chara->sprite);
    if ((vec.x >= vec2.x && vec.x <= vec2.x + 40) ||
    (vec.x + player.width >= vec2.x && vec.x + player.width <= vec2.x + 40)) {
        if ((vec.y >= vec2.y && vec.y <= vec2.y + 45) ||
        (vec.y + player.height >= vec2.y && vec.y +
        player.height <= vec2.y + 45))
        return (0);
    }
    return (1);
}

void make_functionnal_inventory(glb_t *global)
{
    if (global->drop == 0) {
        sfRenderWindow_drawSprite(global->wind.window,
        global->inventory_base.sprite, NULL);
        sfRenderWindow_drawSprite(global->wind.window,
        global->bague.sprite, NULL);
        if (get_obj(global, global->bague) == 0) {
            global->drop += 1;
        }
    }
    if (global->drop == 1) {
        sfRenderWindow_drawSprite(global->wind.window,
        global->inventory_1.sprite, NULL);
        sfRenderWindow_drawSprite(global->wind.window,
        global->collier.sprite, NULL);
        if (get_obj(global, global->collier) == 0) {
            global->drop += 1;
        }
    }
    if (global->drop == 2) {
        sfRenderWindow_drawSprite(global->wind.window,
        global->inventory_2.sprite, NULL);
        if (get_obj(global, global->sceptre) == 0) {
            global->drop += 1;
        }
    }
    if (global->drop == 3) {
        sfRenderWindow_drawSprite(global->wind.window,
        global->inventory_3.sprite, NULL);
    }
}