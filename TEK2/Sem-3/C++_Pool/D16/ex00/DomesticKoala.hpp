/*
** EPITECH PROJECT, 2020
** B-CPP-300-MPL-3-1-CPPD16-corentin.petrau
** File description:
** DomesticKoala.hpp
*/



#ifndef DOMESTICKOALA_HPP_
#define DOMESTICKOALA_HPP_

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <vector>
#include "KoalaAction.hpp"

class DomesticKoala {
    public:
        DomesticKoala(KoalaAction &);
        DomesticKoala(const DomesticKoala &);
        ~DomesticKoala ();
        DomesticKoala &operator=(const DomesticKoala &);

        using methodPointer_t = void (KoalaAction::*)(const std::string &);
        const std::vector<methodPointer_t> *getActions() const;

        void learnAction(unsigned char, methodPointer_t);
        void unlearnAction(unsigned char);
        void doAction(unsigned char, const std::string &);
        void setKoalaAction(KoalaAction &);
    protected:
        KoalaAction koalaAct;
        std::vector<methodPointer_t> act;
        std::vector<char> ptr;
    private:
};

#endif /* !DOMESTICKOALA_HPP_ */





