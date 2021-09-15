/*
** EPITECH PROJECT, 2020
** B-CPP-300-MPL-3-1-CPPD09-alec.ferrari
** File description:
** main.cpp
*/

#include "Character.hpp"
#include "Warrior.hpp"
#include "Mage.hpp"
#include "Priest.hpp"
#include "Paladin.hpp"
#include "Hunter.hpp"


int main()
{
    Warrior c("poney", 42);
    c.TakeDamage(50);
    std::cout << "------------STANCE CHANGED TO CLOSE--------" << std::endl;
    c.Range = Warrior::CLOSE;
    std::cout << "------------CLOSE ATTACK--------" << std::endl;
    c.CloseAttack();
    std::cout << "------------RANGE ATTACK--------" << std::endl;
    c.RangeAttack();
    std::cout << "------------STANCE CHANGED TO RANGE--------" << std::endl;
    c.Range = Warrior::RANGE;
    std::cout << "------------CLOSE ATTACK--------" << std::endl;
    c.CloseAttack();
    std::cout << "------------RANGE ATTACK--------" << std::endl;
    c.RangeAttack();
    c.RestorePower();
    //c.Intercept();
    c.Heal();
    c.TakeDamage(200);
    c.TakeDamage(200);
}