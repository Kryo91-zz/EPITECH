/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** main.c
*/

#include "runner.h"

sfSprite *get_sprite(sfTexture* texture)
{
    sfSprite *sprite = sfSprite_create();

    sfSprite_setTexture(sprite, texture, sfTrue);
    return (sprite);
}

int main(int ac, char **av)
{
    char *app_name = "My Runner";
    char *background = "ressources/fond_nuit.png";

    if (description_and_error(ac, av) == 1)
        return (0);
    sfMusic *music = sfMusic_createFromFile("ressources/Super_Smash.ogg");
    sfVideoMode mode = {1600, 900, 32};
    sfRenderWindow* window = sfRenderWindow_create(mode, app_name,
        sfTitlebar | sfClose, NULL);
    sfTexture *texture_pack = sfTexture_createFromFile(background, NULL);
    sfEvent event;
    run_window_with_sprite(window, event, get_sprite(texture_pack), music);
    sfRenderWindow_setFramerateLimit(window, 120);
    elim(texture_pack, window, music);
    return (0);
}

int description_and_error(int ac, char **av)
{
    if (ac > 2)
        return (1);
    if (ac == 2 && av[1][0] != '-' && av[1][1] != 'h')
        return (1);
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h') {
        write(1, "press the space bar to jump\n", 29);
        return (1);
    }
    return (0);
}

void run_window_with_sprite(sfRenderWindow *window, sfEvent event,
sfSprite *sprite, sfMusic *music)
{
    sfClock *move_clock = sfClock_create();
    sfClock *anim_clock = sfClock_create();

    sfMusic_play(music);
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event))
            run_window_mouse_event(event, window);
            sfClock_restart(move_clock);
            run_window_draw(window, event);
        }
}