/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** btn_menu_prin_in_MP.c
*/

#include "../include/my_rpg.h"

int button_menu_prin_in_pause_menu(glb_t *global)
{
    global->menu_principal.size.x = 2.0f;
    global->menu_principal.size.y = 2.0f;
    global->menu_principal.pos.x = 1400;
    global->menu_principal.pos.y = 600;
    global->menu_principal.rect.top = 0;
    global->menu_principal.rect.left = 0;
    global->menu_principal.rect.width = 95;
    global->menu_principal.rect.height = 39;
    global->menu_principal.texture = sfTexture_createFromFile
    ("./texture/button/butonmenuprincipal.png", NULL);
    if (!global->menu_principal.texture) {
        write(2, "The button is missing!\n", 24);
        return (84);
    }
    global->menu_principal.sprite = sfSprite_create();
    sfSprite_setTexture(global->menu_principal.sprite,
    global->menu_principal.texture, sfTrue);
    texture_menu_prin_in_pause_menu(global);
    return (0);
}

void texture_menu_prin_in_pause_menu(glb_t *global)
{
    sfSprite_setPosition(global->menu_principal.sprite,
    global->menu_principal.pos);
    sfSprite_setScale(global->menu_principal.sprite,
    global->menu_principal.size);
    sfSprite_setTexture(global->menu_principal.sprite,
    global->menu_principal.texture, sfTrue);
    sfSprite_setTextureRect(global->menu_principal.sprite,
    global->menu_principal.rect);
}

void anim_button_menu_prin_in_pause_menu(glb_t *global)
{
    global->menu_principal.rect.left = 95;
    sfSprite_setTextureRect(global->menu_principal.sprite,
    global->menu_principal.rect);
}