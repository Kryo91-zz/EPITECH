/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** my_create2.c
*/

#include "../include/my.h"

void set_pos_kill(my_defender_t *df, int i)
{
    int boole = 0;
    if (df->mob.mob_sprite[i].life <= 0)
        boole = 1;
    if (boole == 1) {
        sfSound_play(df->death);
        sfSprite_setPosition(df->mob.mob_sprite[i].sprite,
        (sfVector2f) {40000, 0});
        df->mob.mob_sprite[i].life -= 1;
        df->mob.mob_sprite[i].life = 1;
        boole = 0;
    }
}

void shoot_tower1(my_defender_t *df)
{
    float range;

    if (df->tower1 == 2) {
        for (int i = 0; i < df->nb_mob; i += 1) {
            range = get_distance(sfSprite_getPosition
            (df->mob.mob_sprite[i].sprite).x, sfSprite_getPosition
            (df->mob.mob_sprite[i].sprite).y, (sfVector2f) {380, 640});
            if (range < 200) {
                df->t1_time = sfClock_getElapsedTime(df->t1_clock);
                df->t1_seconde = df->t1_time.microseconds / 1000000.0;
                if (df->t1_seconde > 1.2) {
                    df->mob.mob_sprite[i].life -= 10;
                    sfClock_restart(df->t1_clock);
                    if (df->mob.mob_sprite[i].life <= 0)
                        df->my_score += 1;
                    break;
                }
            }
            set_pos_kill(df, i);
        }
    }
}

void shoot_tower1_lv2(my_defender_t *df)
{
    float range;

    if (df->tower1 == 3) {
        for (int i = 0; i < df->nb_mob; i += 1) {
            range = get_distance(sfSprite_getPosition
            (df->mob.mob_sprite[i].sprite).x, sfSprite_getPosition
            (df->mob.mob_sprite[i].sprite).y, (sfVector2f) {380, 640});
            if (range < 250) {
                df->t1_time = sfClock_getElapsedTime(df->t1_clock);
                df->t1_seconde = df->t1_time.microseconds / 1000000.0;
                if (df->t1_seconde > 0.9) {
                    df->mob.mob_sprite[i].life -= 10;
                    sfClock_restart(df->t1_clock);
                    if (df->mob.mob_sprite[i].life <= 0)
                        df->my_score += 1;
                    break;
                }
            }
            set_pos_kill(df, i);
        }
    }
}

void shoot_tower1_lv3(my_defender_t *df)
{
    float range;

    if (df->tower1 == 4) {
        for (int i = 0; i < df->nb_mob; i += 1) {
            range = get_distance(sfSprite_getPosition
            (df->mob.mob_sprite[i].sprite).x, sfSprite_getPosition
            (df->mob.mob_sprite[i].sprite).y, (sfVector2f) {380, 640});
            if (range < 250) {
                df->t1_time = sfClock_getElapsedTime(df->t1_clock);
                df->t1_seconde = df->t1_time.microseconds / 1000000.0;
                if (df->t1_seconde > 0.7) {
                    df->mob.mob_sprite[i].life -= 10;
                    sfClock_restart(df->t1_clock);
                    if (df->mob.mob_sprite[i].life <= 0)
                        df->my_score += 1;
                    break;
                }
            }
            set_pos_kill(df, i);
        }
    }
}

void shoot_tower1_lv4(my_defender_t *df)
{
    float range;

    if (df->tower1 == 5) {
        for (int i = 0; i < df->nb_mob; i += 1) {
            range = get_distance(sfSprite_getPosition
            (df->mob.mob_sprite[i].sprite).x, sfSprite_getPosition
            (df->mob.mob_sprite[i].sprite).y, (sfVector2f) {380, 640});
            if (range < 250) {
                df->t1_time = sfClock_getElapsedTime(df->t1_clock);
                df->t1_seconde = df->t1_time.microseconds / 1000000.0;
                if (df->t1_seconde > 0.4) {
                    df->mob.mob_sprite[i].life -= 20;
                    sfClock_restart(df->t1_clock);
                    if (df->mob.mob_sprite[i].life <= 0)
                        df->my_score += 1;
                    break;
                }
            }
            set_pos_kill(df, i);
        }
    }
}