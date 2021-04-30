/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** menu.c
*/

#include "../include/my.h"

void set(my_defender_t *df)
{
    df->menu.s_logo = sfSprite_create();
    df->menu.texture_logo = sfTexture_createFromFile
    ("ressources/logo.png", NULL);
    df->menu.s_menu = sfSprite_create();
    df->menu.texture_menu = sfTexture_createFromFile
    ("ressources/background_menu.jpg", NULL);
    df->s_how = sfSprite_create();
    df->t_how = sfTexture_createFromFile("ressources/how.png", NULL);
    df->s_p = sfSprite_create();
    df->t_p = sfTexture_createFromFile("ressources/parchemin.png", NULL);
    sfSprite_setTexture(df->s_p, df->t_p, sfTrue);
    sfSprite_setTexture(df->s_how, df->t_how, sfTrue);
    sfSprite_setScale(df->s_how, (sfVector2f){0.5, 0.5});
    sfSprite_setTexture(df->menu.s_logo, df->menu.texture_logo, sfTrue);
    sfSprite_setTexture(df->menu.s_menu, df->menu.texture_menu, sfTrue);
    set_button_in_menu(df);
    set_button_texture_in_menu(df);
}

int click(my_defender_t *df, int x, int y)
{
    if (x >= 570 && x <= 900 && y >= 400 && y <= 600)
        return (0);
    if (x >= 0 && x <= 86 && y >= 0 && y <= 86){
        df->quit = 1;
        return (0);
    }
    if (x >= 9 && x <= 397 && y >= 876 && y <= 952)
        df->bole = 1;
    return (1);
}

int event(my_defender_t *df)
{
    int returnn = 1;
    sfVector2i mouse = sfMouse_getPositionRenderWindow(df->window);

    while (sfRenderWindow_pollEvent(df->window, &df->event))
        if (df->event.type == sfEvtClosed){
            df->quit = 1;
            return (0);
        }
    if (sfMouse_isButtonPressed(sfMouseLeft))
        returnn = click(df, mouse.x, mouse.y);
    return (returnn);
}

void destroy(my_defender_t *df)
{
    sfSprite_destroy(df->menu.s_menu);
    sfTexture_destroy(df->menu.texture_menu);
}

void menu(my_defender_t *df)
{
    int boucle = 1;
    set(df);
    while (boucle) {
        if (sfKeyboard_isKeyPressed(sfKeyEscape))
            break;
        boucle = event(df);
        sfRenderWindow_drawSprite(df->window, df->menu.s_menu, NULL);
        sfRenderWindow_drawSprite(df->window, df->menu.s_logo, NULL);
        sfRenderWindow_drawSprite(df->window, df->s_how, NULL);
        if (df->bole == 1)
            sfRenderWindow_drawSprite(df->window, df->s_p, NULL);
        button_color_change_in_menu(df);
        sfRenderWindow_display(df->window);
    }
    destroy(df);
}