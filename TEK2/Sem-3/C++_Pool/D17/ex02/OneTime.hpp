/*
** EPITECH PROJECT, 2020
** B-CPP-300-MPL-3-1-CPPD17-corentin.petrau
** File description:
** OneTime.hpp
*/

#ifndef ONETIME_HPP_
    #define ONETIME_HPP_
    #define COUT std::cout
    #define ENDL std::endl

    #include "IEncryptionMethod.hpp"
    #include <string>
    #include <iostream>

class OneTime : public IEncryptionMethod
{
    public:
        OneTime(std::string key);
        ~OneTime() {};

        virtual void encryptChar(char plainchar);
        virtual void decryptChar(char cipherchar);

        void reset();

    protected:
        std::string _key;
        int _idx = 0;
};


#endif