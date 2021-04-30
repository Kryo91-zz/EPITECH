/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** draw_all.c
*/

#include "../include/my_rpg.h"

void time_clock_demon2(glb_t *global)
{
    global->demon2.time = sfClock_getElapsedTime(global->demon2.clock);
    global->demon2.seconds = global->demon2.time.microseconds / 1000000.0;
    anim_demon2(global);
}

static void move_rect2(glb_t *global, int offset, int max)
{
    global->demon2.rect.left = (global->demon2.rect.left + offset) % max;
}

void anim_demon2(glb_t *global)
{
    if (global->demon2.seconds > 0.10) {
        sfSprite_setTextureRect(global->demon2.sprite, global->demon2.rect);
        move_rect2(global, 63, 252);
        sfClock_restart(global->demon2.clock);
    }
}

void texture_demon2(glb_t *global)
{
    sfSprite_setPosition(global->demon2.sprite, global->demon2.position);
    sfSprite_setScale(global->demon2.sprite, global->demon2.size);
    sfSprite_setTexture(global->demon2.sprite, global->demon2.texture, sfTrue);
    sfSprite_setTextureRect(global->demon2.sprite, global->demon2.rect);
}

void draw_textdemon2(glb_t *global)
{
    static int n = 0;

    if (global->chara->position.x < global->demon2.position.x + 300 && \
    global->chara->position.x > global->demon2.position.x && \
    global->chara->position.y < global->demon2.position.y + 300 && \
    global->chara->position.y > global->demon2.position.y && n == 0) {
        sfText_setPosition(global->textDemon, get_position(1570, 3550));
        sfText_setString(global->textDemon, \
        "Bien, tu ferais un bon esclave , si tu n'etais pas mortel ! (press space)");
        sfText_setFont(global->textDemon, global->font);
        sfText_setColor(global->textDemon, sfWhite);
        sfText_setCharacterSize(global->textDemon, 30);
        sfRenderWindow_drawText(global->wind.window, global->textDemon, NULL);
        if (sfKeyboard_isKeyPressed(sfKeySpace))
            n += 1;
    } else if (n == 1) {
        sfText_setPosition(global->textDemon2, get_position(1570, 3550));
        sfText_setString(global->textDemon2, \
        "Plus qu'une relique !\n Le scpetre a besoin de sang pour etre invoque\nVa je t'attend mon ami\n(press B)");
        sfText_setFont(global->textDemon2, global->font);
        sfText_setColor(global->textDemon2, sfWhite);
        sfText_setCharacterSize(global->textDemon2, 30);
        sfRenderWindow_drawText(global->wind.window, global->textDemon2, NULL);
        if (sfKeyboard_isKeyPressed(sfKeyB))
            n = 2;
    } else if (n == 2) {
        sfText_setPosition(global->textDemon, get_position(1570, 3550));
        sfText_setString(global->textDemon, \
        "Tuer des etres inferieurs devrai suffir !");
        sfText_setFont(global->textDemon, global->font);
        sfText_setColor(global->textDemon, sfWhite);
        sfText_setCharacterSize(global->textDemon, 30);
        sfRenderWindow_drawText(global->wind.window, global->textDemon, NULL);
    }
}