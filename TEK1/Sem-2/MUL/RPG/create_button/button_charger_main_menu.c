/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** button_charger_main_menu.c
*/

#include "../include/my_rpg.h"

int button_charger_main_menu(glb_t *global)
{
    global->charger_MM.size.x = 2.0f;
    global->charger_MM.size.y = 2.0f;
    global->charger_MM.pos.x = 750;
    global->charger_MM.pos.y = 560;
    global->charger_MM.rect.top = 0;
    global->charger_MM.rect.left = 0;
    global->charger_MM.rect.width = 95;
    global->charger_MM.rect.height = 39;
    global->charger_MM.texture = sfTexture_createFromFile
    ("./texture/button/butoncharger.png", NULL);
    if (!global->charger_MM.texture) {
        write(2, "The button is missing!\n", 24);
        return (84);
    }
    global->charger_MM.sprite = sfSprite_create();
    sfSprite_setTexture(global->charger_MM.sprite,
    global->charger_MM.texture, sfTrue);
    texture_charger_main_menu(global);
    return (0);
}

void texture_charger_main_menu(glb_t *global)
{
    sfSprite_setPosition(global->charger_MM.sprite,
    global->charger_MM.pos);
    sfSprite_setScale(global->charger_MM.sprite,
    global->charger_MM.size);
    sfSprite_setTexture(global->charger_MM.sprite,
    global->charger_MM.texture, sfTrue);
    sfSprite_setTextureRect(global->charger_MM.sprite,
    global->charger_MM.rect);
}

void anim_button_charger_main_menu(glb_t *global)
{
    global->charger_MM.rect.left = 95;
    sfSprite_setTextureRect(global->charger_MM.sprite, global->charger_MM.rect);
}