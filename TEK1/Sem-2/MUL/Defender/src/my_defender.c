/*
** EPITECH PROJECT, 2019
** my_hunter-master
** File description:
** my_hunter.c
*/

#include "../include/my.h"

void shoot(my_defender_t *df)
{
    shoot_tower1(df);
    shoot_tower1_lv2(df);
    shoot_tower1_lv3(df);
    shoot_tower1_lv4(df);
    shoot_tower2(df);
    shoot_tower2_lv2(df);
    shoot_tower2_lv3(df);
    shoot_tower2_lv4(df);
    shoot_tower3(df);
    shoot_tower3_lv2(df);
    shoot_tower3_lv3(df);
    shoot_tower3_lv4(df);
    shoot_tower4(df);
    shoot_tower4_lv2(df);
    shoot_tower4_lv3(df);
    shoot_tower4_lv4(df);
}

void draw_boucle(my_defender_t *df)
{
    for (int i = 0; i < df->nb_mob; i += 1) {
        sfRenderWindow_drawSprite(df->window, df->mob.mob_sprite[i].sprite, NULL);
        if (df->pause != 1) {
            clock1(df);
            sold(df);
        }
        if (sfSprite_getPosition(df->mob.mob_sprite[i].sprite).x == 1492
        && sfSprite_getPosition(df->mob.mob_sprite[i].sprite).y >= 800)
            df->my_life -= 1;
        sfSprite_setTextureRect(df->mob.mob_sprite[i].sprite, df->mob.mob_sprite[i].rect);
    }
    inventory_opener(df);
    inventory_draw(df);
    button_color_change_in_game(df);
}

void display(my_defender_t *df)
{
    sfText *text = sfText_create();
    sfText *money = sfText_create();
    sfText *mylife = sfText_create();
    sfText *score = sfText_create();
    sfFont *font = sfFont_createFromFile("ressources/BebasNeue.otf");
    df->x = 0;
    df->y = 0;
    sfSprite_setPosition(df->s_inventory, (sfVector2f){1430, 500});
    sfRenderWindow_drawSprite(df->window, df->background, NULL);
    sfRenderWindow_drawSprite(df->window, df->menu.s_exit_button, NULL);
    draw_boucle(df);
    if (df->pause != 1)
        path_handling_map(df);
    if (df->pause == 1) {
        sfRenderWindow_drawSprite(df->window, df->s_pause, NULL);
        button_interact(df);
    }
    sfText_setPosition(text, get_position(450, 900));
    sfText_setString(text, \
    "score :              Money :                 Life :");
    sfText_setPosition(money, get_position(850, 900));
    sfText_setString(money, \
    my_score(df->money));
    sfText_setPosition(mylife, get_position(1050, 900));
    sfText_setString(mylife, \
    my_score(df->my_life));
    sfText_setPosition(score, get_position(625, 900));
    sfText_setString(score, \
    my_score(df->my_score));
    sfText_setFont(text, font);
    sfText_setColor(text, sfRed);
    sfText_setCharacterSize(text, 50);
    sfRenderWindow_drawText(df->window, text, NULL);
    sfText_setFont(money, font);
    sfText_setColor(money, sfBlack);
    sfText_setCharacterSize(money, 50);
    sfRenderWindow_drawText(df->window, money, NULL);
    sfText_setFont(mylife, font);
    sfText_setColor(mylife, sfBlack);
    sfText_setCharacterSize(mylife, 50);
    sfRenderWindow_drawText(df->window, mylife, NULL);
    sfText_setFont(score, font);
    sfText_setColor(score, sfBlack);
    sfText_setCharacterSize(score, 50);
    sfRenderWindow_drawText(df->window, score, NULL);
    shoot(df);
    if (df->my_life == 0)
        sfRenderWindow_destroy(df->window);
    sfRenderWindow_display(df->window);
}

void my_event(my_defender_t *df)
{
    while (sfRenderWindow_pollEvent(df->window, &df->event))
        if (df->event.type == sfEvtClosed)
            df->quit = 1;
    if (df->event.type == sfEvtClosed)
        sfRenderWindow_close(df->window);
    exit_button_in_game(df);
}

void exit_button_in_game(my_defender_t *df)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(df->window);

    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        click(df, mouse.x, mouse.y);
        if (mouse.x >= 0 && mouse.x <= 86 && mouse.y >= 0 && mouse.y <= 86)
            sfRenderWindow_destroy(df->window);
    }
}