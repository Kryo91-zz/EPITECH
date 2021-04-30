/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** btn_retour_menu_option.c
*/

#include "../include/my_rpg.h"

int button_retour_menu_option(glb_t *global)
{
    global->retour_MO.size.x = 2.0f;
    global->retour_MO.size.y = 2.0f;
    global->retour_MO.pos.x = 780;
    global->retour_MO.pos.y = 800;
    global->retour_MO.rect.top = 0;
    global->retour_MO.rect.left = 0;
    global->retour_MO.rect.width = 95;
    global->retour_MO.rect.height = 39;
    global->retour_MO.texture = sfTexture_createFromFile
    ("./texture/button/butonretour.png", NULL);
    if (!global->retour_MO.texture) {
        write(2, "The button is missing!\n", 24);
        return (84);
    }
    global->retour_MO.sprite = sfSprite_create();
    sfSprite_setTexture(global->retour_MO.sprite,
    global->retour_MO.texture, sfTrue);
    texture_retour_menu_option(global);
    return (0);
}

void texture_retour_menu_option(glb_t *global)
{
    sfSprite_setPosition(global->retour_MO.sprite,
    global->retour_MO.pos);
    sfSprite_setScale(global->retour_MO.sprite,
    global->retour_MO.size);
    sfSprite_setTexture(global->retour_MO.sprite,
    global->retour_MO.texture, sfTrue);
    sfSprite_setTextureRect(global->retour_MO.sprite,
    global->retour_MO.rect);
}

void anim_button_retour_menu_option(glb_t *global)
{
    global->retour_MO.rect.left = 95;
    sfSprite_setTextureRect(global->retour_MO.sprite, global->retour_MO.rect);
}