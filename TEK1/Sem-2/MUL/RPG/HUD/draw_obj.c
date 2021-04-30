/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** draw_obj.c
*/

#include "../include/my_rpg.h"

int draw_obj_bague(glb_t *global)
{
    global->bague.size.x = 3.0f;
    global->bague.size.y = 3.0f;
    global->bague.position.x = 960;
    global->bague.position.y = 1600;
    global->bague.texture = sfTexture_createFromFile
    ("./texture/obj/BAGUE.png", NULL);
    if (!global->bague.texture) {
        write (2, "The texture is missing!\n", 26);
        return (84);
    }
    global->bague.sprite = sfSprite_create();
    sfSprite_setPosition(global->bague.sprite,
    global->bague.position);
    sfSprite_setTexture(global->bague.sprite,
    global->bague.texture, sfTrue);
        sfSprite_setScale(global->bague.sprite,
    global->bague.size);
    return (0);
}

int draw_obj_collier(glb_t *global)
{
    global->collier.size.x = 3.0f;
    global->collier.size.y = 3.0f;
    global->collier.position.x = 1570;
    global->collier.position.y = 3350;
    global->collier.texture = sfTexture_createFromFile
    ("./texture/obj/COLLIER.png", NULL);
    if (!global->collier.texture) {
        write (2, "The texture is missing!\n", 26);
        return (84);
    }
    global->collier.sprite = sfSprite_create();
    sfSprite_setPosition(global->collier.sprite,
    global->collier.position);
    sfSprite_setTexture(global->collier.sprite,
    global->collier.texture, sfTrue);
    sfSprite_setScale(global->collier.sprite,
    global->collier.size);
    return (0);
}

int draw_obj_sceptre(glb_t *global)
{
    global->sceptre.size.x = 3.0f;
    global->sceptre.size.y = 3.0f;
    global->sceptre.position.x = 4500;
    global->sceptre.position.y = 2800;
    global->sceptre.texture = sfTexture_createFromFile
    ("./texture/obj/SCEPTRE.png", NULL);
    if (!global->sceptre.texture) {
        write (2, "The texture is missing!\n", 26);
        return (84);
    }
    global->sceptre.sprite = sfSprite_create();
    sfSprite_setPosition(global->sceptre.sprite,
    global->sceptre.position);
    sfSprite_setTexture(global->sceptre.sprite,
    global->sceptre.texture, sfTrue);
    sfSprite_setScale(global->sceptre.sprite,
    global->sceptre.size);
    return (0);
}