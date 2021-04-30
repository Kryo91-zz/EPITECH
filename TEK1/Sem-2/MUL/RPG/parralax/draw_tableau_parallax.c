/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** draw_tableau_parallax.c
*/

#include "../include/my_rpg.h"

void tableau_background_parallax(glb_t *global)
{
    global->obj[0]->paral = SKY1;
    global->obj[1]->paral = WOOD_RED1_1;
    global->obj[2]->paral = WOOD_RED1_2;
    global->obj[3]->paral = WOOD_TRANS1_1;
    global->obj[4]->paral = WOOD_TRANS1_2;
    global->obj[5]->paral = WOOD1_1;
    global->obj[6]->paral = WOOD1_2;
}

void draw_background_parallax(glb_t *global)
{
    for (int i = 0; i < 7; i++) {
        if (global->obj[i]->paral == SKY1)
            draw_red_sky(global->obj[0]);
        if (global->obj[i]->paral == WOOD_RED1_2)
            draw_wood_red_1_2(global->obj[2]);
        if (global->obj[i]->paral == WOOD_RED1_1)
            draw_wood_red_1_1(global->obj[1]);
        if (global->obj[i]->paral == WOOD_TRANS1_2)
            draw_wood_trans_1_2(global->obj[4]);
        if (global->obj[i]->paral == WOOD_TRANS1_1)
            draw_wood_trans_1_1(global->obj[3]);
        if (global->obj[i]->paral == WOOD1_2)
            draw_wood_1_2(global->obj[6]);
        if (global->obj[i]->paral == WOOD1_1)
            draw_wood_1_1(global->obj[5]);
    }
}

void parallax(glb_t *global)
{
    move_wood_red_1_2(global->obj[2]);
    move_wood_red_1_1(global->obj[1]);
    move_wood_trans_1_2(global->obj[4]);
    move_wood_trans_1_1(global->obj[3]);
    move_wood_1_2(global->obj[6]);
    move_wood_1_1(global->obj[5]);
}