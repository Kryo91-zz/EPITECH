/*
** EPITECH PROJECT, 2020
** B-CPP-300-MPL-3-1-CPPD09-corentin.petrau
** File description:
** criterion_ex05.cpp
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../Hunter.hpp"
#include <stdarg.h>

Test(creation, check_the_creation_Hunter_with_weapon)
{
    Hunter c("Poney", 42, "Sacred Sword");
    int level = c.getLvl();

    cr_assert_eq(level, 42);
}

Test(creation, check_the_creation_Hunter)
{
    Hunter c("Poney", 42);
    const char *str = c.getName().c_str();

    cr_assert_str_eq(str, "Poney");
}

Test(creation, check_the_creation_Hunter_level)
{
    Hunter c("Poney", 42);
    int lvl = c.getLvl();

    cr_assert_eq(lvl, 42);
}

Test(creation, check_the_creation_Hunter_heal)
{
    Hunter c("Poney", 42);
    c.TakeDamage(51);
    c.Heal();
    int nb = c.getPv();

    cr_assert_eq(nb, 99);
}

Test(creation, check_the_creation_Hunter_heal_full)
{
    Hunter c("Poney", 42);
    c.TakeDamage(0);
    c.Heal();
    int nb = c.getPv();

    cr_assert_eq(nb, 100);
}

Test(creation, check_the_creation_Hunter_power_full)
{
    Hunter c("Poney", 42);
    c.RestorePower();
    int nb = c.getPower();

    cr_assert_eq(nb, 100);
}

Test(creation, check_the_creation_Hunter_heal_more)
{
    Hunter c("Poney", 42);
    c.TakeDamage(20);
    c.Heal();
    int nb = c.getPv();

    cr_assert_eq(nb, 100);
}

Test(creation, check_the_creation_Hunter_rangeAttackfail)
{
    Hunter c("Poney", 42);
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

Test(creation, check_the_creation_Hunter_too_much_dammage)
{
    Hunter c("Poney", 42);
    c.TakeDamage(200);
    int nb = c.getPv();

    cr_assert_eq(nb, -100);
}

Test(creation, check_the_creation_Hunter_closeRange_fail)
{
    Hunter c("Poney", 42);
    c.Range = Hunter::RANGE;
    int nb = c.CloseAttack();

    cr_assert_eq(nb, 0);
}

Test(creation, check_the_creation_Hunter_closeRange_with_no_power)
{
    Hunter c("Poney", 42);
    c.Range = Hunter::CLOSE;
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

Test(creation, check_the_creation_Hunter_RangeAttack_with_no_power)
{
    Hunter c("Poney", 42);
    c.Range = Hunter::CLOSE;
    int nb = c.RangeAttack();

    cr_assert_eq(nb, 45);
}