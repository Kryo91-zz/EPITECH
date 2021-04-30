/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** btn_quitter_in_MP.c
*/

#include "../include/my_rpg.h"

int button_quitter_in_pause_menu(glb_t *global)
{
    global->quitter_MP.size.x = 2.0f;
    global->quitter_MP.size.y = 2.0f;
    global->quitter_MP.pos.x = 450;
    global->quitter_MP.pos.y = 600;
    global->quitter_MP.rect.top = 0;
    global->quitter_MP.rect.left = 0;
    global->quitter_MP.rect.width = 95;
    global->quitter_MP.rect.height = 39;
    global->quitter_MP.texture = sfTexture_createFromFile
    ("./texture/button/butonquitter.png", NULL);
    if (!global->quitter_MP.texture) {
        write(2, "The button is missing!\n", 24);
        return (84);
    }
    global->quitter_MP.sprite = sfSprite_create();
    sfSprite_setTexture(global->quitter_MP.sprite,
    global->quitter_MP.texture, sfTrue);
    texture_quitter_in_pause_menu(global);
    return (0);
}

void texture_quitter_in_pause_menu(glb_t *global)
{
    sfSprite_setPosition(global->quitter_MP.sprite,
    global->quitter_MP.pos);
    sfSprite_setScale(global->quitter_MP.sprite,
    global->quitter_MP.size);
    sfSprite_setTexture(global->quitter_MP.sprite,
    global->quitter_MP.texture, sfTrue);
    sfSprite_setTextureRect(global->quitter_MP.sprite,
    global->quitter_MP.rect);
}

void anim_button_quitter_in_pause_menu(glb_t *global)
{
    global->quitter_MP.rect.left = 95;
    sfSprite_setTextureRect(global->quitter_MP.sprite, global->quitter_MP.rect);
}