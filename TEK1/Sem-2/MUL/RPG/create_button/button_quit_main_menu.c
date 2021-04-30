/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** button_quit_main_menu.c
*/

#include "../include/my_rpg.h"

int button_quit_main_menu(glb_t *global)
{
    global->quit_MM.size.x = 2.0f;
    global->quit_MM.size.y = 2.0f;
    global->quit_MM.pos.x = 1050;
    global->quit_MM.pos.y = 400;
    global->quit_MM.rect.top = 0;
    global->quit_MM.rect.left = 0;
    global->quit_MM.rect.width = 95;
    global->quit_MM.rect.height = 39;
    global->quit_MM.texture = sfTexture_createFromFile
    ("./texture/button/butonquitter.png", NULL);
    if (!global->quit_MM.texture) {
        write(2, "The button is missing!\n", 24);
        return (84);
    }
    global->quit_MM.sprite = sfSprite_create();
    sfSprite_setTexture(global->quit_MM.sprite,
    global->quit_MM.texture, sfTrue);
    texture_button_quit_main_menu(global);
    return (0);
}

void texture_button_quit_main_menu(glb_t *global)
{
    sfSprite_setPosition(global->quit_MM.sprite,
    global->quit_MM.pos);
    sfSprite_setScale(global->quit_MM.sprite,
    global->quit_MM.size);
    sfSprite_setTexture(global->quit_MM.sprite,
    global->quit_MM.texture, sfTrue);
    sfSprite_setTextureRect(global->quit_MM.sprite,
    global->quit_MM.rect);
}

void anim_button_quit_main_menu(glb_t *global)
{
    global->quit_MM.rect.left = 95;
    sfSprite_setTextureRect(global->quit_MM.sprite, global->quit_MM.rect);
}