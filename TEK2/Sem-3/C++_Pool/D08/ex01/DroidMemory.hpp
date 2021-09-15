/*
** EPITECH PROJECT, 2020
** B-CPP-300-MPL-3-1-CPPD08-corentin.petrau
** File description:
** DroidMemory.hpp
*/
#include <fstream>
#include <iostream>

class DroidMemory
{
    public:
        DroidMemory();
        ~DroidMemory();
        const size_t &getFingerprint(void) const;
        void setFingerprint(size_t Fingerprint);
        const size_t &getExp(void) const;
        void setExp(size_t Exp);
        size_t &operator<<(DroidMemory &rhs);
        size_t &operator>>(DroidMemory &rhs);
        size_t &operator+=(DroidMemory &rhs);
        size_t &operator+=(size_t rhs);
        DroidMemory &operator+(DroidMemory &rhs);
    private:
        size_t _Exp;
        size_t _Fingerprint;
};
std::ostream &operator<<(std::ostream &s, const DroidMemory &rhs);