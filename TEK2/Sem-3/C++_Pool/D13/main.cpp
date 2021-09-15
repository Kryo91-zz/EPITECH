/*
** EPITECH PROJECT, 2020
** B-CPP-300-MPL-3-1-CPPD13-corentin.petrau
** File description:
** main.cpp
*/

#include "ex03/Toy.hpp"
#include "ex03/Woody.hpp"
#include "ex03/Buzz.hpp"

int main(void)
{
    std::unique_ptr<Toy>b(new Buzz("buzziiiii"));
    std::unique_ptr<Toy>w(new Woody("wood"));
    std::unique_ptr<Toy>t(new Toy(Toy::ALIEN, "ET", "alien .txt"));
    b->speak("To the code, and beyond !!!!!!!!");
    w->speak("There 's a snake in my boot.");
    t->speak("the claaaaaaw");
}