/*
** EPITECH PROJECT, 2020
** B-CPP-300-MPL-3-1-CPPD17-corentin.petrau
** File description:
** Cesar.hpp
*/

#ifndef CESAR_HPP_
    #define CESAR_HPP_
    #define COUT std::cout
    #define ENDL std::endl

#include <iostream>
#include "IEncryptionMethod.hpp"

class Cesar : public IEncryptionMethod
{
    public:
        ~Cesar() {};
        void reset() override;
        void encryptChar(char plainchar) override;
        void decryptChar(char cipherchar) override;

    private:
        int _encrypte = 3;
        int _decrypte = 3;
};

#endif