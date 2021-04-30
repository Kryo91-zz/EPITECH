/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** btn_option_in_MP.c
*/

#include "../include/my_rpg.h"

int button_option_in_pause_menu(glb_t *global)
{
    global->option_MP.size.x = 2.0f;
    global->option_MP.size.y = 2.0f;
    global->option_MP.pos.x = 1100;
    global->option_MP.pos.y = 600;
    global->option_MP.rect.top = 0;
    global->option_MP.rect.left = 0;
    global->option_MP.rect.width = 95;
    global->option_MP.rect.height = 39;
    global->option_MP.texture = sfTexture_createFromFile
    ("./texture/button/butonoption.png", NULL);
    if (!global->option_MP.texture) {
        write(2, "The button is missing!\n", 24);
        return (84);
    }
    global->option_MP.sprite = sfSprite_create();
    sfSprite_setTexture(global->option_MP.sprite,
    global->option_MP.texture, sfTrue);
    texture_option_in_pause_menu(global);
    return (0);
}

void texture_option_in_pause_menu(glb_t *global)
{
    sfSprite_setPosition(global->option_MP.sprite,
    global->option_MP.pos);
    sfSprite_setScale(global->option_MP.sprite,
    global->option_MP.size);
    sfSprite_setTexture(global->option_MP.sprite,
    global->option_MP.texture, sfTrue);
    sfSprite_setTextureRect(global->option_MP.sprite,
    global->option_MP.rect);
}

void anim_button_option_in_pause_menu(glb_t *global)
{
    global->option_MP.rect.left = 95;
    sfSprite_setTextureRect(global->option_MP.sprite,
    global->option_MP.rect);
}