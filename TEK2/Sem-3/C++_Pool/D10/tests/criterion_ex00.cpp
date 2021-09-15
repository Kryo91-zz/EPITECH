/*
** EPITECH PROJECT, 2020
** B-CPP-300-MPL-3-1-CPPD09-corentin.petrau
** File description:
** criterion_ex00.cpp
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../ex00/Sorcerer.hpp"
#include "../ex00/Victim.hpp"
#include "../ex00/Peon.hpp"
#include "../ex01/AEnemy.hpp"
#include "../ex01/AWeapon.hpp"
#include "../ex01/Character.hpp"
#include "../ex01/PlasmaRifle.hpp"
#include "../ex01/PowerFist.hpp"
#include "../ex01/RadScorpion.hpp"
#include "../ex01/SuperMutant.hpp"
#include <stdarg.h>
#include <assert.h>
#include <cassert>

void redirect_all_stdout(void)
{
        cr_redirect_stdout();
        cr_redirect_stderr();
}

void do_a_test()
{
    Sorcerer c("Martin", "Magnific");
}

void do_a_test2()
{
    Sorcerer robert("Robert", "the Magnificent");
    Victim jim("Jimmy");
    Peon joe("Joe");
}

void do_a_test_3()
{
    Sorcerer robert("Robert", "the Magnificent");
    Victim jim("Jimmy");
    Peon joe("Joe");
    std::cout << robert << jim << joe;
    robert.polymorph(jim);
    robert.polymorph(joe);
}

void do_a_test_4_ex01()
{
    const auto preda = new Character("Predator");
    const auto prey = new RadScorpion();
    COUT << *preda;
    AWeapon *pr(new PlasmaRifle());
    AWeapon *pf(new PowerFist ());
    preda->equip(pr);
    COUT << *preda;
    preda->equip(pf);
    preda-> attack(prey);
    COUT << *preda;
    preda->equip(pr);
    COUT << *preda;
    preda->attack(prey);
    COUT << *preda;
    preda->attack(prey);
    COUT << *preda;
}

void do_a_test_5_ex01()
{
    const auto mutant = new SuperMutant();
    mutant->takeDamage(180);
    delete(mutant);
}

void do_a_test_6_ex01()
{
    const auto mutant = new SuperMutant();
    mutant->takeDamage(1);
    delete(mutant);
}

Test(creation, creation_sorcer, .init=redirect_all_stdout)
{
    do_a_test();
    const char *str = "Martin, Magnific, is born!\nMartin, Magnific, is dead. Consequences will never be the same!\n";
    cr_assert_stdout_eq_str(str, "");
}

Test(creation, creation_sorcer_victim_peon, .init=redirect_all_stdout)
{
    do_a_test2();
    const char *str = "Robert, the Magnificent, is born!\nSome random victim called Jimmy just popped!\nSome random victim called Joe just popped!\nZog zog.\nBleuark...\nVictim Joe just died for no apparent reason!\nVictim Jimmy just died for no apparent reason!\nRobert, the Magnificent, is dead. Consequences will never be the same!\n";
    cr_assert_stdout_eq_str(str, "");
}

Test(creation, creation_sorcer_victim_peon_and_presentation, .init=redirect_all_stdout)
{
    do_a_test_3();
    const char *str = "Robert, the Magnificent, is born!\nSome random victim called Jimmy just popped!\nSome random victim called Joe just popped!\nZog zog.\nI am Robert, the Magnificent, and I like ponies!\nI'm Jimmy and I like otters!\nI'm Joe and I like otters!\nJimmy has been turned into a cute little sheep!\nJoe has been turned into a pink pony!\nBleuark...\nVictim Joe just died for no apparent reason!\nVictim Jimmy just died for no apparent reason!\nRobert, the Magnificent, is dead. Consequences will never be the same!\n";
    cr_assert_stdout_eq_str(str, "");
}

Test(creation, creation_ex01, .init=redirect_all_stdout)
{
    do_a_test_4_ex01();
    const char *str = "* click click click *\nPredator has 40 AP and is unarmed\nPredator has 40 AP and wields a Plasma Rifle\nPredator attacks RadScorpion with a Power Fist\n* pschhh... SBAM! *\nPredator has 32 AP and wields a Power Fist\nPredator has 32 AP and wields a Plasma Rifle\nPredator attacks RadScorpion with a Plasma Rifle\n* piouuu piouuu piouuu *\nPredator has 27 AP and wields a Plasma Rifle\nPredator attacks RadScorpion with a Plasma Rifle\n* piouuu piouuu piouuu *\n* SPROTCH *\nPredator has 22 AP and wields a Plasma Rifle\n";
    cr_assert_stdout_eq_str(str, "");
}

Test(creation, creation_ex01_1, .init=redirect_all_stdout)
{
    do_a_test_5_ex01();
    const char *str = "Gaaah. Me want smash heads!\nAaargh...\n";
    cr_assert_stdout_eq_str(str, "");
}

Test(creation, creation_ex01_2, .init=redirect_all_stdout)
{
    do_a_test_6_ex01();
    const char *str = "Gaaah. Me want smash heads!\nAaargh...\n";
    cr_assert_stdout_eq_str(str, "");
}