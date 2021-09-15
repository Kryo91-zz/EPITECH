/*
** EPITECH PROJECT, 2020
** ex00
** File description:
** Picture.hpp
*/

#ifndef PICTUREH
#define PICTUREH

#include <iomanip>
#include <fstream>
#include <iostream>
#include <string>
#include <cstring>

class Picture
{
    public:
        Picture();
        ~Picture();
        Picture(const Picture &other);
        Picture(const std::string &file);

        std::string data;

        bool getPictureFromFile(const std::string &file);

        Picture &operator=(const Picture &other);
};

#endif