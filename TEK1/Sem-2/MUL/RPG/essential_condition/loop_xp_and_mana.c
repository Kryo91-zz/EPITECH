/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** loop_for_all_menu.c
*/

#include "../include/my_rpg.h"

int tree_competence2(glb_t *global, int n)
{
    if (global->exp == 5 && n == 1) {
        global->manamax += 25;
        global->health = global->healthmax;
        global->mana = global->manamax;
        n -= 1;
    }
    return (n);
}

void tree_competence(glb_t *global)
{
    static int n = 0;
    if (global->exp == 2 && n == 0) {
        global->healthmax += 25;
        global->health = global->healthmax;
        global->mana = global->manamax;
        n += 1;
    }
    if (global->exp == 3 && n == 1) {
        global->manamax += 25;
        global->health = global->healthmax;
        global->mana = global->manamax;
        n -= 1;
    }
    if (global->exp == 4 && n == 0) {
        global->healthmax += 25;
        global->health = global->healthmax;
        global->mana = global->manamax;
        n += 1;
    }
    n = tree_competence2(global, n);
}

void power_life(glb_t *global)
{
    static int n = 0;

    n += 1;
    if (global->health < global->healthmax) {
        if (n == 10) {
            global->minhealth += 1;
            n = 0;
        }
        if (global->minhealth == 100) {
            global->health += 1;
            global->minhealth = 0;
        }
    } else
        n = 0;
}

void power_mana(glb_t *global)
{
    static int n = 0;

    n += 1;
    if (global->mana < global->manamax) {
        if (n == 3) {
            global->minimana += 1;
            n = 0;
        }
        if (global->minimana == 100) {
            global->mana += 1;
            global->minimana = 0;
        }
    } else
        n = 0;
}

void power_xp(glb_t *global)
{
    static int n = 0;

    n += 1;
    if (global->exp < global->expmax) {
        if (n == 15) {
            global->minixp += 1;
            n = 0;
        }
        if (global->minixp >= 100) {
            global->exp += 1;
            global->minixp = 0;
        }
    } else
        n = 0;
}