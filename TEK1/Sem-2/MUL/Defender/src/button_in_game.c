/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** button_in_game.c
*/

#include "../include/my.h"

void place_tower1_bis(my_defender_t *df)
{
    if (df->mouse_pos.x >= 1230 && df->mouse_pos.x <= 1280 &&
    df->mouse_pos.y >= 515 && df->mouse_pos.y <= 595) {
        if (df->money >= 150) {
            df->rect_tower.rect.left = 270;
            df->tower1 = 2;
        }
    }
    if (df->mouse_pos.x >= 1281 && df->mouse_pos.x <= 1350 &&
    df->mouse_pos.y >= 515 && df->mouse_pos.y <= 595) {
        if (df->money >= 250) {
            df->rect_tower.rect.left = 700;
            df->tower1 = 3;
        }
    }
}

void place_tower1(my_defender_t *df)
{
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        place_tower1_bis(df);
        if (df->mouse_pos.x >= 1351 && df->mouse_pos.x <= 1420 &&
        df->mouse_pos.y >= 515 && df->mouse_pos.y <= 595) {
            if (df->money >= 400) {
                df->rect_tower.rect.left = 900;
                df->tower1 = 4;
            }
        }
        if (df->mouse_pos.x >= 1421 && df->mouse_pos.x <= 1490 &&
        df->mouse_pos.y >= 515 && df->mouse_pos.y <= 595) {
            if (df->money >= 800) {
                df->rect_tower.rect.left = 500;
                df->tower1 = 5;
            }
        }
    }
}

void emplacement_choose_bis(my_defender_t *df)
{
    if (df->mouse_pos.x >= 388 && df->mouse_pos.x <= 482 &&
    df->mouse_pos.y >= 645 && df->mouse_pos.y <= 742)
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            if (df->tower1 == 0)
                df->rect_tower.rect.left = 1100;
            df->tower1 = 1;
        }
    if (df->mouse_pos.x >= 620 && df->mouse_pos.x <= 722 &&
    df->mouse_pos.y >= 645 && df->mouse_pos.y <= 742)
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            if (df->tower2 == 1)
                df->rect_tower2.rect.left = 1100;
            df->tower2 = 1;
        }
}

void emplacement_choose(my_defender_t *df)
{
    emplacement_choose_bis(df);
    if (df->mouse_pos.x >= 883 && df->mouse_pos.x <= 985 &&
    df->mouse_pos.y >= 245 && df->mouse_pos.y <= 348)
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            if (df->tower3 == 1)
                df->rect_tower3.rect.left = 1100;
            df->tower3 = 1;
        }
    if (df->mouse_pos.x >= 1138 && df->mouse_pos.x <= 1232 &&
    df->mouse_pos.y >= 672 && df->mouse_pos.y <= 770)
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            if (df->tower4 == 1)
                df->rect_tower4.rect.left = 1100;
            df->tower4 = 1;
        }
    emplacement_choose_bis2(df);
}

void inventory_opener(my_defender_t *df)
{
    df->mouse_pos = sfMouse_getPositionRenderWindow(df->window);
    if (df->mouse_pos.x >= 1445 && df->mouse_pos.x <= 1500 &&
    df->mouse_pos.y >= 510 && df->mouse_pos.y <= 595)
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            df->bo = 1;
        }
    if (df->bo == 1) {
        sfSprite_setPosition(df->s_inventory, (sfVector2f){1150, 500});
        emplacement_choose(df);
    }
    if (df->mouse_pos.x >= 1165 && df->mouse_pos.x <= 1217 &&
    df->mouse_pos.y >= 517 && df->mouse_pos.y <= 595)
                if (sfMouse_isButtonPressed(sfMouseLeft))
                    df->bo = 0;
    if (df->bo == 0)
        sfSprite_setPosition(df->s_inventory, (sfVector2f){1430, 500});
}