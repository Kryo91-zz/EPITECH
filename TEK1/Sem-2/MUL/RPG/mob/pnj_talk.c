/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** pnj_talk.c
*/

#include "../include/my_rpg.h"

void draw_text_pnj(glb_t *global)
{
    static int n = 0;

    if (global->chara->position.x < global->pnj.position.x + 100 && \
    global->chara->position.x > global->pnj.position.x && \
    global->chara->position.y < global->pnj.position.y + 100 && \
    global->chara->position.y > global->pnj.position.y && n == 0) {
        sfText_setPosition(global->text_pnj, get_position(4130, 1350));
        sfText_setString(global->text_pnj, \
        "Hey ! Approche j'ai besoin de toi ! (press space)");
        sfText_setFont(global->text_pnj, global->font);
        sfText_setColor(global->text_pnj, sfWhite);
        sfText_setCharacterSize(global->text_pnj, 30);
        sfRenderWindow_drawText(global->wind.window, global->text_pnj, NULL);
        if (sfKeyboard_isKeyPressed(sfKeySpace))
            n += 1;
    } else if (n == 1) {
        sfText_setPosition(global->text_pnj, get_position(4130, 1350));
        sfText_setString(global->text_pnj, \
        "Le reste de mes vaches se sont enfuies !\nPeut tu m'aider a les retrouver ?\n(press B)");
        sfText_setFont(global->text_pnj, global->font);
        sfText_setColor(global->text_pnj, sfWhite);
        sfText_setCharacterSize(global->text_pnj, 30);
        sfRenderWindow_drawText(global->wind.window, global->text_pnj, NULL);
        if (sfKeyboard_isKeyPressed(sfKeyB))
            n = 2;
    } else if (n == 2) {
        sfText_setPosition(global->text_pnj, get_position(4130, 1350));
        sfText_setString(global->text_pnj, \
        "Elles sont parties vers la GAUCHE en direction de la foret ...");
        sfText_setFont(global->text_pnj, global->font);
        sfText_setColor(global->text_pnj, sfWhite);
        sfText_setCharacterSize(global->text_pnj, 30);
        sfRenderWindow_drawText(global->wind.window, global->text_pnj, NULL);
    }
}