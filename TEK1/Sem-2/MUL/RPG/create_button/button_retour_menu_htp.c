/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** butoon_retour_menu_htp.c
*/

#include "../include/my_rpg.h"

int button_retour_main_menu(glb_t *global)
{
    global->retour_htp.size.x = 2.0f;
    global->retour_htp.size.y = 2.0f;
    global->retour_htp.pos.x = 850;
    global->retour_htp.pos.y = 920;
    global->retour_htp.rect.top = 0;
    global->retour_htp.rect.left = 0;
    global->retour_htp.rect.width = 95;
    global->retour_htp.rect.height = 39;
    global->retour_htp.texture = sfTexture_createFromFile
    ("./texture/button/butonretour.png", NULL);
    if (!global->retour_htp.texture) {
        write(2, "The button is missing!\n", 24);
        return (84);
    }
    global->retour_htp.sprite = sfSprite_create();
    sfSprite_setTexture(global->retour_htp.sprite,
    global->retour_htp.texture, sfTrue);
    texture_retour_main_menu(global);
    return (0);
}

void texture_retour_main_menu(glb_t *global)
{
    sfSprite_setPosition(global->retour_htp.sprite,
    global->retour_htp.pos);
    sfSprite_setScale(global->retour_htp.sprite,
    global->retour_htp.size);
    sfSprite_setTexture(global->retour_htp.sprite,
    global->retour_htp.texture, sfTrue);
    sfSprite_setTextureRect(global->retour_htp.sprite,
    global->retour_htp.rect);
}

void anim_button_retour_main_menu(glb_t *global)
{
    global->retour_htp.rect.left = 95;
    sfSprite_setTextureRect(global->retour_htp.sprite,
    global->retour_htp.rect);
}