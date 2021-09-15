/*
** EPITECH PROJECT, 2020
** B-CPP-300-MPL-3-1-CPPD09-corentin.petrau
** File description:
** criterion_ex04.cpp
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../Paladin.hpp"
#include <stdarg.h>

Test(creation, check_the_creation_Paladin_with_weapon)
{
    Paladin c("Poney", 42, "Sacred Sword");
    int level = c.getLvl();

    cr_assert_eq(level, 42);
}

Test(creation, check_the_creation_Paladin)
{
    Paladin c("Poney", 42);
    const char *str = c.getName().c_str();

    cr_assert_str_eq(str, "Poney");
}

Test(creation, check_the_creation_Paladin_level)
{
    Paladin c("Poney", 42);
    int lvl = c.getLvl();

    cr_assert_eq(lvl, 42);
}

Test(creation, check_the_creation_Paladin_heal)
{
    Paladin c("Poney", 42);
    c.TakeDamage(71);
    c.Heal();
    int nb = c.getPv();

    cr_assert_eq(nb, 99);
}

Test(creation, check_the_creation_Paladin_heal_full)
{
    Paladin c("Poney", 42);
    c.TakeDamage(0);
    c.Heal();
    int nb = c.getPv();

    cr_assert_eq(nb, 100);
}

Test(creation, check_the_creation_Paladin_power_full)
{
    Paladin c("Poney", 42);
    c.RestorePower();
    int nb = c.getPower();

    cr_assert_eq(nb, 100);
}

Test(creation, check_the_creation_Paladin_heal_more)
{
    Paladin c("Poney", 42);
    c.TakeDamage(20);
    c.Heal();
    int nb = c.getPv();

    cr_assert_eq(nb, 100);
}

Test(creation, check_the_creation_Paladin_rangeAttackfail)
{
    Paladin c("Poney", 42);
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

Test(creation, check_the_creation_Paladin_too_much_damPaladin)
{
    Paladin c("Poney", 42);
    c.TakeDamage(200);
    int nb = c.getPv();

    cr_assert_eq(nb, -100);
}

Test(creation, check_the_creation_Paladin_closeRange_fail)
{
    Paladin c("Poney", 42);
    c.Range = Paladin::RANGE;
    int nb = c.CloseAttack();

    cr_assert_eq(nb, 0);
}

Test(creation, check_the_creation_Paladin_closeRange_with_no_power)
{
    Paladin c("Poney", 42);
    c.Range = Paladin::CLOSE;
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

Test(creaction, Paladin_Intercept_1)
{
    Paladin c("Poney", 42);
    c.Range = Paladin::CLOSE;
    int nb = c.Intercept();

    cr_assert_eq(nb, 0);
}

Test(creaction, Paladin_Intercept_2)
{
    Paladin c("Poney", 42);
    c.Range = Paladin::RANGE;
    int nb = c.Intercept();

    cr_assert_eq(nb, 0);
}

Test(creaction, Paladin_Intercept_3)
{
    Paladin c("Poney", 42);
    c.Range = Paladin::CLOSE;
    int nb = c.Intercept();
    nb = c.Intercept();
    nb = c.Intercept();
    nb = c.Intercept();
    nb = c.Intercept();
    nb = c.Intercept();
    nb = c.Intercept();
    nb = c.Intercept();
    nb = c.Intercept();
    nb = c.Intercept();
    nb = c.Intercept();
    nb = c.Intercept();
    nb = c.Intercept();
    nb = c.Intercept();

    cr_assert_eq(nb, 0);
}