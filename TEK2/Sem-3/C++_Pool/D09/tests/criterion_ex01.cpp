/*
** EPITECH PROJECT, 2020
** B-CPP-300-MPL-3-1-CPPD09-corentin.petrau
** File description:
** criterion_ex01.cpp
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../Character.hpp"
#include <stdarg.h>

Test(creation, check_the_creation_character)
{
    Character c("Poney", 42);
    const char *str = c.getName().c_str();

    cr_assert_str_eq(str, "Poney");
}

Test(creation, check_the_creation_character_level)
{
    Character c("Poney", 42);
    int lvl = c.getLvl();

    cr_assert_eq(lvl, 42);
}

Test(creation, check_the_creation_character_heal)
{
    Character c("Poney", 42);
    c.TakeDamage(51);
    c.Heal();
    int nb = c.getPv();

    cr_assert_eq(nb, 99);
}

Test(creation, check_the_creation_character_heal_full)
{
    Character c("Poney", 42);
    c.TakeDamage(0);
    c.Heal();
    int nb = c.getPv();

    cr_assert_eq(nb, 100);
}

Test(creation, check_the_creation_character_power_full)
{
    Character c("Poney", 42);
    c.RestorePower();
    int nb = c.getPower();

    cr_assert_eq(nb, 100);
}

Test(creation, check_the_creation_character_heal_more)
{
    Character c("Poney", 42);
    c.TakeDamage(20);
    c.Heal();
    int nb = c.getPv();

    cr_assert_eq(nb, 100);
}

Test(creation, check_the_creation_character_rangeAttackfail)
{
    Character c("Poney", 42);
    int nb = c.RangeAttack();
    nb = c.RangeAttack();
    nb = c.RangeAttack();
    nb = c.RangeAttack();
    nb = c.RangeAttack();
    nb = c.RangeAttack();
    nb = c.RangeAttack();
    nb = c.RangeAttack();
    nb = c.RangeAttack();
    nb = c.RangeAttack();
    nb = c.RangeAttack();

    cr_assert_eq(nb, 0);
}

Test(creation, check_the_creation_character_too_much_dammage)
{
    Character c("Poney", 42);
    c.TakeDamage(200);
    int nb = c.getPv();

    cr_assert_eq(nb, -100);
}

Test(creation, check_the_creation_character_closeRange_fail)
{
    Character c("Poney", 42);
    c.Range = Character::RANGE;
    int nb = c.CloseAttack();

    cr_assert_eq(nb, 0);
}

Test(creation, check_the_creation_character_closeRange_with_no_power)
{
    Character c("Poney", 42);
    c.Range = Character::CLOSE;
    int nb = c.CloseAttack();
    nb = c.CloseAttack();
    nb = c.CloseAttack();
    nb = c.CloseAttack();
    nb = c.CloseAttack();
    nb = c.CloseAttack();
    nb = c.CloseAttack();
    nb = c.CloseAttack();
    nb = c.CloseAttack();
    nb = c.CloseAttack();
    nb = c.CloseAttack();
    nb = c.CloseAttack();
    nb = c.CloseAttack();
    nb = c.CloseAttack();
    nb = c.CloseAttack();
    nb = c.CloseAttack();

    cr_assert_eq(nb, 0);
}