/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** main.c
*/

#include "runner.h"

void run_window_mouse_event(sfEvent event, sfRenderWindow *window)
{

    if (event.type == sfEvtClosed || event.key.code == sfKeyEscape)
        exit_game(event, window);
}

void run_window_draw(sfRenderWindow *window, sfEvent event)
{
    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_display(window);
}

void exit_game(sfEvent event, sfRenderWindow *window)
{

    if (event.type == sfEvtClosed || event.key.code == sfKeyEscape)
        sfRenderWindow_close(window);
    return ;
}

void elim(sfTexture *texture_pack, sfRenderWindow* window, sfMusic *music)
{
    sfMusic_destroy(music);
    sfTexture_destroy(texture_pack);
    sfRenderWindow_destroy(window);
}