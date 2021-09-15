/*
** EPITECH PROJECT, 2020
** B-CPP-300-MPL-3-1-CPPrush3-lyvia.mallereau
** File description:
** Data.hpp
*/

#ifndef DATA_HPP_
    #define DATA_HPP_

    #include <string>
    #include <sys/utsname.h>
    #include <iostream>
    #include <algorithm>
    #include <stdexcept>
    #include <cerrno>
    #include <cstring>
    #include <dirent.h>
    #include <cstdio>
    #include <memory>
    #include <array>

    class IMonitorModule
    {
        public:
            virtual void refreshData(void) = 0;
            virtual std::string getData(void) const = 0;
    };

#endif