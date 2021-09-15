/*
** EPITECH PROJECT, 2020
** B-CPP-300-MPL-3-1-CPPrush3-lyvia.mallereau
** File description:
** IMonitorDisplay.hpp
*/

#ifndef IMONITOR_DISPLAY_HPP
    #define IMONITOR_DISPLAY_HPP

    #include <string>

    class IMonitorDisplay
    {
        public:
            IMonitorDisplay(void) {};
            ~IMonitorDisplay(void) {};
            const std::string NCURSES = "-ncurses";
            const std::string SFML = "-sfml";
    };

#endif