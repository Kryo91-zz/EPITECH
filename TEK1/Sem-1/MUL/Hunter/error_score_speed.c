/*
** EPITECH PROJECT, 2019
** HUNTER
** File description:
** .c
*/

#include "hunter.h"

void my_putchar(char c);

void report_error(char *str)
{

    for (int len = 0; str[len]; len++) {
        write(2, str, len);
        close (84);
    }
}

void manage_score(struct game *game_instance)
{
    game_instance->score++;
    game_instance->bird->speed -= 40;
    sfSprite_setPosition(game_instance->bird->sprite,
    game_instance->bird->pos);
    load_game_text(game_instance);
}

void manage_speed(struct game *game_instance)
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