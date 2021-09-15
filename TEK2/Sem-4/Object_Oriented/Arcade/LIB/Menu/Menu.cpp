/*
** EPITECH PROJECT, 2021
** B-OOP-400-MPL-4-1-arcade-corentin.petrau
** File description:
** Menu
*/

#include "Menu.hpp"

const std::string WHITESPACE = " \n\r\t\f\v";

arcade::Menu::Menu(void)
{
}

std::pair<int, int> arcade::Menu::loop_menu(std::vector<std::string> lib, std::vector<std::string> game)
{
    arcade::selection s;
    this->size_lib = lib.size();
    this->size_game = game.size();
    init_curse();
    one_sec_loop(lib, game, s);
    if (this->quit != 0) {
        exit(0);
    }
    return (std::make_pair(this->y_lib-1, this->y_game-1));
}

void arcade::Menu::init_curse(void)
{
    initscr();
    start_color();
    use_default_colors();
    notimeout(stdscr, FALSE);
    keypad(stdscr, TRUE);
    noecho();
    curs_set(0);
    init_color(COLOR_RED, 0, 0, 355);
    init_pair(1, COLOR_CYAN, -1);
    init_pair(2, COLOR_BLUE, -1);
    init_pair(3, COLOR_MAGENTA, -1);
    clear();
}

void arcade::Menu::pseudo(void)
{
    int key = 0;

    while(alias.size() < 3) {
        key = getch();
        alias += key;
        mvwprintw(_header, 1, 50, "%s", alias.c_str());
    }
}

void arcade::Menu::one_sec_loop(std::vector<std::string> lib, std::vector<std::string> game, selection s)
{
    int key = 0;

    this->quit = 1;
    header();
    disp_maps(key, s, lib, game);
    readscore();
    refresh();
    while (key != 27 && key != 'q' && key != 'v') {
        header();
        disp_maps(key, s, lib, game);
        refresh();
        key = getch();
        if (key == 'p') {
            alias = "";
            pseudo();
        }
    }
    if (key == 'v')
        this->quit = 0;
    clear();
    endwin();
}


WINDOW *arcade::Menu::create_new_board(int height, int width, int start_y, int start_x)
{
    WINDOW	*win;

    if (!(win = newwin(height, width, start_y, start_x)))
        return (NULL);
    wattron(win, COLOR_PAIR(3));
    box(win, 0, 0);
    wattroff(win, COLOR_PAIR(3));
    return (win);
}

std::string arcade::Menu::rtrim(const std::string& s)
{
    size_t end = s.find_last_not_of(WHITESPACE);
    return (end == std::string::npos) ? "" : s.substr(0, end + 1);
}

const std::string arcade::Menu::currentDateTime()
{
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);

    return buf;
}

void arcade::Menu::header()
{
    std::string curr_time = currentDateTime();
    std::string username1 = "Username : ";
    std::string curr_time1 = "Current time : ";
    _header = create_new_board(3, 80, 0, 0);
    wattron(_header, COLOR_PAIR(1));
    mvwprintw(_header, 1, 5 + strlen(curr_time1.c_str()) + strlen(curr_time.c_str()), "%s", username1.c_str());
    wattroff(_header, COLOR_PAIR(1));
    wattron(_header, COLOR_PAIR(2));
    mvwprintw(_header, 1, 1, "%s", curr_time1.c_str());
    wattroff(_header, COLOR_PAIR(2));
    mvwprintw(_header, 1, 50, "%s", alias.c_str());
    mvwprintw(_header, 1, 1 + strlen(curr_time1.c_str()), "%s", curr_time.c_str());
    wrefresh(_header);
}

void arcade::Menu::select(int key, selection s)
{
    if (key == 'z' && this->y_lib > 1)
        this->y_lib -= 1;
    else if (key == 's' && this->y_lib < this->size_lib)
        this->y_lib += 1;
    else if (key == 259 && this->y_game > 1)
        this->y_game -= 1;
    else if (key == 258 && this->y_game < this->size_game)
        this->y_game += 1;
    mvwprintw(s.w_lib, this->y_lib, 1, "[");
    mvwprintw(s.w_lib, this->y_lib, 38, "]");
    mvwprintw(s.w_game, this->y_game, 1, "[");
    mvwprintw(s.w_game, this->y_game, 38, "]");
}

