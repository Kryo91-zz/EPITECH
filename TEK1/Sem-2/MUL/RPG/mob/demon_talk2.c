/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** draw_all.c
*/

#include "../include/my_rpg.h"

void time_clock_demon3(glb_t *global)
{
    global->demon3.time = sfClock_getElapsedTime(global->demon3.clock);
    global->demon3.seconds = global->demon3.time.microseconds / 1000000.0;
    anim_demon3(global);
}

static void move_rect3(glb_t *global, int offset, int max)
{
    global->demon3.rect.left = (global->demon2.rect.left + offset) % max;
}

void anim_demon3(glb_t *global)
{
    if (global->demon3.seconds > 0.10) {
        sfSprite_setTextureRect(global->demon3.sprite, global->demon3.rect);
        move_rect3(global, 63, 252);
        sfClock_restart(global->demon3.clock);
    }
}

void texture_demon3(glb_t *global)
{
    sfSprite_setPosition(global->demon3.sprite, global->demon3.position);
    sfSprite_setScale(global->demon3.sprite, global->demon3.size);
    sfSprite_setTexture(global->demon3.sprite, global->demon3.texture, sfTrue);
    sfSprite_setTextureRect(global->demon3.sprite, global->demon3.rect);
}

void draw_textdemon3(glb_t *global)
{
    static int n = 0;

    if (global->chara->position.x < global->demon3.position.x + 300 && \
    global->chara->position.x > global->demon3.position.x && \
    global->chara->position.y < global->demon3.position.y + 300 && \
    global->chara->position.y > global->demon3.position.y && n == 0) {
        sfText_setPosition(global->textDemon, get_position(6400, 3350));
        sfText_setString(global->textDemon, \
        "Parfait, maintenant donnes moi ces objets ! (press space)");
        sfText_setFont(global->textDemon, global->font);
        sfText_setColor(global->textDemon, sfWhite);
        sfText_setCharacterSize(global->textDemon, 30);
        sfRenderWindow_drawText(global->wind.window, global->textDemon, NULL);
        if (sfKeyboard_isKeyPressed(sfKeySpace))
            n += 1;
    } else if (n == 1) {
        sfText_setPosition(global->textDemon2, get_position(6400, 3350));
        sfText_setString(global->textDemon2, \
        "Quoi ?!, Tu refuses d'obeir !\nTu vas perir dans les FLAMMES DE L'ENFER PETIT MECREANT !(press B)");
        sfText_setFont(global->textDemon2, global->font);
        sfText_setColor(global->textDemon2, sfWhite);
        sfText_setCharacterSize(global->textDemon2, 30);
        sfRenderWindow_drawText(global->wind.window, global->textDemon2, NULL);
        if (sfKeyboard_isKeyPressed(sfKeyB)) {
            n = 2;
            global->defeat = 1;
        }
    }
}