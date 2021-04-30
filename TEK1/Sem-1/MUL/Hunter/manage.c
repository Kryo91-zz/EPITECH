/*
** EPITECH PROJECT, 2019
** HUNTER
** File description:
** .c
*/

#include "hunter.h"

void game_event_lvl1(sfEvent event, struct game *game_instance)
{
    const int bird_height = 110;

    if (event.type != sfEvtMouseButtonPressed ||
        event.mouseButton.button != sfMouseLeft ||
        game_instance->step != 5)
        return;
    if (game_instance->bird->order == 0 && event.mouseButton.x <=
        game_instance->bird->pos.x + 110 && event.mouseButton.x >=
        game_instance->bird->pos.x && event.mouseButton.y <=
        game_instance->bird->pos.y + bird_height &&
        event.mouseButton.y >= game_instance->bird->pos.y)
        spawn_new_bird_lvl1(game_instance);
    else if (game_instance->bird->order == 1 && event.mouseButton.x + 110
        <= game_instance->bird->pos.x + 110 && event.mouseButton.x
        + 110 >= game_instance->bird->pos.x && event.mouseButton.y
        <= game_instance->bird->pos.y + bird_height
        && event.mouseButton.y >= game_instance->bird->pos.y)
        spawn_new_bird_lvl1(game_instance);
    else
        bird_miss_lvl1(game_instance);
}

void game_event_lvl2(sfEvent event, struct game *game_instance)
{
    const int bird_height = 110;

    if (event.type != sfEvtMouseButtonPressed ||
        event.mouseButton.button != sfMouseLeft ||
        game_instance->step != 6)
        return;
    if (game_instance->bird->order == 0 && event.mouseButton.x <=
        game_instance->bird->pos.x + 110 && event.mouseButton.x >=
        game_instance->bird->pos.x && event.mouseButton.y <=
        game_instance->bird->pos.y + bird_height &&
        event.mouseButton.y >= game_instance->bird->pos.y)
        spawn_new_bird_lvl2(game_instance);
    else if (game_instance->bird->order == 1 && event.mouseButton.x + 110
        <= game_instance->bird->pos.x + 110 && event.mouseButton.x
        + 110 >= game_instance->bird->pos.x && event.mouseButton.y
        <= game_instance->bird->pos.y + bird_height
        && event.mouseButton.y >= game_instance->bird->pos.y)
        spawn_new_bird_lvl2(game_instance);
    else
        bird_miss_lvl2(game_instance);
}

void game_event_lvl3(sfEvent event, struct game *game_instance)
{
    const int bird_height = 110;

    if (event.type != sfEvtMouseButtonPressed ||
        event.mouseButton.button != sfMouseLeft ||
        game_instance->step != 7)
        return;
    if (game_instance->bird->order == 0 && event.mouseButton.x <=
        game_instance->bird->pos.x + 110 && event.mouseButton.x >=
        game_instance->bird->pos.x && event.mouseButton.y <=
        game_instance->bird->pos.y + bird_height &&
        event.mouseButton.y >= game_instance->bird->pos.y)
        spawn_new_bird_lvl3(game_instance);
    else if (game_instance->bird->order == 1 && event.mouseButton.x + 110
        <= game_instance->bird->pos.x + 110 && event.mouseButton.x
        + 110 >= game_instance->bird->pos.x && event.mouseButton.y
        <= game_instance->bird->pos.y + bird_height
        && event.mouseButton.y >= game_instance->bird->pos.y)
        spawn_new_bird_lvl3(game_instance);
    else
        bird_miss_lvl3(game_instance);
}

void window_draw_lvl2(sfRenderWindow *window, struct game *game_instance,
                        sfEvent event)
{
    if (event.mouseMove.x >= 470 + 130 && event.mouseMove.x <= 790 +
    130 && event.mouseMove.y >= 200 + 250 &&
    event.mouseMove.y <= 588 + 250) {
        sfSprite_setPosition(game_instance->bap, get_position(650, 450));
        sfRenderWindow_drawSprite(window, game_instance->bap, NULL);
    }
    if (event.mouseMove.x >= 1030 + 130 && event.mouseMove.x <= 1280 +
    130 && event.mouseMove.y >= 200 + 250 &&
    event.mouseMove.y <= 588 + 250) {
        sfSprite_setPosition(game_instance->luc2, get_position(1150, 450));
        sfRenderWindow_drawSprite(window, game_instance->luc2, NULL);
    }
    sfSprite_setPosition(game_instance->hard, get_position(550, 250));
    sfRenderWindow_drawSprite(window, game_instance->hard, NULL);
    if (event.mouseMove.x >= 420 + 130 && event.mouseMove.x <= 920 +
    130 && event.mouseMove.y >= 0 + 250 &&
    event.mouseMove.y <= 150 + 250) {
        sfSprite_setPosition(game_instance->hard2, get_position(550, 250));
        sfRenderWindow_drawSprite(window, game_instance->hard2, NULL);
    }
}