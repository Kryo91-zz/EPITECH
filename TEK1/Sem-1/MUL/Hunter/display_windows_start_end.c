/*
** EPITECH PROJECT, 2019
** HUNTER
** File description:
** .c
*/

#include "hunter.h"

void window_draw(sfRenderWindow *window, struct game *game_instance,
                sfEvent event)
{
    if (game_instance->step == 0)
        window_draw_start(window, game_instance, event);
    if (game_instance->step == 1)
        window_draw_game(window, game_instance);
    if (game_instance->step == 2)
        window_draw_end(window, game_instance, event);
    if (game_instance-> step == 3)
        window_draw_info(window, game_instance, event);
    if (game_instance->step == 4)
        window_draw_lvl(window, game_instance, event);
    if (game_instance->step == 5)
        window_draw_gamelvl1(window, game_instance);
    if (game_instance->step == 6)
        window_draw_gamelvl2(window, game_instance);
    if (game_instance->step == 7)
        window_draw_gamelvl3(window, game_instance);

}

void window_draw_start(sfRenderWindow *window, struct game *game_instance,
                        sfEvent event)
{

    if (game_instance->step != 0)
        return;
    sfRenderWindow_setMouseCursorVisible(window, sfTrue);
    sfSprite_setPosition(game_instance->info, get_position(650, 250));
    sfRenderWindow_drawSprite(window, game_instance->sprite, NULL);
    sfRenderWindow_drawSprite(window, game_instance->play, NULL);
    sfRenderWindow_drawSprite(window, game_instance->info, NULL);
    if (event.mouseMove.x >= 470 + 130 && event.mouseMove.x <= 790 +
    130 && event.mouseMove.y >= 200 + 250 &&
    event.mouseMove.y <= 388 + 250) {
        sfSprite_setPosition(game_instance->play2, get_position(600, 450));
        sfRenderWindow_drawSprite(window, game_instance->play2, NULL);
    }
    if (event.mouseMove.x >= 470 + 130 && event.mouseMove.x <= 790 +
    130 && event.mouseMove.y >= 0 + 250 &&
    event.mouseMove.y <= 188 + 250) {
        sfSprite_setPosition(game_instance->info2, get_position(650, 250));
        sfRenderWindow_drawSprite(window, game_instance->info2, NULL);
    }
}

void window_draw_game(sfRenderWindow *window, struct game *game_instance)
{
    if (game_instance->step != 1)
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

void window_draw_end(sfRenderWindow *window, struct game *game_instance,
                        sfEvent event)
{
    if (game_instance->step != 2)
        return ;
    sfRenderWindow_setMouseCursorVisible(window, sfTrue);
    sfRenderWindow_drawSprite(window, game_instance->sprite, NULL);
    sfSprite_setPosition(game_instance->dog, get_position(620, 50));
    sfSprite_setPosition(game_instance->try_again, get_position(670, 550));
    sfSprite_setPosition(game_instance->game_over, get_position(620, 265));
    sfRenderWindow_drawSprite(window, game_instance->dog, NULL);
    sfRenderWindow_drawSprite(window, game_instance->game_over, NULL);
    sfRenderWindow_drawSprite(window, game_instance->leave, NULL);
    sfRenderWindow_drawSprite(window, game_instance->try_again, NULL);
    sfRenderWindow_drawText(window, game_instance->score_field, NULL);
    sfRenderWindow_drawText(window, game_instance->score_text, NULL);
    sfRenderWindow_drawText(window, game_instance->miss_text, NULL);
    sfRenderWindow_drawText(window, game_instance->speed_text, NULL);
    sfRenderWindow_drawText(window, game_instance->best_score_field, NULL);
    sfRenderWindow_drawText(window, game_instance->best_score_text, NULL);
    window_draw_end2(window, game_instance, event);
}

void window_draw_info(sfRenderWindow *window, struct game *game_instance,
                        sfEvent event)
{
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile("ressources/BebasNeue.otf");

    if (game_instance->step != 3)
        return ;
    sfRenderWindow_drawSprite(window, game_instance->sprite, NULL);
    sfRenderWindow_drawSprite(window, game_instance->leave, NULL);
    sfText_setPosition(text, get_position(300, 100));
    sfText_setString(text, "This is the best shooter game of the"
                                " pokemon world :\n\n"
                                "The objectif ? very easy :)\n"
                                "You need to shoot on this fu****g pokemon"
                                " on your screen\n\n\n"
                                "RULES :\n\n     You have three chances to "
                                "touch the pokemon\n     If the pokemon go out"
                                " the window ? Don't worry"
                                " he will come back\n"
                                "     Take care of the speed of the pokemon"
                                " increase each time you touch him\n\n"
                                "GOOD LUCK CATCHER");
    sfText_setFont(text, font);
    sfText_setColor(text, sfRed);
    sfText_setCharacterSize(text, 50);
    sfRenderWindow_drawText(window, text, NULL);
    if (event.mouseMove.x >= 0 && event.mouseMove.x <= 150
        && event.mouseMove.y >= 0 &&
        event.mouseMove.y <= 150) {
        sfRenderWindow_drawSprite(window, game_instance->leave2, NULL);
    }
}