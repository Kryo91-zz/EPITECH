/*
** EPITECH PROJECT, 2021
** B-OOP-400-MPL-4-1-arcade-corentin.petrau
** File description:
** ncurse
*/

#include "ncurse.hpp"

arcade::Ncurse::Ncurse()
{
}

void arcade::Ncurse::init()
{
    initscr();
    start_color();
    use_default_colors();
    notimeout(stdscr, FALSE);
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);
    noecho();
    curs_set(0);
    init_color(COLOR_RED, 0, 0, 355);
    init_pair(1, COLOR_CYAN, -1);
    init_pair(2, COLOR_BLUE, -1);
    init_pair(3, COLOR_MAGENTA, -1);
    _window = newwin(70, 70, 0, 0);
    clear();
}

void arcade::Ncurse::stop()
{
    clear();
    refresh();
    endwin();
}

void arcade::Ncurse::draw(GameObject &entity)
{
    std::fstream myfile;
    std::string line;
    std::string name;

    if (entity.type == arcade::GameObject::ObjectType::SPRITE) {
        name = entity.sprite_src + ".txt";
        myfile.open(name, std::ios::in);
        if (myfile) {
            getline(myfile, line);
            this->block = line;
        }
        myfile.close();

        mvwprintw(_window, entity.position.x, entity.position.y, this->block.c_str());
    }
}

std::vector<arcade::Input::Key> arcade::Ncurse::get_input()
{
    int key = getch();
    std::vector<arcade::Input::Key> ididntwanttodothis;
    switch (key)
    {
        case 'z':
            ididntwanttodothis.push_back(arcade::Input::Z);
            break;
        case 'q':
            ididntwanttodothis.push_back(arcade::Input::Q);
            break;
        case 's':
            ididntwanttodothis.push_back(arcade::Input::S);
            break;
        case 'd':
            ididntwanttodothis.push_back(arcade::Input::D);
            break;
        case KEY_UP:
            ididntwanttodothis.push_back(arcade::Input::Up);
            break;
        case KEY_DOWN:
            ididntwanttodothis.push_back(arcade::Input::Down);
            break;
        case KEY_LEFT:
            ididntwanttodothis.push_back(arcade::Input::Left);
            break;
        case KEY_RIGHT:
            ididntwanttodothis.push_back(arcade::Input::Right);
            break;
        case 'r':
            ididntwanttodothis.push_back(arcade::Input::R);
            break;
        case 'v':
            ididntwanttodothis.push_back(arcade::Input::V);
            break;
        case 'm':
            ididntwanttodothis.push_back(arcade::Input::M);
            break;
        case 'y':
            ididntwanttodothis.push_back(arcade::Input::Y);
            break;
        case 'u':
            ididntwanttodothis.push_back(arcade::Input::U);
            break;
        case 'h':
            ididntwanttodothis.push_back(arcade::Input::H);
            break;
        case 'j':
            ididntwanttodothis.push_back(arcade::Input::J);
            break;
    }
    return(ididntwanttodothis);
}

void arcade::Ncurse::clear(void)
{
    // clear();
}

void arcade::Ncurse::display(void)
{
    wrefresh(_window);
}

extern "C" {
    arcade::IGraphicalLibrary *entryPoint(void) {
        return(new arcade::Ncurse());
    }
}