/*
** EPITECH PROJECT, 2021
** CPPPool
** File description:
** Victim
*/

#ifndef VICTIM_HPP_
#define VICTIM_HPP_

#define COUT std::cout
#define ENDL std::endl

#include <iostream>
#include <ostream>

class Victim
{
    public:
        Victim(const std::string &name);
        ~Victim();
        virtual void getPolymorphed() const;
        std::string getName() {return this->_name;};

    protected:
        std::string _name;
};

std::ostream &operator<<(std::ostream &stream, Victim &vict);

#endif /* !VICTIM_HPP_ */