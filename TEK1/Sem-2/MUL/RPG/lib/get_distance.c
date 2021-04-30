/*
** EPITECH PROJECT, 2019
** get_distance
** File description:
** return the distance between two points
*/

#include "../include/my_rpg.h"

float v2f_dist(const sfVector2f *p1, const sfVector2f *p2)
{
    const float dx = p2->x - p1->x;
    const float dy = p2->y - p1->y;

    return (sqrtf(dx * dx + dy * dy));
}