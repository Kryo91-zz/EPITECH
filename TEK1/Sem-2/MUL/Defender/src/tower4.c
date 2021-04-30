/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** tower4.c
*/

#include "../include/my.h"

void place_tower4_bis(my_defender_t *df)
{
    if (df->mouse_pos.x >= 1230 && df->mouse_pos.x <= 1280 &&
    df->mouse_pos.y >= 515 && df->mouse_pos.y <= 595) {
        if (df->money >= 150) {
            df->rect_tower4.rect.left = 270;
            df->tower4 = 2;
            df->money = df->money - 150;
        }
    }
    if (df->mouse_pos.x >= 1281 && df->mouse_pos.x <= 1350 &&
    df->mouse_pos.y >= 515 && df->mouse_pos.y <= 595) {
        if (df->money >= 250) {
            df->rect_tower4.rect.left = 700;
            df->tower4 = 3;
            df->money = df->money - 250;
        }
    }
}

void place_tower4(my_defender_t *df)
{
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        place_tower4_bis(df);
        if (df->mouse_pos.x >= 1351 && df->mouse_pos.x <= 1420 &&
        df->mouse_pos.y >= 515 && df->mouse_pos.y <= 595) {
            if (df->money >= 400) {
                df->rect_tower4.rect.left = 900;
                df->tower4 = 4;
                df->money = df->money - 400;
            }
        }
        if (df->mouse_pos.x >= 1421 && df->mouse_pos.x <= 1490 &&
        df->mouse_pos.y >= 515 && df->mouse_pos.y <= 595) {
            if (df->money >= 800) {
                df->rect_tower4.rect.left = 500;
                df->tower4 = 5;
                df->money = df->money - 800;
            }
        }
    }
}