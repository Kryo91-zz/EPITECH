/*
** EPITECH PROJECT, 2021
** CPPPool
** File description:
** main
*/

#include  <iostream>
#include  <memory>
#include "Toy.hpp"
#include "Buzz.hpp"
#include "Woody.hpp"

int  main()
{
    Toy toto;
    Toy ET(Toy::ALIEN, "green", "./alien.txt");
    toto.setName("TOTO !");
    toto.setAscii("alien.txt");
    
    if (toto.getType () == Toy::BASIC_TOY)
        std::cout  << "basic  toy: " << toto.getName () << std::endl<< toto.getAscii () << std::endl;
    if (ET.getType () == Toy::ALIEN)
        std::cout  << "this  alien is: " << ET.getName () << std::endl<< ET.getAscii () << std::endl;
    std::unique_ptr<Toy> b(new  Buzz("buzziiiii"));
    std::unique_ptr<Toy> w(new  Woody("wood"));
    std::unique_ptr<Toy> t(new Toy(Toy::ALIEN, "ET", "alien.txt"));
    return  0;
}