/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** button_in_game.c
*/

#include "../include/my.h"

void set_button_in_menu(my_defender_t *df)
{
    sfSprite_setScale(df->menu.s_logo, (sfVector2f){0.7, 0.7});
    sfSprite_setScale(df->menu.s_menu, (sfVector2f){0.6, 0.6});
    sfSprite_setPosition(df->menu.s_logo, (sfVector2f){440, -10});
    sfSprite_setPosition(df->s_p, (sfVector2f){1125, 10});
    sfSprite_setPosition(df->s_how, (sfVector2f){9, 876});
    df->menu.s_play_button = sfSprite_create();
    df->menu.s_play_button2 = sfSprite_create();
    df->menu.texture_play_button = sfTexture_createFromFile
    ("ressources/play.png", NULL);
    df->menu.texture_play_button2 = sfTexture_createFromFile
    ("ressources/play2.png", NULL);
    df->menu.s_exit_button = sfSprite_create();
    df->menu.s_exit_button2 = sfSprite_create();
    df->menu.texture_exit_button = sfTexture_createFromFile
    ("ressources/leave.png", NULL);
    df->menu.texture_exit_button2 = sfTexture_createFromFile
    ("ressources/leave2.png", NULL);
}

void set_button_texture_in_menu(my_defender_t *df)
{
    sfSprite_setTexture(df->menu.s_play_button,
    df->menu.texture_play_button, sfTrue);
    sfSprite_setTexture(df->menu.s_play_button2,
    df->menu.texture_play_button2, sfTrue);
    sfSprite_setPosition(df->menu.s_play_button, get_position(570, 400));
    sfSprite_setPosition(df->menu.s_play_button2, get_position(570, 400));
    sfSprite_setTexture(df->menu.s_exit_button,
    df->menu.texture_exit_button, sfTrue);
    sfSprite_setTexture(df->menu.s_exit_button2,
    df->menu.texture_exit_button2, sfTrue);
    sfSprite_setPosition(df->menu.s_exit_button, get_position(0, 0));
    sfSprite_setPosition(df->menu.s_exit_button2, get_position(0, 0));
    sfSprite_setScale(df->menu.s_exit_button, (sfVector2f){0.4, 0.4});
    sfSprite_setScale(df->menu.s_exit_button2, (sfVector2f){0.4, 0.4});
}

void button_color_change_in_menu(my_defender_t *df)
{
    if (df->event.mouseMove.x >= 570 && df->event.mouseMove.x <= 900
    && df->event.mouseMove.y >= 400 && df->event.mouseMove.y <= 600) {
        sfRenderWindow_drawSprite(df->window, df->menu.s_play_button2, NULL);
    } else {
        sfSound_play(df->button);
        sfRenderWindow_drawSprite(df->window, df->menu.s_play_button, NULL);
    }
    if (df->event.mouseMove.x >= 0 && df->event.mouseMove.x <= 87
    && df->event.mouseMove.y >= 0 && df->event.mouseMove.y <= 85) {
        sfRenderWindow_drawSprite(df->window, df->menu.s_exit_button2, NULL);
        event(df);
    } else
        sfRenderWindow_drawSprite(df->window, df->menu.s_exit_button, NULL);
}

void set_button_in_game(my_defender_t *df)
{
    df->s_tower = sfSprite_create();
    df->t_tower = sfTexture_createFromFile("ressources/tower1.png", NULL);
    df->s_tower2 = sfSprite_create();
    df->s_tower3 = sfSprite_create();
    df->s_tower4 = sfSprite_create();
    sfSprite_setScale(df->s_tower, (sfVector2f){0.5, 0.5});
    sfSprite_setScale(df->s_tower2, (sfVector2f){0.5, 0.5});
    sfSprite_setScale(df->s_tower3, (sfVector2f){0.5, 0.5});
    sfSprite_setScale(df->s_tower4, (sfVector2f){0.5, 0.5});
    sfSprite_setTexture(df->s_tower, df->t_tower, sfTrue);
    sfSprite_setTexture(df->s_tower2, df->t_tower, sfTrue);
    sfSprite_setTexture(df->s_tower3, df->t_tower, sfTrue);
    sfSprite_setTexture(df->s_tower4, df->t_tower, sfTrue);
}

void button_color_change_in_game(my_defender_t *df)
{
    if (df->event.mouseMove.x <= 86 && df->event.mouseMove.y <= 86) {
        sfRenderWindow_drawSprite(df->window, df->menu.s_exit_button2, NULL);
        event(df);
    } else
        sfRenderWindow_drawSprite(df->window, df->menu.s_exit_button, NULL);
}