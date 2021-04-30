/*
** EPITECH PROJECT, 2019
** HUNTER
** File description:
** .c
*/

#include "hunter.h"

int description_and_error(int ac, char **av)
{
    if (ac > 2)
        return (1);
    if (ac == 2 && av[1][0] != '-' && av[1][1] != 'h')
        return (1);
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h') {
        write(1, "Look the information in game", 29);
        return (1);
    }
    return (0);
}

void window_draw_gamelvl1(sfRenderWindow *window, struct game *game_instance)
{
    if (game_instance->step != 5)
        return;
    sfRenderWindow_setMouseCursorVisible(window, sfFalse);
    sfSprite_setPosition(game_instance->aim, game_instance->mouse);
    make_bird_move_lvl1(game_instance);
    sfRenderWindow_drawSprite(window, game_instance->sprite, NULL);
    sfRenderWindow_drawSprite(window, game_instance->bird->sprite, NULL);
    sfRenderWindow_drawSprite(window, game_instance->aim, NULL);
    sfRenderWindow_drawText(window, game_instance->score_field, NULL);
    sfRenderWindow_drawText(window, game_instance->score_text, NULL);
    sfRenderWindow_drawText(window, game_instance->miss_text, NULL);
    sfRenderWindow_drawText(window, game_instance->speed_text, NULL);
}

void window_draw_gamelvl2(sfRenderWindow *window, struct game *game_instance)
{
    if (game_instance->step != 6)
        return;
    sfRenderWindow_setMouseCursorVisible(window, sfFalse);
    sfSprite_setPosition(game_instance->aim, game_instance->mouse);
    make_bird_move(game_instance);
    sfRenderWindow_drawSprite(window, game_instance->sprite, NULL);
    sfRenderWindow_drawSprite(window, game_instance->bird->sprite, NULL);
    sfRenderWindow_drawSprite(window, game_instance->aim, NULL);
    sfRenderWindow_drawText(window, game_instance->score_field, NULL);
    sfRenderWindow_drawText(window, game_instance->score_text, NULL);
    sfRenderWindow_drawText(window, game_instance->miss_text, NULL);
    sfRenderWindow_drawText(window, game_instance->speed_text, NULL);
}

void window_draw_gamelvl3(sfRenderWindow *window, struct game *game_instance)
{
    if (game_instance->step != 7)
        return;
    sfRenderWindow_setMouseCursorVisible(window, sfFalse);
    sfSprite_setPosition(game_instance->aim, game_instance->mouse);
    make_bird_move(game_instance);
    sfRenderWindow_drawSprite(window, game_instance->sprite, NULL);
    sfRenderWindow_drawSprite(window, game_instance->bird->sprite, NULL);
    sfRenderWindow_drawSprite(window, game_instance->aim, NULL);
    sfRenderWindow_drawText(window, game_instance->score_field, NULL);
    sfRenderWindow_drawText(window, game_instance->score_text, NULL);
    sfRenderWindow_drawText(window, game_instance->miss_text, NULL);
    sfRenderWindow_drawText(window, game_instance->speed_text, NULL);
}