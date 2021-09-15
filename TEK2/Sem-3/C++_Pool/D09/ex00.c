/*
** EPITECH PROJECT, 2020
** B-CPP-300-MPL-3-1-CPPD09-corentin.petrau
** File description:
** ex00.c
*/

#include "ex00.h"

static void cthulhu_initializer(cthulhu_t *this)
{
    this->m_name = "Cthulhu";
    this->m_power = 42;
    printf("----\nBuilding Cthulhu\n");
}

static void koala_initializer(koala_t *this, char *_name, char _is_A_Legend)
{
    this->m_is_a_legend = _is_A_Legend;
    this->m_parent = *new_cthulhu();
    this->m_parent.m_name = _name;
    if (_is_A_Legend == 0)
        this->m_parent.m_power = 0;
    else
        this->m_parent.m_power = 42;
    printf("Building %s\n", this->m_parent.m_name);
}

cthulhu_t *new_cthulhu(void)
{
    cthulhu_t *cthulhu = malloc(sizeof(cthulhu_t));
    cthulhu_initializer(cthulhu);
    return (cthulhu);
}

koala_t *new_koala(char *name , char is_a_legend)
{
    koala_t *koala = malloc(sizeof(koala_t));
    koala_initializer(koala, name, is_a_legend);
    return (koala);
}

void print_power(cthulhu_t *this)
{
    printf("Power => %d\n", this->m_power);
}

void attack(cthulhu_t *this)
{
    if (this->m_power >= 42) {
        printf("%s attacks and destroys the city\n", this->m_name);
        this->m_power -= 42;
    } else
        printf("%s can't attack, he doesn't have enough power\n", this->m_name);
}

void sleeping(cthulhu_t *this)
{
    printf("%s sleeps\n", this->m_name);
    this->m_power = 42000;
}

void eat(koala_t *this)
{
    printf("%s eats\n", this->m_parent.m_name);
    this->m_parent.m_power += 42;
}