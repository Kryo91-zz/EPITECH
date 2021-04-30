/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** lyvia.h
*/

#ifndef MY_RPG_H_
#define MY_RPG_H_

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <SFML/Audio/SoundBuffer.h>
#include <SFML/Audio/Sound.h>

typedef struct mob_s
{
    sfSprite *sprite;
    sfTexture *texture;
    sfClock *clock;
    sfTime time;
    float seconds;
    sfIntRect rect;
    sfVector2f size;
    sfVector2f position;
} mob_t;

#endif /* !MY_RPG_H_ */