void arcade::Menu::readscore()
{
    std::fstream fp;
    std::string file;

    fp.open("./scores_pacman", std::ios::in);
    if (fp)
        for (long unsigned int i = 0; getline(fp, file); i++)
            score_pacman.push_back(file);
    fp.close();
    fp.open("./scores_nibbler", std::ios::in);
    if (fp)
        for (long unsigned int i = 0; getline(fp, file); i++)
            score_nibbler.push_back(file);
    fp.close();
}

void arcade::Menu::scores(WINDOW *score1, WINDOW *score2)
{
    int n = 1;
    int m = 2;
    for (long unsigned int it = 0; it < score_nibbler.size(); it+=1) {
        if (n == 1)
            n = 2;
        else
            n = 1;
        wattron(score1, COLOR_PAIR(n));
        mvwprintw(score1, it+1, 1, "%s", score_nibbler[it].c_str());
        wattroff(score1, COLOR_PAIR(n));
    }
    for (long unsigned int it = 0; it < score_pacman.size(); it+=1) {
        if (m == 1)
            m = 2;
        else
            m = 1;
        wattron(score2, COLOR_PAIR(m));
        mvwprintw(score2, it+1, 1, "%s", score_pacman[it].c_str());
        wattroff(score2, COLOR_PAIR(m));
    }
}

void arcade::Menu::disp_qna(WINDOW *qna)
{
    mvwprintw(qna, 1, 1, "Keys:");
    mvwprintw(qna, 2, 4, "\"z\" and \"s\" to select the library.");
    mvwprintw(qna, 3, 4, "\"up arrow\" and \"down arrow\" to select the game.");
    mvwprintw(qna, 4, 4, "\"y\" or \"u\" to swap graphical library at any moment.");
    mvwprintw(qna, 5, 4, "\"h\" or \"j\" to swap game at any moment.");
    mvwprintw(qna, 6, 4, "\"p\" to set up the username (3 characters)");
    mvwprintw(qna, 7, 4, "\"v\" to validate. ESCAPE or \"q\" to quit");
}

void arcade::Menu::disp_maps(int key, selection s, std::vector<std::string> lib, std::vector<std::string> game)
{
    WINDOW *name = create_new_board(2 + lib.size(), 40, 3, 0);
    WINDOW *name2 = create_new_board(2 + game.size(), 40, 3, 40);
    WINDOW *scoreboard = create_new_board(4, 40, 0, 80);
    int size = lib.size();
    if (game.size() > lib.size())
        size = game.size();
    WINDOW *qna = create_new_board(9, 80, size+5, 0);
    WINDOW *score1 = create_new_board(size+10, 20, 4, 80);
    WINDOW *score2 = create_new_board(size+10, 20, 4, 100);
    for (long unsigned int it = 0; it < lib.size(); it+=1)
        mvwprintw(name, it+1, 3, lib[it].c_str());
    for (long unsigned int it = 0; it < game.size(); it+=1)
        mvwprintw(name2, it+1, 3, game[it].c_str());
    s.w_game = name2;
    s.w_lib = name;
    wattron(scoreboard, COLOR_PAIR(3));
    mvwprintw(scoreboard, 1, 17, "SCORES");
    mvwprintw(scoreboard, 2, 6, "Nibbler");
    mvwprintw(scoreboard, 2, 27, "Pacman");
    wattroff(scoreboard, COLOR_PAIR(3));
    select(key, s);
    scores(score1, score2);
    disp_qna(qna);
    wrefresh(name);
    wrefresh(name2);
    wrefresh(scoreboard);
    wrefresh(score1);
    wrefresh(score2);
    wrefresh(qna);
}

extern "C" {
    arcade::Menu *menu(void) {
        return(new arcade::Menu());
    }
}
