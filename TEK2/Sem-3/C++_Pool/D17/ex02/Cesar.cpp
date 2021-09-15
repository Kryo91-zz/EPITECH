/*
** EPITECH PROJECT, 2020
** B-CPP-300-MPL-3-1-CPPD17-corentin.petrau
** File description:
** Cesar.cpp
*/

#include "Cesar.hpp"

void Cesar::reset()
{
    this->_decrypte = 3;
    this->_encrypte = 3;
}

void Cesar::encryptChar(char plainchar)
{
    int c = plainchar;

    if (plainchar >= 'A' && plainchar <= 'Z') {
        c += this->_encrypte%26;
        if (c > 'Z')
            c -= 26;
    }
    if (plainchar >= 'a' && plainchar <= 'z') {
        c += this->_encrypte%26;
        if (c > 'z')
            c -= 26;
    }
    this->_encrypte += 1;
    COUT << (char)c;
}

void Cesar::decryptChar(char cipherchar)
{
    int c = cipherchar;

    if (cipherchar >= 'A' && cipherchar <= 'Z') {
        c -= this->_decrypte%26;
        if (c < 'A')
            c += 26;
    }
    if (cipherchar >= 'a' && cipherchar <= 'z') {
        c -= this->_decrypte%26;
        if (c < 'a')
            c += 26;
    }
    this->_decrypte += 1;
    COUT << (char)c;
}