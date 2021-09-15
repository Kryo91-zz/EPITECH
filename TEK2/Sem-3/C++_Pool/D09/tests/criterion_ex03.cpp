/*
** EPITECH PROJECT, 2020
** B-CPP-300-MPL-3-1-CPPD09-corentin.petrau
** File description:
** criterion_ex03.cpp
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../Mage.hpp"
#include "../Priest.hpp"
#include <stdarg.h>

Test(creation, check_the_creation_Mage)
{
    Mage c("Poney", 42);
    const char *str = c.getName().c_str();

    cr_assert_str_eq(str, "Poney");
}

Test(creation, check_the_creation_Mage_level)
{
    Mage c("Poney", 42);
    int lvl = c.getLvl();

    cr_assert_eq(lvl, 42);
}

Test(creation, check_the_creation_Mage_heal)
{
    Mage c("Poney", 42);
    c.TakeDamage(51);
    c.Heal();
    int nb = c.getPv();

    cr_assert_eq(nb, 99);
}

Test(creation, check_the_creation_Mage_heal_full)
{
    Mage c("Poney", 42);
    c.TakeDamage(0);
    c.Heal();
    int nb = c.getPv();

    cr_assert_eq(nb, 100);
}

Test(creation, check_the_creation_Mage_power_full)
{
    Mage c("Poney", 42);
    c.RestorePower();
    int nb = c.getPower();

    cr_assert_eq(nb, 100);
}

Test(creation, check_the_creation_Mage_heal_more)
{
    Mage c("Poney", 42);
    c.TakeDamage(20);
    c.Heal();
    int nb = c.getPv();

    cr_assert_eq(nb, 100);
}

Test(creation, check_the_creation_Mage_rangeAttackfail)
{
    Mage c("Poney", 42);
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

Test(creation, check_the_creation_Mage_too_much_dammage)
{
    Mage c("Poney", 42);
    c.TakeDamage(200);
    int nb = c.getPv();

    cr_assert_eq(nb, -100);
}

Test(creation, check_the_creation_Mage_closeRange_fail)
{
    Mage c("Poney", 42);
    c.Range = Mage::RANGE;
    int nb = c.CloseAttack();

    cr_assert_eq(nb, 0);
}

Test(creation, check_the_creation_Mage_closeRange_with_no_power)
{
    Mage c("Poney", 42);
    c.Range = Mage::CLOSE;
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

Test(creation, check_the_creation_Priest)
{
    Priest c("Poney", 42);
    const char *str = c.getName().c_str();

    cr_assert_str_eq(str, "Poney");
}

Test(creation, check_the_creation_Priest_level)
{
    Priest c("Poney", 42);
    int lvl = c.getLvl();

    cr_assert_eq(lvl, 42);
}

Test(creation, check_the_creation_Priest_heal)
{
    Priest c("Poney", 42);
    c.TakeDamage(71);
    c.Heal();
    int nb = c.getPv();

    cr_assert_eq(nb, 99);
}

Test(creation, check_the_creation_Priest_heal_full)
{
    Priest c("Poney", 42);
    c.TakeDamage(0);
    c.Heal();
    int nb = c.getPv();

    cr_assert_eq(nb, 100);
}

Test(creation, check_the_creation_Priest_power_full)
{
    Priest c("Poney", 42);
    c.RestorePower();
    int nb = c.getPower();

    cr_assert_eq(nb, 100);
}

Test(creation, check_the_creation_Priest_heal_more)
{
    Priest c("Poney", 42);
    c.TakeDamage(20);
    c.Heal();
    int nb = c.getPv();

    cr_assert_eq(nb, 100);
}

Test(creation, check_the_creation_Priest_rangeAttackfail)
{
    Priest c("Poney", 42);
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

Test(creation, check_the_creation_Priest_too_much_damPriest)
{
    Priest c("Poney", 42);
    c.TakeDamage(200);
    int nb = c.getPv();

    cr_assert_eq(nb, -100);
}

Test(creation, check_the_creation_Priest_closeRange_fail)
{
    Priest c("Poney", 42);
    c.Range = Priest::RANGE;
    int nb = c.CloseAttack();

    cr_assert_eq(nb, 0);
}

Test(creation, check_the_creation_Priest_closeRange_with_no_power)
{
    Priest c("Poney", 42);
    c.Range = Priest::CLOSE;
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