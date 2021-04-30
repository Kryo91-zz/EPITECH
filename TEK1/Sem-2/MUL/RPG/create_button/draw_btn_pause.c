/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** draw_btn_pause.c
*/

#include "../include/my_rpg.h"

int button_pause_in_game(glb_t *global)
{
    global->pause.size.x = 2.0f;
    global->pause.size.y = 2.0f;
    global->pause.pos.x = 10;
    global->pause.pos.y = 10;
    global->pause.rect.top = 0;
    global->pause.rect.left = 0;
    global->pause.rect.width = 95;
    global->pause.rect.height = 39;
    global->pause.texture = sfTexture_createFromFile
    ("./texture/button/butonpause.png", NULL);
    if (!global->pause.texture) {
        write(2, "The button is missing!\n", 24);
        return (84);
    }
    global->pause.sprite = sfSprite_create();
    sfSprite_setTexture(global->pause.sprite,
    global->pause.texture, sfTrue);
    texture_pause_in_game(global);
    return (0);
}

void texture_pause_in_game(glb_t *global)
{
    sfSprite_setPosition(global->pause.sprite,
    global->pause.pos);
    sfSprite_setScale(global->pause.sprite,
    global->pause.size);
    sfSprite_setTexture(global->pause.sprite,
    global->pause.texture, sfTrue);
    sfSprite_setTextureRect(global->pause.sprite,
    global->pause.rect);
}

void anim_button_pause_in_game(glb_t *global)
{
    global->pause.rect.left = 95;
    sfSprite_setTextureRect(global->pause.sprite, global->pause.rect);
}