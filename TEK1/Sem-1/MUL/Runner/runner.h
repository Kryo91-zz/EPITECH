/*
** EPITECH PROJECT, 2019
** RUNNER
** File description:
** .h
*/

#ifndef RUNNER
#define RUNNER
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/Window/Export.h>
#include <SFML/Graphics/Types.h>
#include <SFML/System/Export.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Window/Types.h>
#include <SFML/System/Vector2.h>


void exit_game(sfEvent event, sfRenderWindow *window);
void elim(sfTexture *texture_pack, sfRenderWindow* window, sfMusic *music);
int description_and_error(int ac, char **av);
sfSprite *get_sprite(sfTexture* texture);
void run_window_with_sprite(sfRenderWindow *window, sfEvent event,
sfSprite *sprite, sfMusic *music);
void run_window_mouse_event(sfEvent event, sfRenderWindow *window);

#endif