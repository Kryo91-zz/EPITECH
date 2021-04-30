/*
** EPITECH PROJECT, 2019
** HUNTER
** File description:
** .c
*/

#include "hunter.h"

void make_bird_move_lvl1(struct game *game_instance)
{
    int bird_height2 = 110;
    int screen_width = 1535;

    if (game_instance->bird->pos.x > screen_width) {
        game_instance->bird->pos.y = bird_height2 * rand_line_height();
        game_instance->bird->pos.x = screen_width;
        game_instance->bird->order = 1;
    }
    else if (game_instance->bird->pos.x < 0) {
        sfSprite_setScale(game_instance->bird->sprite,
        get_position(1, 1));
        game_instance->bird->pos.y = bird_height2 * rand_line_height();
        game_instance->bird->pos.x = 0;
        game_instance->bird->order = 0;
    }
    manage_speed(game_instance);
    sfSprite_setPosition(game_instance->bird->sprite, get_position(
        game_instance->bird->pos.x, game_instance->bird->pos.y));
    if (game_instance->bird->order == 1)
        sfSprite_setScale(game_instance->bird->sprite, get_position(-1, 1));
}

void spawn_new_bird_lvl1(struct game *game_instance)
{
    int bird_height2 = 110;
    int y = game_instance->bird->pos.y;

    if (rand_line_height() % 2 == 0) {
        sfSprite_setScale(game_instance->bird->sprite,
        get_position(1, 1));
        game_instance->bird->order = 0;
        game_instance->bird->pos = get_position(0, y);
        game_instance->bird->pos.y = bird_height2 * rand_line_height();
    } else {
        sfSprite_setScale(game_instance->bird->sprite,
        get_position(-1, 1));
        game_instance->bird->order = 1;
        game_instance->bird->pos = get_position(1536, y);
        game_instance->bird->pos.y = bird_height2 * rand_line_height();
    }
    manage_score_lvl1(game_instance);
}

void bird_miss_lvl1(struct game *game_instance)
{
    game_instance->miss++;
    load_game_text(game_instance);
    if (game_instance->miss == 3) {
        if (game_instance->score > game_instance->best_score) {
            game_instance->best_score = game_instance->score;
            sfText_setString(game_instance->best_score_field,
            my_score(game_instance->best_score));
        }
        game_instance->step = 2;
    }
}

void manage_speed_lvl1(struct game *game_instance)
{
    if ((game_instance->bird->speed < -200 &&
    game_instance->bird->move_length < 5) ||
    (game_instance->bird->speed < -100 &&
    game_instance->bird->move_length < 4) ||
    (game_instance->bird->speed < -30 &&
    game_instance->bird->move_length < 3))
        game_instance->bird->move_length++;
    if (game_instance->bird->order == 0)
        game_instance->bird->pos.x += game_instance->bird->move_length;
    else
        game_instance->bird->pos.x -= game_instance->bird->move_length;
}

void manage_score_lvl1(struct game *game_instance)
{
    game_instance->score++;
    game_instance->bird->speed -= 5;
    sfSprite_setPosition(game_instance->bird->sprite,
    game_instance->bird->pos);
    load_game_text(game_instance);
}