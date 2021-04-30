/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** norm2.c
*/

#include "../include/my.h"

float get_distance(float x, float y, sfVector2f p2)
{
    const float dx = p2.x - x;
    const float dy = p2.y - y;

    return (sqrtf(dx * dx + dy * dy));
}