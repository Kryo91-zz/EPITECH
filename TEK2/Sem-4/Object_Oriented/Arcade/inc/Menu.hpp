/*
** EPITECH PROJECT, 2021
** B-OOP-400-MPL-4-1-arcade-corentin.petrau
** File description:
** Menu
*/

#pragma once

#include "Include.hpp"

namespace arcade
{
    typedef struct window_s
    {
        char *print;
        WINDOW *line;
    } window_t;

    typedef struct page_s
    {
        window_t *page;
    } page_t;

    struct selection {
        int x;
        int y_lib;
        int y_gam;
        WINDOW *w_lib;
        WINDOW *w_game;
        std::vector<std::string> g;
        std::vector<std::string> l;
    };

    struct read;

    class Menu {
    public:
        Menu();
        ~Menu();
        void disp_ncurses();
        void init_curse(void);
        std::string get_name(void) {return(this->alias);}
        WINDOW *create_new_board(int height, int width, int start_y, int start_x);
        std::string rtrim(const std::string& s);
        void header();
        const std::string currentDateTime();
        void select(int key, selection s);
        void scores(WINDOW *score1, WINDOW *score2);
        void disp_maps(int key, selection s, std::vector<std::string> lib, std::vector<std::string> game);
        void one_sec_loop(std::vector<std::string> lib, std::vector<std::string> game, selection s);
        void disp_qna(WINDOW *qna);
        virtual std::pair<int, int> loop_menu(std::vector<std::string> lib, std::vector<std::string> game);
        void readscore(void);
        void pseudo(void);

        std::vector<std::string> score_pacman;
        std::vector<std::string> score_nibbler;
    protected:
    private:
        int y_lib = 1;
        int y_game = 1;
        int quit = 1;
        int size_lib = 0;
        int size_game = 0;
        std::string alias = "";
        WINDOW *_header;
    };
} // namespace arcade
