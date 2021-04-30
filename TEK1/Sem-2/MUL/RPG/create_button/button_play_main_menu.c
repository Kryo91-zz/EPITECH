/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** button_play_main_menu.c
*/

#include "../include/my_rpg.h"

int button_play_main_menu(glb_t *global)
{
    global->play_MM.size.x = 2.0f;
    global->play_MM.size.y = 2.0f;
    global->play_MM.pos.x = 450;
    global->play_MM.pos.y = 400;
    global->play_MM.rect.top = 0;
    global->play_MM.rect.left = 0;
    global->play_MM.rect.width = 95;
    global->play_MM.rect.height = 39;
    global->play_MM.texture = sfTexture_createFromFile
    ("./texture/button/butonjouer.png", NULL);
    if (!global->play_MM.texture) {
        write(2, "The button is missing!\n", 24);
        return (84);
    }
    global->play_MM.sprite = sfSprite_create();
    sfSprite_setTexture(global->play_MM.sprite,
    global->play_MM.texture, sfTrue);
    texture_button_play_main_menu(global);
    return (0);
}

void texture_button_play_main_menu(glb_t *global)
{
    sfSprite_setPosition(global->play_MM.sprite,
    global->play_MM.pos);
    sfSprite_setScale(global->play_MM.sprite,
    global->play_MM.size);
    sfSprite_setTexture(global->play_MM.sprite,
    global->play_MM.texture, sfTrue);
    sfSprite_setTextureRect(global->play_MM.sprite,
    global->play_MM.rect);
}

void anim_button_play_main_menu(glb_t *global)
{
    global->play_MM.rect.left = 95;
    sfSprite_setTextureRect(global->play_MM.sprite, global->play_MM.rect);
}