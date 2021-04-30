/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** inventory.c
*/

#include "../include/my.h"

void inventory_draw(my_defender_t *df)
{
        sfSprite_setPosition(df->s_tower, (sfVector2f){380, 640});
        sfSprite_setPosition(df->s_tower2, (sfVector2f){620, 640});
        sfSprite_setPosition(df->s_tower3, (sfVector2f){883, 245});
        sfSprite_setPosition(df->s_tower4, (sfVector2f){1130, 670});
        sfSprite_setTextureRect(df->s_tower, df->rect_tower.rect);
        sfSprite_setTextureRect(df->s_tower2, df->rect_tower2.rect);
        sfSprite_setTextureRect(df->s_tower3, df->rect_tower3.rect);
        sfSprite_setTextureRect(df->s_tower4, df->rect_tower4.rect);
        sfRenderWindow_drawSprite(df->window, df->s_tower, NULL);
        sfRenderWindow_drawSprite(df->window, df->s_tower2, NULL);
        sfRenderWindow_drawSprite(df->window, df->s_tower3, NULL);
        sfRenderWindow_drawSprite(df->window, df->s_tower4, NULL);
        sfRenderWindow_drawSprite(df->window, df->s_inventory, NULL);
}