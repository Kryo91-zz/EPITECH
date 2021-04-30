/*
** EPITECH PROJECT, 2019
** HUNTER
** File description:
** .c
*/

#include "hunter.h"

int number_digits(int nbr)
{
    int n = 1;
    int po = 10;

    if (nbr < 0)
        nbr = -nbr;
    while (nbr >= po) {
        n++;
        if (po > 214748364)
            break;
        po *= 10;
    }
    return (n);
}

void window_draw_lvl(sfRenderWindow *window, struct game *game_instance,
                    sfEvent event)
{
    if (game_instance->step != 4)
        return ;
    sfRenderWindow_setMouseCursorVisible(window, sfTrue);
    sfRenderWindow_drawSprite(window, game_instance->sprite, NULL);
    sfSprite_setPosition(game_instance->lvl, get_position(350, 50));
    sfSprite_setPosition(game_instance->sim, get_position(150, 450));
    sfSprite_setPosition(game_instance->luc, get_position(1150, 450));
    sfSprite_setPosition(game_instance->bap2, get_position(650, 450));
    sfRenderWindow_drawSprite(window, game_instance->lvl, NULL);
    sfRenderWindow_drawSprite(window, game_instance->sim, NULL);
    sfRenderWindow_drawSprite(window, game_instance->bap2, NULL);
    sfRenderWindow_drawSprite(window, game_instance->luc, NULL);
    if (event.mouseMove.x >= 150 && event.mouseMove.x <= 450
        && event.mouseMove.y >= 200 + 250 &&
    event.mouseMove.y <= 588 + 250) {
        sfSprite_setPosition(game_instance->sim2, get_position(150, 450));
        sfRenderWindow_drawSprite(window, game_instance->sim2, NULL);
    }
    window_draw_lvl2(window, game_instance, event);
}

void bird_miss(struct game *game_instance)
{
    game_instance->miss++;
    load_game_text(game_instance);
    if (game_instance->miss == 1) {
        if (game_instance->score > game_instance->best_score) {
            game_instance->best_score = game_instance->score;
            sfText_setString(game_instance->best_score_field,
            my_score(game_instance->best_score));
        }
        game_instance->step++;
    }
}

void game_event_game(sfEvent event, struct game *game_instance)
{

    if (event.type != sfEvtMouseButtonPressed ||
        event.mouseButton.button != sfMouseLeft || game_instance->step != 4)
        return;
    if (event.mouseButton.x >= 150 && event.mouseButton.x <= 450
        && event.mouseButton.y >= 200 + 250 &&
        event.mouseButton.y <= 588 + 250) {
            game_instance->step = 5;
            return ;
    } else if (event.mouseButton.x >= 470 + 130 && event.mouseButton.x <= 790 +
        130 && event.mouseButton.y >= 200 + 250 &&
        event.mouseButton.y <= 588 + 250) {
            game_instance->step = 6;
            return ;
    }
    game_event_game2(event, game_instance);
    return ;
}

void load_sprites2(struct game *game_instance)
{
    game_instance->leave = get_sprite(sfTexture_createFromFile(
        "ressources/leave.png", NULL));
    game_instance->leave2 = get_sprite(sfTexture_createFromFile(
        "ressources/leave2.png", NULL));
    game_instance->info = get_sprite(sfTexture_createFromFile(
        "ressources/information.png", NULL));
    game_instance->info2 = get_sprite(sfTexture_createFromFile(
        "ressources/information2.png", NULL));
    game_instance->play2 = get_sprite(sfTexture_createFromFile(
        "ressources/play2.png", NULL));
    game_instance->luc = get_sprite(sfTexture_createFromFile(
        "ressources/lucas.png", NULL));
    game_instance->luc2 = get_sprite(sfTexture_createFromFile(
        "ressources/lucas2.png", NULL));
    game_instance->sim = get_sprite(sfTexture_createFromFile(
        "ressources/simon.png", NULL));
    game_instance->sim2 = get_sprite(sfTexture_createFromFile(
        "ressources/simon2.png", NULL));
    game_instance->bap2 = get_sprite(sfTexture_createFromFile(
        "ressources/baptiste2.png", NULL));
}
