/*
** EPITECH PROJECT, 2020
** B-CPP-300-MPL-3-1-CPPD09-corentin.petrau
** File description:
** criterion_ex00.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../ex00.h"
#include <stdarg.h>

Test(creation, test_the_cthulu_creation_name)
{
    cthulhu_t *c = new_cthulhu();

    cr_assert_str_eq(c->m_name, "Cthulhu");
}

Test(creation, test_the_cthulu_creation_power)
{
    cthulhu_t *c = new_cthulhu();

    cr_assert_eq(c->m_power, 42);
}

Test(creation, test_the_cthulu_sleeping)
{
    cthulhu_t *c = new_cthulhu();
    attack(c);
    sleeping(c);

    cr_assert_eq(c->m_power, 42000);
}

Test(creation, test_the_koala_eats)
{
    koala_t *c = new_koala("Jordan", 1);
    eat(c);

    cr_assert_eq(c->m_parent.m_power, 84);
}

Test(creation, test_the_koala_eats2)
{
    koala_t *c = new_koala("Jordan", 0);
    eat(c);

    cr_assert_eq(c->m_parent.m_power, 42);
}

Test(creation, test_the_koala_Attack)
{
    cthulhu_t *c = new_cthulhu();
    attack(c);

    cr_assert_eq(c->m_power, 0);
}