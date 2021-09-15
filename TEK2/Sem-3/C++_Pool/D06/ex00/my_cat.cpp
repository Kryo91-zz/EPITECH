/*
** EPITECH PROJECT, 2020
** my_cat.cpp
** File description:
** recoding cat
*/

#include <string>
#include <fstream>
#include <iostream>
#include <cstdlib>

int main(int ac, char **av)
{
    std::string line;
    

    if (av[1] == NULL) {
        std::cerr << "my_cat: Usage: ./my_cat file [...]" << std::endl;
        return (0);
    }
    for (int i = 1; av[i]; ++i) {
        std::ifstream file_name (av[i]);
        if (file_name.is_open()) {
            while (getline(file_name, line))
                std::cout << line << '\n';
            file_name.close();
        } else
            std::cerr << "my_cat: " << av[i] << ": No such file or directory" << std::endl;
    }
    return (0);
}