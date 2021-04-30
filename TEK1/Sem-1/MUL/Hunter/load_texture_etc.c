/*
** EPITECH PROJECT, 2019
** HUNTER
** File description:
** .c
*/

#include "hunter.h"

void load_other(struct game *game_instance)
{
    load_sprites(game_instance);
    load_sprites2(game_instance);
    load_sprites3(game_instance);
    load_main_text(game_instance);
    load_game_text(game_instance);
    load_end_text(game_instance);
}

void load_main_text(struct game *game_instance)
{
    game_instance->score_field = sfText_create();
    sfText_setPosition(game_instance->score_field,
    get_position(200, 800));
    sfText_setString(game_instance->score_field,
    "SCORE :            MISS :             SPEED :");
    sfText_setFont(game_instance->score_field, game_instance->font_debas);
    sfText_setCharacterSize(game_instance->score_field, 50);
    game_instance->score_text = sfText_create();
    game_instance->miss_text = sfText_create();
    game_instance->speed_text = sfText_create();
}

void load_game_text(struct game *game_instance)
{
    int speed = game_instance->bird->speed - 80;

    if (speed < 0)
        speed *= -1;
    sfText_setString(game_instance->score_text,
    my_score(game_instance->score));
    sfText_setFont(game_instance->score_text, game_instance->font_debas);
    sfText_setCharacterSize(game_instance->score_text, 50);
    sfText_setPosition(game_instance->score_text, get_position(345, 800));
    sfText_setString(game_instance->miss_text,
    my_score(game_instance->miss));
    sfText_setFont(game_instance->miss_text, game_instance->font_debas);
    sfText_setCharacterSize(game_instance->miss_text, 50);
    sfText_setPosition(game_instance->miss_text, get_position(545, 800));
    sfText_setString(game_instance->speed_text, my_score(speed));
    sfText_setFont(game_instance->speed_text, game_instance->font_debas);
    sfText_setCharacterSize(game_instance->speed_text, 50);
    sfText_setPosition(game_instance->speed_text, get_position(750, 800));
}

void load_end_text(struct game *game_instance)
{
    game_instance->best_score_text = sfText_create();
    sfText_setString(game_instance->best_score_text, "BEST SCORE :");
    sfText_setFont(game_instance->best_score_text,
    game_instance->font_debas);
    sfText_setCharacterSize(game_instance->best_score_text, 50);
    sfText_setPosition(game_instance->best_score_text, get_position(900,
    800));
    game_instance->best_score_field = sfText_create();
    sfText_setString(game_instance->best_score_field, "0");
    sfText_setFont(game_instance->best_score_field,
    game_instance->font_debas);
    sfText_setCharacterSize(game_instance->best_score_field, 50);
    sfText_setPosition(game_instance->best_score_field, get_position(1150,
    800));
}

void load_sprites(struct game *game_instance)
{
    game_instance->bird = get_bird_instance();
    game_instance->bird->sprite = get_sprite(sfTexture_createFromFile(
        "ressources/lugia2.png", NULL));
    game_instance->aim = get_sprite(sfTexture_createFromFile(
        "ressources/aim.png", NULL));
    game_instance->play = get_sprite(sfTexture_createFromFile(
        "ressources/play.png", NULL));
    game_instance->dog = get_sprite(sfTexture_createFromFile(
        "ressources/pikatriste.png", NULL));
    game_instance->game_over = get_sprite(sfTexture_createFromFile(
        "ressources/game_over.png", NULL));
    game_instance->try_again = get_sprite(sfTexture_createFromFile(
        "ressources/play.png", NULL));
    game_instance->bap = get_sprite(sfTexture_createFromFile(
        "ressources/baptiste.png", NULL));
    game_instance->font_julietta =
        sfFont_createFromFile("ressources/julietta.ttf");
    game_instance->font_debas =
        sfFont_createFromFile("ressources/BebasNeue.otf");
    sfSprite_setPosition(game_instance->play, get_position(600, 450));
}