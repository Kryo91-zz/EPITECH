/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** get_attack_pos
*/

#include "../include/my_rpg.h"

sfVector2f get_pos(character_t *chara, sfSprite *sprite)
{
    sfVector2f pos;
    sprite = sprite;
    if (chara->vision == 1) {
        pos.x = 875;
        pos.y = 505;
    }
    if (chara->vision == 2) {
        pos.x = 1010;
        pos.y = 505;
    }
    if (chara->vision == 3) {
        pos.y = 580;
        pos.x = 950;
    }
    if (chara->vision == 4) {
        pos.y = 425;
        pos.x = 950;
    }
    return (pos);
}