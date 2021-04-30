/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** btn_reprendre_in_MP.c
*/

#include "../include/my_rpg.h"

int button_reprendre_in_pause_menu(glb_t *global)
{
    global->reprendre.size.x = 2.0f;
    global->reprendre.size.y = 2.0f;
    global->reprendre.pos.x = 100;
    global->reprendre.pos.y = 600;
    global->reprendre.rect.top = 0;
    global->reprendre.rect.left = 0;
    global->reprendre.rect.width = 95;
    global->reprendre.rect.height = 39;
    global->reprendre.texture = sfTexture_createFromFile
    ("./texture/button/butonreprendre.png", NULL);
    if (!global->reprendre.texture) {
        write(2, "The button is missing!\n", 24);
        return (84);
    }
    global->reprendre.sprite = sfSprite_create();
    sfSprite_setTexture(global->reprendre.sprite,
    global->reprendre.texture, sfTrue);
    texture_reprendre_in_pause_menu(global);
    return (0);
}

void texture_reprendre_in_pause_menu(glb_t *global)
{
    sfSprite_setPosition(global->reprendre.sprite,
    global->reprendre.pos);
    sfSprite_setScale(global->reprendre.sprite,
    global->reprendre.size);
    sfSprite_setTexture(global->reprendre.sprite,
    global->reprendre.texture, sfTrue);
    sfSprite_setTextureRect(global->reprendre.sprite,
    global->reprendre.rect);
}

void anim_button_reprendre_in_pause_menu(glb_t *global)
{
    global->reprendre.rect.left = 95;
    sfSprite_setTextureRect(global->reprendre.sprite, global->reprendre.rect);
}