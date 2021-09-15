/*
** EPITECH PROJECT, 2020
** ex00
** File description:
** Droid.cpp
*/

#include "Droid.hpp"

Droid &Droid::operator=(const Droid &rhs)
{
    this->_Id = rhs._Id;
    this->_Energy = rhs._Energy;
    this->_Status = rhs._Status;

    return *this;
}

Droid &Droid::operator<<(size_t &energy)
{
    int res = this->_Energy + energy;

    if (res > 100) {
        this->_Energy = 100;
        res -= 100;
        energy = res;
        return *this;
    } else {
        this->_Energy = res;
        energy = 0;
    }
    return *this;
}

Droid &Droid::operator<<(Droid &rhs)
{
    while (this->_Energy < 100 && rhs._Energy > 0) {
        this->_Energy += 1;
        rhs._Energy -= 1;
    }
    return *this;
}

bool Droid::operator==(const Droid &rhs)
{
    return !(*this != rhs);
}

bool Droid::operator!=(const Droid &rhs)
{
    return (*(this->_Status) != *(rhs._Status));
}

std::ostream &operator<<(std::ostream &s, const Droid &rhs)
{
    s << "Droid \'" << rhs.getId() << "\', " << *rhs.getStatus() << ", " << rhs.getEnergy();
    return s;
}

Droid::Droid(const std::string &Id)
{
    this->_Id = Id;
    this->BattleData;
    std::cout << "Droid '" << this->_Id << "' Activated" << std::endl;
}

Droid::~Droid(void)
{
    std::cout << "Droid \'" << this->_Id << "\' Destroyed" << std::endl;
}

Droid::Droid(Droid &other)
{
    this->_Energy = other._Energy;
    this->_Id = other._Id;
    this->_Status = other._Status;

    std::cout << "Droid \'" << other._Id << "\' Activated , Memory Dumped" << std::endl;
}

std::string Droid::getId(void) const
{
    return this->_Id;
}

size_t Droid::getEnergy(void)  const
{
    return this->_Energy;
}

size_t Droid::getAttack(void)
{
    return this->_Attack;
}

size_t Droid::getThoughness(void)
{
    return this->_Toughness;
}

std::string *Droid::getStatus(void) const
{
    return this->_Status;
}

void Droid::setId(std::string Id)
{
    this->_Id = Id;
}

void Droid::setEnergy(size_t Energy)
{
    if (Energy >= 100)
        this->_Energy = 100;
    else
        this->_Energy = Energy;
}

void Droid::setStatus(std::string *Status)
{
    if (this->_Status == Status)
        delete this->_Status;
    else if (this->_Status == NULL)
        this->_Status = Status;
    this->_Status = Status;
}
