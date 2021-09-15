/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPrush3-lyvia.mallereau
** File description:
** main-ncurses
*/

#include "GKrellm.hpp"
#include <iostream>
#include <string>
#include <algorithm>

const std::string WHITESPACE = " \n\r\t\f\v";

WINDOW *create_new_board(int height, int width, int start_y, int start_x)
{
    WINDOW	*win;

    if (!(win = newwin(height, width, start_y, start_x)))
        return (NULL);
    wattron(win, COLOR_PAIR(3));
    box(win, 0, 0);
    wattroff(win, COLOR_PAIR(3));
    return (win);
}

std::string rtrim(const std::string& s)
{
    size_t end = s.find_last_not_of(WHITESPACE);
    return (end == std::string::npos) ? "" : s.substr(0, end + 1);
}

void header(SysData data)
{
    std::string hostname = data.hostname;
    std::string machine_name = data.machine_name;
    std::string username = data.username;
    std::string curr_time = rtrim(data.curr_time);
    std::string proc_type = data.proc_type;
    std::string kernel = data.kernel_version;
    std::string distrib = data.distrib;
    std::string hostname1 = "Hostname : ";
    std::string machine_name1 = "Machine name : ";
    std::string username1 = "Username : ";
    std::string curr_time1 = "Current time : ";
    std::string proc_type1 = "Processor type : ";
    std::string kernel1 = "Kernel version : ";
    std::string distrib1 = "Distribution : ";
    WINDOW *header = create_new_board(7, 90, 0, 0);
    wattron(header, COLOR_PAIR(1));
    mvwprintw(header, 3, 1, "%s", hostname1.c_str());
    mvwprintw(header, 4, 1, "%s", username1.c_str());
    mvwprintw(header, 5, 1, "%s", machine_name1.c_str());
    mvwprintw(header, 4, 45, "%s", distrib1.c_str());
    mvwprintw(header, 5, 45, "%s", kernel1.c_str());
    wattroff(header, COLOR_PAIR(1));
    wattron(header, COLOR_PAIR(2));
    mvwprintw(header, 1, 1, "%s", curr_time1.c_str());
    mvwprintw(header, 2, 45, "%s", proc_type1.c_str());
    wattroff(header, COLOR_PAIR(2));
    mvwprintw(header, 3, 1 + strlen(hostname1.c_str()), "%s", hostname.c_str());
    mvwprintw(header, 4, 1 + strlen(username1.c_str()), "%s", username.c_str());
    mvwprintw(header, 5, 1 + strlen(machine_name1.c_str()), "%s", machine_name.c_str());
    mvwprintw(header, 1, 1 + strlen(curr_time1.c_str()), "%s", curr_time.c_str());
    mvwprintw(header, 2, 45 + strlen(proc_type1.c_str()), "%s", proc_type.c_str());
    mvwprintw(header, 4, 45 + strlen(distrib1.c_str()), "%s", distrib.c_str());
    mvwprintw(header, 5, 45+ strlen(kernel1.c_str()), "%s", kernel.c_str());
    wrefresh(header);
}

void disp_maps(string_map ligne)
{
    int lines = 2;
    int lignes = 0;
    int n = 1;
    lignes = ligne.size();
    WINDOW *name = create_new_board(lignes + 4, 45, 7, 0);
    WINDOW *name2 = create_new_board(lignes + 4, 45, 7, 45);
    for (auto it = ligne.begin(); it != ligne.end(); it++) {
        if (n == 1)
            n = 2;
        else
            n = 1;
        wattron(name, COLOR_PAIR(n));
        mvwprintw(name, lines, 1, (*it).first.c_str());
        wattroff(name, COLOR_PAIR(n));
        mvwprintw(name2, lines, 1, (*it).second.c_str());
        lines += 1;
    }
    wrefresh(name);
    wrefresh(name2);
}

void disp_ncurses(int tic __attribute__((unused)), SysData data)
{
    header(data);
    disp_maps(data.getMap());
}

void init_curse(void)
{
    initscr();
    start_color();
    use_default_colors();
    notimeout(stdscr, FALSE);
    keypad(stdscr, TRUE);
    noecho();
    cbreak();
    nodelay(stdscr, TRUE);
    curs_set(0);
    init_color(COLOR_RED, 0, 0, 355);
    init_pair(1, COLOR_CYAN, -1);
    init_pair(2, COLOR_BLUE, -1);
    init_pair(3, COLOR_MAGENTA, -1);
}