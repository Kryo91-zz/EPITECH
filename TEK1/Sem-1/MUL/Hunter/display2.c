/*
** EPITECH PROJECT, 2019
** HUNTER
** File description:
** .c
*/

#include "hunter.h"

void window_draw_end2(sfRenderWindow *window, struct game *game_instance,
                        sfEvent event)
{
    if (event.mouseMove.x >= 500 + 130 && event.mouseMove.x <= 790 +
        130 && event.mouseMove.y >= 300 + 250 &&
        event.mouseMove.y <= 488 + 250) {
        sfSprite_setPosition(game_instance->play2, get_position(670, 550));
        sfRenderWindow_drawSprite(window, game_instance->play2, NULL);
    }
    if (event.mouseMove.x >= 0 && event.mouseMove.x <= 150
        && event.mouseMove.y >= 0 &&
        event.mouseMove.y <= 150) {
        sfRenderWindow_drawSprite(window, game_instance->leave2, NULL);
    }
}

void manage_window_events2(sfEvent event, struct game *game_instance)
{
    if (event.type == sfEvtMouseButtonPressed &&
        event.mouseButton.button == sfMouseLeft && game_instance->step == 5) {
        game_event_lvl1(event, game_instance);
        return;
    }
    if (event.type == sfEvtMouseButtonPressed &&
        event.mouseButton.button == sfMouseLeft && game_instance->step == 6) {
        game_event_lvl2(event, game_instance);
        return;
    }
    if (event.type == sfEvtMouseButtonPressed &&
        event.mouseButton.button == sfMouseLeft && game_instance->step == 7) {
        game_event_lvl3(event, game_instance);
        return;
    }
}

void load_sprites3(struct game *game_instance)
{
    game_instance->lvl = get_sprite(sfTexture_createFromFile(
        "ressources/lvl_select.png", NULL));
    game_instance->hard = get_sprite(sfTexture_createFromFile(
        "ressources/hardcore.png", NULL));
    game_instance->hard2 = get_sprite(sfTexture_createFromFile(
        "ressources/hardcore2.png", NULL));
}

void game_event_game2(sfEvent event, struct game *game_instance)
{
    if (event.mouseButton.x >= 1030 + 130 && event.mouseButton.x <= 1280 +
        130 && event.mouseButton.y >= 200 + 250 &&
        event.mouseButton.y <= 588 + 250) {
            game_instance->step = 7;
            return ;
    }
    if (event.mouseButton.x >= 420 + 130 && event.mouseButton.x <= 920 +
        130 && event.mouseButton.y >= 0 + 250 &&
        event.mouseButton.y <= 150 + 250) {
            game_instance->step = 1;
            return ;
    }
}