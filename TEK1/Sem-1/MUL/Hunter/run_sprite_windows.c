/*
** EPITECH PROJECT, 2019
** HUNTER
** File description:
** .c
*/

#include "hunter.h"

void run_window_with_sprite(sfRenderWindow *window, sfEvent event,
sfSprite *sprite, sfMusic *music)
{
    struct game *game_instance = get_game_instance();
    sfClock *move_clock = sfClock_create();
    sfClock *anim_clock = sfClock_create();

    load_other(game_instance);
    game_instance->sprite = sprite;
    game_instance->best_score = 0;
    sfMusic_play(music);
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event))
            run_window_mouse_event(event, game_instance, window);
        if (sfClock_getElapsedTime(move_clock).microseconds
            / 100 >= game_instance->bird->speed) {
            sfClock_restart(move_clock);
            run_window_draw(window, game_instance, event);
        }
        if (sfClock_getElapsedTime(anim_clock).microseconds
            / 100 > 3000)
            run_window_anim(anim_clock, game_instance);
    }
}

void run_window_mouse_event(sfEvent event, struct game *game_instance,
                            sfRenderWindow *window)
{

    if (event.type == sfEvtClosed || event.key.code == sfKeyEscape)
        exit_game(event, window);
    if (event.type == sfEvtMouseMoved)
        game_instance->mouse = get_position(event.mouseMove.x - 122,
        event.mouseMove.y - 122);
    manage_window_events(event, game_instance, window);
}

void run_window_draw(sfRenderWindow *window, struct game *game_instance,
                        sfEvent event)
{
    sfRenderWindow_clear(window, sfBlack);
    window_draw(window, game_instance, event);
    sfRenderWindow_display(window);
}

void run_window_anim(sfClock *anim_clock, struct game *game_instance)
{
    sfClock_restart(anim_clock);
    game_instance->bird->skin_index++;
    sfSprite_setTextureRect(game_instance->bird->sprite,
    get_rect_bird_skin(game_instance));
}