/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** draw_btn_plus.c
*/

#include "../include/my_rpg.h"

int button_plus_create(glb_t *global)
{
    global->plus.size.x = 1.5f;
    global->plus.size.y = 1.5f;
    global->plus.pos.x = 1000;
    global->plus.pos.y = 400;
    global->plus.rect.top = 0;
    global->plus.rect.left = 0;
    global->plus.rect.width = 56;
    global->plus.rect.height = 56;
    global->plus.texture = sfTexture_createFromFile
    ("./texture/HUD/plusbtn.png", NULL);
    if (!global->plus.texture) {
        write(2, "The button is missing!\n", 24);
        return (84);
    }
    global->plus.sprite = sfSprite_create();
    sfSprite_setTexture(global->plus.sprite,
    global->plus.texture, sfTrue);
    texture_btn_plus(global);
    return (0);
}

void texture_btn_plus(glb_t *global)
{
    sfSprite_setPosition(global->plus.sprite,
    global->plus.pos);
    sfSprite_setScale(global->plus.sprite,
    global->plus.size);
    sfSprite_setTexture(global->plus.sprite,
    global->plus.texture, sfTrue);
    sfSprite_setTextureRect(global->plus.sprite,
    global->plus.rect);
}

void anim_btn_plus(glb_t *global)
{
    global->plus.rect.left = 56;
    sfSprite_setTextureRect(global->plus.sprite,
    global->plus.rect);
}