/*
** EPITECH PROJECT, 2020
** ex00
** File description:
** Picture.cpp
*/

#include "Picture.hpp"

Picture::Picture()
{
    this->data = "";
}

Picture::Picture(const std::string &file)
{
    this->getPictureFromFile(file);
}

Picture::~Picture() { }

bool Picture::getPictureFromFile(const std::string &file)
{
    char ch;
    std::ifstream fp;
    std::string content;

    fp.open(file.c_str(), std::fstream::in);
    if (!fp) {
        this->data = "ERROR";
        return false;
    }
    while(fp.eof()==0) {
        ch = (char) fp.get();
        if(fp.eof()==0)
            content += ch;
    }
    this->data = content;
    fp.close();
    return true;
}