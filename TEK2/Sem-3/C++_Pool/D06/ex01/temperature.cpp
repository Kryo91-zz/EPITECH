/*
** EPITECH PROJECT, 2020
** temperature.cpp
** File description:
** temperature
*/

#include <string>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <iomanip>

int main(void)
{
    float temp = 0;
    std::string name;

    std::cin >> temp;
    std::cin >> name;
    char const *str = name.c_str();

    if (strcmp(str, "Celsius") == 0) {
        temp =  (temp * (9.0/5.0)) + 32;
        std::cout << std::right << std::setw(16) << std::fixed << std::setprecision(3) << temp << std::setw(16) << "Fahrenheit" << std::endl;
    } 
    if (strcmp(str, "Fahrenheit") == 0) {
        temp =  5.0/9.0 * (temp - 32);
        std::cout << std::right << std::setw(16) << std::fixed << std::setprecision(3) << temp << std::setw(16) << "Celsius" << std::endl;
    }
}