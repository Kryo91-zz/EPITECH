/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** norm.c
*/

#include "../include/my.h"

void set_button_texture_in_game(my_defender_t *df)
{
    sfSprite_setTexture(df->background, df->texture_bg, sfTrue);
}

void emplacement_choose_bis2(my_defender_t *df)
{
    if (df->tower1 == 1)
        place_tower1(df);
    if (df->tower2 == 1)
        place_tower2(df);
    if (df->tower3 == 1)
        place_tower3(df);
    if (df->tower4 == 1)
        place_tower4(df);
}

void destroy_all(my_defender_t *df)
{
    sfRenderWindow_destroy(df->window);
    sfMusic_destroy(df->music);
    sfSound_destroy(df->death);
    sfSound_destroy(df->button);
    sfSoundBuffer_destroy(df->button_b);
    sfSoundBuffer_destroy(df->death_b);
}

sfVector2f get_position(int x, int y)
{
    sfVector2f vector;

    vector.x = x;
    vector.y = y;
    return (vector);
}

void my_ceate_bis2(my_defender_t *df)
{
    sfSprite_setTexture(df->pause_retry_s, df->pause_retry_t, sfTrue);
    df->pause_home_s = sfSprite_create();
    df->pause_home_t = sfTexture_createFromFile
    ("ressources/pause_menu_home.png", NULL);
    sfSprite_setTexture(df->pause_home_s, df->pause_home_t, sfTrue);
    set_button_in_game(df);
    sfSprite_setScale(df->s_mob, (sfVector2f){0.2, 0.2});
    sfSprite_setScale(df->s_inventory, (sfVector2f){0.7, 0.7});
    sfSprite_setPosition(df->s_mob, (sfVector2f){-10, 250});
}