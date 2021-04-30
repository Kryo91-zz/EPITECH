/*
** EPITECH PROJECT, 2019
** HUNTER
** File description:
** .c
*/

#include <SFML/Graphics.h>
#include <stdio.h>
#include <SFML/Audio.h>
#include "hunter.h"

int main(int ac, char **av)
{
    char *app_name = "My Hunter";
    char *background = "ressources/fond.png";

    if (description_and_error(ac, av) == 1)
        return (0);
    sfMusic *music = sfMusic_createFromFile("ressources/pokemon.ogg");
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