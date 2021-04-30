/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** anim
*/

#include "../include/my_rpg.h"

void anim_left(character_t *chara)
{
    float seconds;

    chara->time = sfClock_getElapsedTime(chara->clock);
    seconds = chara->time.microseconds/100000;
    if (chara->vision != chara->old_vision)
        seconds = 1;
    if (seconds >= 1) {
        if (chara->anim == 1)
            sfSprite_setTextureRect(chara->sprite, rect(32, 324, 24, 32));
        if (chara->anim == 4)
            sfSprite_setTextureRect(chara->sprite, rect(33, 356, 24, 31));
        if (chara->anim == 3)
            sfSprite_setTextureRect(chara->sprite, rect(32, 324, 24, 32));
        if (chara->anim == 2)
            sfSprite_setTextureRect(chara->sprite, rect(33, 292, 24, 31));
        if (chara->anim < 4)
            chara->anim += 1;
        else
            chara->anim = 1;
        seconds = 0;
        sfClock_restart(chara->clock);
    }
}

void anim_right(character_t *chara)
{
    float seconds;

    chara->time = sfClock_getElapsedTime(chara->clock);
    seconds = chara->time.microseconds/100000;
    if (chara->vision != chara->old_vision)
        seconds = 1;
    if (seconds >= 1) {
        if (chara->anim == 1)
            sfSprite_setTextureRect(chara->sprite, rect(64, 324, 24, 32));
        if (chara->anim == 4)
            sfSprite_setTextureRect(chara->sprite, rect(65, 356, 24, 31));
        if (chara->anim == 3)
            sfSprite_setTextureRect(chara->sprite, rect(64, 324, 24, 32));
        if (chara->anim == 2)
            sfSprite_setTextureRect(chara->sprite, rect(65, 292, 24, 31));
        if (chara->anim < 4)
            chara->anim += 1;
        else
            chara->anim = 1;
        seconds = 0;
        sfClock_restart(chara->clock);
    }
}

void anim_down(character_t *chara)
{
    float seconds;

    chara->time = sfClock_getElapsedTime(chara->clock);
    seconds = chara->time.microseconds/100000;
    if (chara->vision != chara->old_vision)
        seconds = 1;
    if (seconds >= 1) {
        if (chara->anim == 1)
            sfSprite_setTextureRect(chara->sprite, rect(0, 324, 24, 32));
        if (chara->anim == 4)
            sfSprite_setTextureRect(chara->sprite, rect(1, 356, 24, 31));
        if (chara->anim == 3)
            sfSprite_setTextureRect(chara->sprite, rect(0, 324, 24, 32));
        if (chara->anim == 2)
            sfSprite_setTextureRect(chara->sprite, rect(1, 292, 24, 31));
        if (chara->anim < 4)
            chara->anim += 1;
        else
            chara->anim = 1;
        seconds = 0;
        sfClock_restart(chara->clock);
    }
}

void anim_up(character_t *chara)
{
    float seconds;

    chara->time = sfClock_getElapsedTime(chara->clock);
    seconds = chara->time.microseconds/100000;
    if (chara->vision != chara->old_vision)
        seconds = 1;
    if (seconds >= 1) {
        if (chara->anim == 1)
            sfSprite_setTextureRect(chara->sprite, rect(96, 324, 24, 32));
        if (chara->anim == 4)
            sfSprite_setTextureRect(chara->sprite, rect(97, 356, 24, 31));
        if (chara->anim == 3)
            sfSprite_setTextureRect(chara->sprite, rect(96, 324, 24, 32));
        if (chara->anim == 2)
            sfSprite_setTextureRect(chara->sprite, rect(97, 292, 24, 31));
        if (chara->anim < 4)
            chara->anim += 1;
        else
            chara->anim = 1;
        seconds = 0;
        sfClock_restart(chara->clock);
    }
}