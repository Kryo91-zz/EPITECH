/*
** EPITECH PROJECT, 2020
** B-CPP-300-MPL-3-1-CPPrush3-lyvia.mallereau
** File description:
** main.cpp
*/

#include "GKrellm.hpp"

void print_data(int tic __attribute__((unused)), SysData data)
{
    // print<std::string>(get_curr_date());
    // print<std::string>(string_exec( "ps -e | wc -l"));
    print<std::string>(data.getData());
}

void start_ncurses(void)
{
    SysData data;
    init_curse();
    one_sec_loop(
        disp_ncurses, // en ncurses
        data
    );
}

int main(int argc __attribute__((unused)), const char *argv[])
{
    IMonitorDisplay display_mode;

    if (argc == 2 && (std::string(argv[1]) == display_mode.SFML))
        start_sfml();
    else
        start_ncurses();
}