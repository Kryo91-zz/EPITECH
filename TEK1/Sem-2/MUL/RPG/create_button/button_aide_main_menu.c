/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** button_aide_main_menu.c
*/

#include "../include/my_rpg.h"

int button_aide_main_menu(glb_t *global)
{
    global->aide_MM.size.x = 2.0f;
    global->aide_MM.size.y = 2.0f;
    global->aide_MM.pos.x = 1050;
    global->aide_MM.pos.y = 700;
    global->aide_MM.rect.top = 0;
    global->aide_MM.rect.left = 0;
    global->aide_MM.rect.width = 95;
    global->aide_MM.rect.height = 39;
    global->aide_MM.texture = sfTexture_createFromFile
    ("./texture/button/butonaide.png", NULL);
    if (!global->aide_MM.texture) {
        write(2, "The button is missing!\n", 24);
        return (84);
    }
    global->aide_MM.sprite = sfSprite_create();
    sfSprite_setTexture(global->aide_MM.sprite,
    global->aide_MM.texture, sfTrue);
    texture_aide_main_menu(global);
    return (0);
}

void texture_aide_main_menu(glb_t *global)
{
    sfSprite_setPosition(global->aide_MM.sprite,
    global->aide_MM.pos);
    sfSprite_setScale(global->aide_MM.sprite,
    global->aide_MM.size);
    sfSprite_setTexture(global->aide_MM.sprite,
    global->aide_MM.texture, sfTrue);
    sfSprite_setTextureRect(global->aide_MM.sprite,
    global->aide_MM.rect);
}

void anim_button_aide_main_menu(glb_t *global)
{
    global->aide_MM.rect.left = 95;
    sfSprite_setTextureRect(global->aide_MM.sprite, global->aide_MM.rect);
}