/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** tower_dammage2.c
*/

#include "../include/my.h"

void shoot_tower2(my_defender_t *df)
{
    float range;

    if (df->tower2 == 2) {
        for (int i = 0; i < df->nb_mob; i += 1) {
            range = get_distance(sfSprite_getPosition
            (df->mob.mob_sprite[i].sprite).x, sfSprite_getPosition
            (df->mob.mob_sprite[i].sprite).y, (sfVector2f) {620, 640});
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

void shoot_tower2_lv2(my_defender_t *df)
{
    float range;

    if (df->tower2 == 3) {
        for (int i = 0; i < df->nb_mob; i += 1) {
            range = get_distance(sfSprite_getPosition
            (df->mob.mob_sprite[i].sprite).x, sfSprite_getPosition
            (df->mob.mob_sprite[i].sprite).y, (sfVector2f) {620, 640});
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

void shoot_tower2_lv3(my_defender_t *df)
{
    float range;

    if (df->tower2 == 4) {
        for (int i = 0; i < df->nb_mob; i += 1) {
            range = get_distance(sfSprite_getPosition
            (df->mob.mob_sprite[i].sprite).x, sfSprite_getPosition
            (df->mob.mob_sprite[i].sprite).y, (sfVector2f) {620, 640});
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

void shoot_tower2_lv4(my_defender_t *df)
{
    float range;

    if (df->tower2 == 5) {
        for (int i = 0; i < df->nb_mob; i += 1) {
            range = get_distance(sfSprite_getPosition
            (df->mob.mob_sprite[i].sprite).x, sfSprite_getPosition
            (df->mob.mob_sprite[i].sprite).y, (sfVector2f) {620, 640});
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