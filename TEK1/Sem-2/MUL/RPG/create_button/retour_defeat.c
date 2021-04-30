/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** retour_defeat.c
*/

#include "../include/my_rpg.h"

int btn_retour_defeat(glb_t *global)
{
    global->retour_defeat.size.x = 2.0f;
    global->retour_defeat.size.y = 2.0f;
    global->retour_defeat.pos.x = 780;
    global->retour_defeat.pos.y = 800;
    global->retour_defeat.rect.top = 0;
    global->retour_defeat.rect.left = 0;
    global->retour_defeat.rect.width = 95;
    global->retour_defeat.rect.height = 39;
    global->retour_defeat.texture = sfTexture_createFromFile
    ("./texture/button/butonquitter.png", NULL);
    if (!global->retour_defeat.texture) {
        write(2, "The button is missing!\n", 24);
        return (84);
    }
    global->retour_defeat.sprite = sfSprite_create();
    sfSprite_setTexture(global->retour_defeat.sprite,
    global->retour_defeat.texture, sfTrue);
    texture_retour_defeat(global);
    return (0);
}

void texture_retour_defeat(glb_t *global)
{
    sfSprite_setPosition(global->retour_defeat.sprite,
    global->retour_defeat.pos);
    sfSprite_setScale(global->retour_defeat.sprite,
    global->retour_defeat.size);
    sfSprite_setTexture(global->retour_defeat.sprite,
    global->retour_defeat.texture, sfTrue);
    sfSprite_setTextureRect(global->retour_defeat.sprite,
    global->retour_defeat.rect);
}

void anim_retour_defeat(glb_t *global)
{
    global->retour_defeat.rect.left = 95;
    sfSprite_setTextureRect(global->retour_defeat.sprite,
    global->retour_defeat.rect);
}