/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** draw_btn_moins.c
*/

#include "../include/my_rpg.h"

int button_moins_create(glb_t *global)
{
    global->moins.size.x = 1.5f;
    global->moins.size.y = 1.5f;
    global->moins.pos.x = 700;
    global->moins.pos.y = 400;
    global->moins.rect.top = 0;
    global->moins.rect.left = 0;
    global->moins.rect.width = 55;
    global->moins.rect.height = 53;
    global->moins.texture = sfTexture_createFromFile
    ("./texture/HUD/moinsbtn.png", NULL);
    if (!global->moins.texture) {
        write(2, "The button is missing!\n", 24);
        return (84);
    }
    global->moins.sprite = sfSprite_create();
    sfSprite_setTexture(global->moins.sprite,
    global->moins.texture, sfTrue);
    texture_btn_moins(global);
    return (0);
}

void texture_btn_moins(glb_t *global)
{
    sfSprite_setPosition(global->moins.sprite,
    global->moins.pos);
    sfSprite_setScale(global->moins.sprite,
    global->moins.size);
    sfSprite_setTexture(global->moins.sprite,
    global->moins.texture, sfTrue);
    sfSprite_setTextureRect(global->moins.sprite,
    global->moins.rect);
}

void anim_btn_moins(glb_t *global)
{
    global->moins.rect.left = 55;
    sfSprite_setTextureRect(global->moins.sprite,
    global->moins.rect);
}