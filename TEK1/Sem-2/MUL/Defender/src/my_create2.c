/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** my_create2.c
*/

#include "../include/my.h"

void clock1(my_defender_t *df)
{
    df->time = sfClock_getElapsedTime(df->clock);
    df->seconde = df->time.microseconds / 1000000.0;
    if (df->seconde > df->x_speed) {
        move_rect(df, 110, 220);
        sfClock_restart(df->clock);
    }
}

void create_bis(my_defender_t *df)
{
    df->tower1 = 0;
    df->money = 0;
    df->pause = 0;
    df->s_pause = sfSprite_create();
    df->t_pause = sfTexture_createFromFile("ressources/pause_menu.png", NULL);
    sfSprite_setTexture(df->s_pause, df->t_pause, sfTrue);
    df->pause_back_s = sfSprite_create();
    df->pause_back_t = sfTexture_createFromFile
    ("ressources/pause_menu_back.png", NULL);
    sfSprite_setTexture(df->pause_back_s, df->pause_back_t, sfTrue);
    df->pause_retry_s = sfSprite_create();
    df->pause_retry_t = sfTexture_createFromFile
    ("ressources/pause_menu_retry.png", NULL);
    my_ceate_bis2(df);
}

void create_rect_bis(my_defender_t *df)
{
    df->rect_tower2.rect.top = 0;
    df->rect_tower2.rect.left = 0;
    df->rect_tower2.rect.width = 200;
    df->rect_tower2.rect.height = 400;
    df->rect_tower3.rect.top = 0;
    df->rect_tower3.rect.left = 0;
    df->rect_tower3.rect.width = 200;
    df->rect_tower3.rect.height = 400;
    df->rect_tower4.rect.top = 0;
    df->rect_tower4.rect.left = 0;
    df->rect_tower4.rect.width = 200;
    df->rect_tower4.rect.height = 400;
}

int number_digits(int nbr)
{
    int n = 1;
    int po = 10;

    if (nbr < 0)
        nbr = -nbr;
    while (nbr >= po) {
        n++;
        if (po > 214748364)
            break;
        po *= 10;
    }
    return (n);
}

char *my_score(int nbr)
{
    int len = number_digits(nbr);
    char *result;

    result = malloc(sizeof(char) * len);
    if (result == NULL)
        report_error("Fatal error: malloc failed.");
    result[len] = '\0';
    while (len--) {
        result[len] = nbr % 10 + '0';
        nbr /= 10;
    }
    return (result);
}