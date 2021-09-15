/*
** EPITECH PROJECT, 2020
** ex00
** File description:
** Droid.hpp
*/
#ifndef DROID_HPP
    #define DROID_HPP

#include <iostream>
#include <string>
#include "DroidMemory.hpp"

class Droid
{
    public :
        Droid();
        Droid(const std::string &Id);
        Droid(Droid &other);
        ~Droid();

        std::string getId(void) const;
        size_t getEnergy(void) const;
        size_t getAttack(void);
        size_t getThoughness(void);
        std::string *getStatus(void) const;
        std::string *getActivity(void) const;
        std::string *getWorking(void) const;

        void setId(std::string Id);
        void setEnergy(size_t Energy);
        void setStatus(std::string *Status);

        bool operator!=(const Droid &rhs);
        bool operator==(const Droid &rhs);
        Droid &operator=(const Droid &rhs);
        Droid &operator<<(Droid &rhs);
        Droid &operator<<(size_t &energy);
        bool operator()(std::string *task, size_t req_exp);
    private:
        std::string _Id = "";
        size_t _Energy = 50;
        const size_t _Attack = 25;
        const size_t _Toughness = 15;
        std::string *_Status = new std::string("Standing By");
        DroidMemory *BattleData;
        std::string *Activity;
        std::string *Working;
};
std::ostream &operator<<(std::ostream &s, const Droid &rhs);
#endif
