/*
** EPITECH PROJECT, 2020
** B-CPP-300-MPL-3-1-CPPD07A-corentin.petrau
** File description:
** Skat.hpp
*/

#include <iostream>
#include <fstream>

class Skat
{
    public :
        Skat();
        Skat(const std::string &name , int stimPaks);
        ~Skat();
        int &stimPaks();
        const std::string &name() const;
        void shareStimPaks(int number , int &stock) ;
        void addStimPaks(unsigned int number) ;
        void useStimPaks();
        void const status();
    private :
        std::string _name = "bob";
        int _stimPaks = 15;
};