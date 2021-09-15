/*
** EPITECH PROJECT, 2020
** B-CCP-400-MPL-4-1-theplazza-corentin.petrau
** File description:
** Reception.hpp
*/

#pragma once

#include "inc.hpp"
#include "Kitchen.hpp"
#include "Logfile.hpp"

class Reception
{
    protected:
        std::vector<std::string> _pizza;
        std::vector<std::string> _size;
        std::vector<int> _nbPizza;
        std::string _order;
        double _cooking_time_multiplier;
        size_t _nb_cooks;
        std::chrono::milliseconds _time;
        int client = 0;
        Logfile *_log;

    private:
        bool _end = false;
        bool _error = false;

    public:
        Reception(char **tab, Logfile *log);
        ~Reception() {};
        void create_socket();
        void Take_order();
        void Get_order();
        bool End_command() {return this->_end;};
        bool Error_command() {return this->_error;};
        std::vector<std::string> get_pizza();
        std::vector<int> get_nbPizza();
        std::vector<std::string> get_size();
        double get_multiplier();
        size_t get_nbcook();
        std::chrono::milliseconds get_time();
        std::vector<std::string> split_string();
        void reception_loop();
};
