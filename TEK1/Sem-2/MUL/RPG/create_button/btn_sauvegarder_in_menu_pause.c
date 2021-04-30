/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** btn_sauvegarder_in_MP.c
*/

#include "../include/my_rpg.h"

int button_sauvegarder_in_pause_menu(glb_t *global)
{
    global->sauvegarder.size.x = 2.0f;
    global->sauvegarder.size.y = 2.0f;
    global->sauvegarder.pos.x = 800;
    global->sauvegarder.pos.y = 600;
    global->sauvegarder.rect.top = 0;
    global->sauvegarder.rect.left = 0;
    global->sauvegarder.rect.width = 95;
    global->sauvegarder.rect.height = 39;
    global->sauvegarder.texture = sfTexture_createFromFile
    ("./texture/button/butonsauvegarder.png", NULL);
    if (!global->sauvegarder.texture) {
        write(2, "The button is missing!\n", 24);
        return (84);
    }
    global->sauvegarder.sprite = sfSprite_create();
    sfSprite_setTexture(global->sauvegarder.sprite,
    global->sauvegarder.texture, sfTrue);
    texture_sauvegarder_in_pause_menu(global);
    return (0);
}

void texture_sauvegarder_in_pause_menu(glb_t *global)
{
    sfSprite_setPosition(global->sauvegarder.sprite,
    global->sauvegarder.pos);
    sfSprite_setScale(global->sauvegarder.sprite,
    global->sauvegarder.size);
    sfSprite_setTexture(global->sauvegarder.sprite,
    global->sauvegarder.texture, sfTrue);
    sfSprite_setTextureRect(global->sauvegarder.sprite,
    global->sauvegarder.rect);
}

void anim_button_sauvegarder_in_pause_menu(glb_t *global)
{
    global->sauvegarder.rect.left = 95;
    sfSprite_setTextureRect(global->sauvegarder.sprite,
    global->sauvegarder.rect);
}