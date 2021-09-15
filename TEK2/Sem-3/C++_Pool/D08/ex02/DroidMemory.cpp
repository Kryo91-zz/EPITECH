/*
** EPITECH PROJECT, 2020
** B-CPP-300-MPL-3-1-CPPD08-corentin.petrau
** File description:
** DroidMemory.cpp
*/

#include "DroidMemory.hpp"

DroidMemory::DroidMemory(void) {
    this->_Exp = 0;
    this->_Fingerprint = random();
}

DroidMemory::~DroidMemory(void) {}

const size_t &DroidMemory::getFingerprint(void) const
{
    return this->_Fingerprint;
}

void DroidMemory::setFingerprint(size_t Fingerprint)
{
    this->_Fingerprint = Fingerprint;
}

const size_t &DroidMemory::getExp(void) const
{
    return this->_Exp;
}

void DroidMemory::setExp(size_t Exp)
{
    this->_Exp = Exp;
}

size_t &DroidMemory::operator<<(DroidMemory &rhs)
{
    if ((this->_Fingerprint ^= rhs._Fingerprint))
        this->_Exp += rhs._Exp;
    return this->_Exp;
}

size_t &DroidMemory::operator>>(DroidMemory &rhs)
{
    if ((rhs._Fingerprint ^= this->_Fingerprint))
        rhs._Exp += this->_Exp;
    return rhs._Exp;
}

size_t &DroidMemory::operator+=(DroidMemory &rhs)
{
    if ((this->_Fingerprint ^= rhs._Fingerprint))
        this->_Exp += rhs._Exp;
    return this->_Exp;
}

size_t &DroidMemory::operator+=(size_t rhs)
{
    if ((this->_Fingerprint ^= rhs))
        this->_Exp += rhs;
    return this->_Exp;
}

std::ostream &operator<<(std::ostream &s, const DroidMemory &rhs)
{
    s << "DroidMemory '" << rhs.getFingerprint() << "', " << rhs.getExp();
    return (s);
}

bool DroidMemory::operator!=(const DroidMemory &rhs)
{
    return (this->_Exp != rhs._Exp \
            || this->_Fingerprint != rhs._Fingerprint);
}

bool DroidMemory::operator==(const DroidMemory &rhs)
{
    return (this->_Exp == rhs._Exp \
            && this->_Fingerprint == rhs._Fingerprint);
}

bool DroidMemory::operator<=(const DroidMemory &rhs)
{
    return (this->_Exp <= rhs._Exp);
}

bool DroidMemory::operator>=(const DroidMemory &rhs)
{
    return (this->_Exp >= rhs._Exp);
}

bool DroidMemory::operator<(const DroidMemory &rhs)
{
    return (this->_Exp < rhs._Exp);
}

bool DroidMemory::operator>(const DroidMemory &rhs)
{
    return (this->_Exp > rhs._Exp);
}

bool DroidMemory::operator<=(size_t rhs)
{
    return (this->_Exp <= rhs);
}

bool DroidMemory::operator>=(size_t rhs)
{
    return (this->_Exp >= rhs);
}

bool DroidMemory::operator<(size_t rhs)
{
    return (this->_Exp < rhs);
}

bool DroidMemory::operator>(size_t rhs)
{
    return (this->_Exp > rhs);
}

DroidMemory &DroidMemory::operator+(DroidMemory &rhs)
{
    DroidMemory *new_droid;

    new_droid->_Exp = this->_Exp + rhs._Exp;
    new_droid->_Fingerprint = this->_Fingerprint + rhs._Fingerprint;
    return *new_droid;
}