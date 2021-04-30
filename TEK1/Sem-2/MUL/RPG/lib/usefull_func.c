/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** usefull_func
*/

#include "../include/my_rpg.h"

sfVector2f pos(float x, float y)
{
    sfVector2f pos;
    pos.x = x;
    pos.y = y;
    return (pos);
}

sfIntRect rect(int top, int left, int width, int height)
{
    sfIntRect rect;
    rect.top = top;
    rect.left = left;
    rect.width = width;
    rect.height = height;

    return (rect);
}
