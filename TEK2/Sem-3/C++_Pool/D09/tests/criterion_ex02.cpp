/*
** EPITECH PROJECT, 2020
** B-CPP-300-MPL-3-1-CPPD09-corentin.petrau
** File description:
** criterion_ex02.cpp
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../Warrior.hpp"
#include <stdarg.h>

Test(creation, check_the_creation_Warrior_with_weapon)
{
    Warrior c("Poney", 42, "Sacred Sword");
    int level = c.getLvl();

    cr_assert_eq(level, 42);
}

Test(creation, check_the_creation_Warrior)
{
    Warrior c("Poney", 42);
    const char *str = c.getName().c_str();

    cr_assert_str_eq(str, "Poney");
}

Test(creation, check_the_creation_Warrior_level)
{
    Warrior c("Poney", 42);
    int lvl = c.getLvl();

    cr_assert_eq(lvl, 42);
}

Test(creation, check_the_creation_Warrior_heal)
{
    Warrior c("Poney", 42);
    c.TakeDamage(51);
    c.Heal();
    int nb = c.getPv();

    cr_assert_eq(nb, 99);
}

Test(creation, check_the_creation_Warrior_heal_full)
{
    Warrior c("Poney", 42);
    c.TakeDamage(0);
    c.Heal();
    int nb = c.getPv();

    cr_assert_eq(nb, 100);
}

Test(creation, check_the_creation_Warrior_power_full)
{
    Warrior c("Poney", 42);
    c.RestorePower();
    int nb = c.getPower();

    cr_assert_eq(nb, 100);
}

Test(creation, check_the_creation_Warrior_heal_more)
{
    Warrior c("Poney", 42);
    c.TakeDamage(20);
    c.Heal();
    int nb = c.getPv();

    cr_assert_eq(nb, 100);
}

Test(creation, check_the_creation_Warrior_rangeAttackfail)
{
    Warrior c("Poney", 42);
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

Test(creation, check_the_creation_Warrior_too_much_dammage)
{
    Warrior c("Poney", 42);
    c.TakeDamage(200);
    int nb = c.getPv();

    cr_assert_eq(nb, -100);
}

Test(creation, check_the_creation_Warrior_closeRange_fail)
{
    Warrior c("Poney", 42);
    c.Range = Warrior::RANGE;
    int nb = c.CloseAttack();

    cr_assert_eq(nb, 0);
}

Test(creation, check_the_creation_Warrior_closeRange_with_no_power)
{
    Warrior c("Poney", 42);
    c.Range = Warrior::CLOSE;
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