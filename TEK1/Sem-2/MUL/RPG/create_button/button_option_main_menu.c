/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** button_option_main_menu.c
*/

#include "../include/my_rpg.h"

int button_option_main_menu(glb_t *global)
{
    global->option_MM.size.x = 2.0f;
    global->option_MM.size.y = 2.0f;
    global->option_MM.pos.x = 450;
    global->option_MM.pos.y = 700;
    global->option_MM.rect.top = 0;
    global->option_MM.rect.left = 0;
    global->option_MM.rect.width = 95;
    global->option_MM.rect.height = 39;
    global->option_MM.texture = sfTexture_createFromFile
    ("./texture/button/butonoption.png", NULL);
    if (!global->option_MM.texture) {
        write(2, "The button is missing!\n", 24);
        return (84);
    }
    global->option_MM.sprite = sfSprite_create();
    sfSprite_setTexture(global->option_MM.sprite,
    global->option_MM.texture, sfTrue);
    texture_option_main_menu(global);
    return (0);
}

void texture_option_main_menu(glb_t *global)
{
    sfSprite_setPosition(global->option_MM.sprite,
    global->option_MM.pos);
    sfSprite_setScale(global->option_MM.sprite,
    global->option_MM.size);
    sfSprite_setTexture(global->option_MM.sprite,
    global->option_MM.texture, sfTrue);
    sfSprite_setTextureRect(global->option_MM.sprite,
    global->option_MM.rect);
}

void anim_button_option_main_menu(glb_t *global)
{
    global->option_MM.rect.left = 95;
    sfSprite_setTextureRect(global->option_MM.sprite, global->option_MM.rect);
}