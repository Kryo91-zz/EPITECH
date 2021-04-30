/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** mob.c
*/

#include "../include/my.h"

void path1(my_defender_t *df)
{
    for (int i = 0; i < df->nb_mob; i += 1) {
        if (sfSprite_getPosition(df->mob.mob_sprite[i].sprite).x >= -2400 &&
        sfSprite_getPosition(df->mob.mob_sprite[i].sprite).x <= 250) {
            sfSprite_move(df->mob.mob_sprite[i].sprite, (sfVector2f){2, 0});
            if (sfSprite_getPosition(df->mob.mob_sprite[i].sprite).x == 250)
                    df->mob.mob_sprite[i].rect.top += 425;
        }
        if ((sfSprite_getPosition(df->mob.mob_sprite[i].sprite).x >= 250 &&
        sfSprite_getPosition(df->mob.mob_sprite[i].sprite).x <= 330) &&
        sfSprite_getPosition(df->mob.mob_sprite[i].sprite).y <= 810) {
            sfSprite_move(df->mob.mob_sprite[i].sprite, (sfVector2f){0, 2});
            if (sfSprite_getPosition(df->mob.mob_sprite[i].sprite).y == 810)
                df->mob.mob_sprite[i].rect.top -= 425;
        }
        if (sfSprite_getPosition(df->mob.mob_sprite[i].sprite).y >= 810 &&
        sfSprite_getPosition(df->mob.mob_sprite[i].sprite).x <= 750) {
            sfSprite_move(df->mob.mob_sprite[i].sprite, (sfVector2f){2, 0});
            if (sfSprite_getPosition(df->mob.mob_sprite[i].sprite).x == 750)
                df->mob.mob_sprite[i].rect.top = 0;
        }
    }
}

void path2(my_defender_t *df)
{
    for (int i = 0; i < df->nb_mob ; i += 1) {
        if ((sfSprite_getPosition(df->mob.mob_sprite[i].sprite).x >= 750 &&
        sfSprite_getPosition(df->mob.mob_sprite[i].sprite).x <= 790) &&
        sfSprite_getPosition(df->mob.mob_sprite[i].sprite).y >= 125) {
            sfSprite_move(df->mob.mob_sprite[i].sprite, (sfVector2f){0, -2});
            if (sfSprite_getPosition(df->mob.mob_sprite[i].sprite).y == 130)
                df->mob.mob_sprite[i].rect.top = 425;
        }
        if ((sfSprite_getPosition(df->mob.mob_sprite[i].sprite).y == 124 &&
        sfSprite_getPosition(df->mob.mob_sprite[i].sprite).y <= 130) &&
        sfSprite_getPosition(df->mob.mob_sprite[i].sprite).x <= 1350) {
            sfSprite_move(df->mob.mob_sprite[i].sprite, (sfVector2f){2, 0});
            if (sfSprite_getPosition(df->mob.mob_sprite[i].sprite).x == 1350)
                df->mob.mob_sprite[i].rect.top += 425;
        }
        if ((sfSprite_getPosition(df->mob.mob_sprite[i].sprite).x <= 1460 &&
        sfSprite_getPosition(df->mob.mob_sprite[i].sprite).x >= 1350) &&
        sfSprite_getPosition(df->mob.mob_sprite[i].sprite).y <= 385) {
            sfSprite_move(df->mob.mob_sprite[i].sprite, (sfVector2f){0, 2});
            if (sfSprite_getPosition(df->mob.mob_sprite[i].sprite).x == 1460)
                df->mob.mob_sprite[i].rect.top = 1275;
        }
    }
}

void path3(my_defender_t *df)
{
    for (int i = 0; i < df->nb_mob ; i += 1) {
        if ((sfSprite_getPosition(df->mob.mob_sprite[i].sprite).y >= 380 &&
        sfSprite_getPosition(df->mob.mob_sprite[i].sprite).y <= 400) &&
        sfSprite_getPosition(df->mob.mob_sprite[i].sprite).x >= 1010) {
            sfSprite_move(df->mob.mob_sprite[i].sprite, (sfVector2f){-2, 0});
            if (sfSprite_getPosition(df->mob.mob_sprite[i].sprite).y >= 380)
                df->mob.mob_sprite[i].rect.top = 1275;
        }
        if ((sfSprite_getPosition(df->mob.mob_sprite[i].sprite).x >= 1000 &&
        sfSprite_getPosition(df->mob.mob_sprite[i].sprite).x <= 1010 &&
        sfSprite_getPosition(df->mob.mob_sprite[i].sprite).y >= 360) &&
        sfSprite_getPosition(df->mob.mob_sprite[i].sprite).y <= 850) {
            sfSprite_move(df->mob.mob_sprite[i].sprite, (sfVector2f){0, 2});
            if (sfSprite_getPosition(df->mob.mob_sprite[i].sprite).x <= 1010)
                df->mob.mob_sprite[i].rect.top = 850;
        }
        if ((sfSprite_getPosition(df->mob.mob_sprite[i].sprite).y >= 831 &&
        sfSprite_getPosition(df->mob.mob_sprite[i].sprite).y <= 921 &&
        sfSprite_getPosition(df->mob.mob_sprite[i].sprite).x >= 992) &&
        sfSprite_getPosition(df->mob.mob_sprite[i].sprite).x <= 1600)
            sfSprite_move(df->mob.mob_sprite[i].sprite, (sfVector2f){2, 0});
    }
}

void path_handling_map(my_defender_t *df)
{
    path1(df);
    path2(df);
    path3(df);
}

int create_mob(my_defender_t *df)
{
    int x = -380;
    df->nb_mob = 20;
    df->mob.mob_sprite = malloc(sizeof(mob_sprite_t) * (df->nb_mob + 1));
    df->mob.mob = malloc(sizeof(int) * (df->nb_mob + 1));

    for (int i = 0; i < df->nb_mob ; i += 1) {
        df->mob.mob_sprite[i].pos.y = 250;
        df->mob.mob_sprite[i].texture = sfTexture_createFromFile
        ("ressources/top_view.png", NULL);
        df->mob.mob_sprite[i].sprite = sfSprite_create();
        sfSprite_setTexture(df->mob.mob_sprite[i].sprite,
        df->mob.mob_sprite->texture, sfTrue);
        sfSprite_setScale(df->mob.mob_sprite[i].sprite, (sfVector2f){0.2, 0.2});
        df->mob.mob_sprite[i].rect.top = 425;
        df->mob.mob_sprite[i].rect.left = 0;
        df->mob.mob_sprite[i].rect.width = 534;
        df->mob.mob_sprite[i].rect.height = 425;
        df->mob.mob_sprite[i].life = 100;
        sfSprite_setTextureRect(df->mob.mob_sprite[i].sprite,
        df->mob.mob_sprite[i].rect);
        sfSprite_setPosition(df->mob.mob_sprite[i].sprite,
        (sfVector2f){x, df->mob.mob_sprite[i].pos.y});
        x -= 150;
    }
    return (0);
}