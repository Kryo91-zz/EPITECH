/*
** EPITECH PROJECT, 2019
** my_hunter
** File description:
** my_create.c
*/

#include "../include/my.h"

void my_create_sprite_music(my_defender_t *df)
{
    df->my_life = 3;
    df->my_score = 00;
    df->music = sfMusic_createFromFile("ressources/saxguy.ogg");
    df->background = sfSprite_create();
    df->texture_bg = sfTexture_createFromFile("ressources/map.png", NULL);
    df->s_mob = sfSprite_create();
    df->t_mob = sfTexture_createFromFile("ressources/mob.jpg", NULL);
    df->button = sfSound_create();
    df->button_b = sfSoundBuffer_createFromFile("ressources/button.wav");
    sfSound_setBuffer(df->button, df->button_b);
    df->death = sfSound_create();
    df->death_b = sfSoundBuffer_createFromFile("ressources/death.wav");
    sfSound_setBuffer(df->death, df->death_b);
    sfSprite_setTexture(df->s_mob, df->t_mob, sfTrue);
    sfSprite_setScale(df->background, (sfVector2f){0.8, 1});
    df->s_inventory = sfSprite_create();
    df->t_inventory = sfTexture_createFromFile
    ("ressources/inventory.png", NULL);
    sfSprite_setTexture(df->s_inventory, df->t_inventory, sfTrue);
    create_bis(df);
}

void my_create_window(my_defender_t *df)
{
    df->video_mode.width = 1500;
    df->video_mode.height = 1000;
    df->video_mode.bitsPerPixel = 32;
}

void my_create_rect(my_defender_t *df)
{
    df->clock = sfClock_create();
    df->money_clock = sfClock_create();
    df->t1_clock = sfClock_create();
    df->x_speed = 0.4;
    df->x_speed2 = 5.0;
    df->rect_tower.rect.top = 0;
    df->rect_tower.rect.left = 0;
    df->rect_tower.rect.width = 200;
    df->rect_tower.rect.height = 400;
    create_rect_bis(df);

}

void sold(my_defender_t *df)
{
    df->time2 = sfClock_getElapsedTime(df->money_clock);
    df->seconde2 = df->time2.microseconds / 1000000.0;
    if (df->seconde2 > 2) {
        df->money += 100;
        sfClock_restart(df->money_clock);
    }
}

void create(my_defender_t *df)
{
    df->bo = 0;
    my_create_rect(df);
    my_create_window(df);
    my_create_sprite_music(df);
    create_mob(df);
    set_button_texture_in_game(df);
    df->window = sfRenderWindow_create(df->video_mode,
        "my_defender", sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(df->window, 60);
}