/*
** EPITECH PROJECT, 2019
** HUNTER
** File description:
** .c
*/

#include "hunter.h"

void make_bird_move(struct game *game_instance)
{
    int bird_height = 110;
    int screen_width = 1535;

    if (game_instance->bird->pos.x > screen_width) {
        game_instance->bird->pos.y = bird_height * rand_line_height();
        game_instance->bird->pos.x = screen_width;
        game_instance->bird->order = 1;
    }
    else if (game_instance->bird->pos.x < 0) {
        sfSprite_setScale(game_instance->bird->sprite,
        get_position(1, 1));
        game_instance->bird->pos.y = bird_height * rand_line_height();
        game_instance->bird->pos.x = 0;
        game_instance->bird->order = 0;
    }
    manage_speed(game_instance);
    sfSprite_setPosition(game_instance->bird->sprite, get_position(
        game_instance->bird->pos.x, game_instance->bird->pos.y));
    if (game_instance->bird->order == 1)
        sfSprite_setScale(game_instance->bird->sprite, get_position(-1, 1));
}

sfIntRect get_rect_bird_skin(struct game *game_instance)
{
    int bird_width = 331;
    int bird_height = 110;

    if (game_instance->bird->skin_index > 3)
        game_instance->bird->skin_index = 1;
    if (game_instance->bird->skin_index <= 1)
        return (get_rect(0, 0, bird_width / 3, bird_height));
    else if (game_instance->bird->skin_index == 2)
        return (get_rect(0, bird_width / 3, bird_width / 3,
        bird_height));
    else
        return (get_rect(0, bird_width / 3 * 2, bird_width / 3,
        bird_height));
}

void spawn_new_bird(struct game *game_instance)
{
    int bird_height = 110;
    int y = game_instance->bird->pos.y;

    if (rand_line_height() % 2 == 0) {
        sfSprite_setScale(game_instance->bird->sprite,
        get_position(1, 1));
        game_instance->bird->order = 0;
        game_instance->bird->pos = get_position(0, y);
        game_instance->bird->pos.y = bird_height * rand_line_height();
    } else {
        sfSprite_setScale(game_instance->bird->sprite,
        get_position(-1, 1));
        game_instance->bird->order = 1;
        game_instance->bird->pos = get_position(1536, y);
        game_instance->bird->pos.y = bird_height * rand_line_height();
    }
    manage_score(game_instance);
}

int rand_line_height(void)
{
    srand(time(NULL));
    int nbgen = rand()%7+1;
    return (nbgen);
}
