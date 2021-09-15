/*
** EPITECH PROJECT, 2020
** B-CPP-300-MPL-3-1-CPPD17-corentin.petrau
** File description:
** OneTime.cpp
*/

#include "OneTime.hpp"

OneTime::OneTime(std::string key) :
    _key(key) {}

void OneTime::reset()
{
    this->_idx = 0;
}

void OneTime::encryptChar(char plainchar)
{
    int c = plainchar;
    int key = this->_key[this->_idx];
    int keyb = 0;
    int base = 0;

    if (plainchar >= 'A' && plainchar <= 'Z' || plainchar >= 'a' && plainchar <= 'z') {
        if (c > 96)
            base = 97;
        else
            base = 65;
        if (key > 96)
            keyb = 97;
        else
            keyb = 65;
        c = (c - base + (key - keyb)) % 26 + base;
    }
    COUT << (char)c;
    this->_idx = (this->_idx + 1) % this->_key.size();
}

void OneTime::decryptChar(char cipherchar)
{
    int c = cipherchar;
    int key = this->_key[this->_idx];
    int keyb = 0;
    int base = 0;

    if (cipherchar >= 'A' && cipherchar <= 'Z' || cipherchar >= 'a' && cipherchar <= 'z') {
        if (c > 96)
            base = 122;
        else
            base = 90;
        if (key > 96)
            keyb = 97;
        else
            keyb = 65;
        c = (c - base - (key - keyb)) % 26 + base;
    }
    COUT << (char)c;
    this->_idx = (this->_idx + 1) % this->_key.size();
}