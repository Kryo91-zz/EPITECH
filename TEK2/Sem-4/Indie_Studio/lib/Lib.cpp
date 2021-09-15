/*
** EPITECH PROJECT, 2020
** B-CCP-400-MPL-4-1-theplazza-alec.ferrari
** File description:
** Lib.cpp
*/

#include "lib/Lib.hpp"

namespace lib
{
    std::string toUpper(const std::string src)
    {
        std::string res = "";

        for (auto &&i : src) {
            res.push_back(toupper(i));
        }
        return res;
    }

    std::string toLower(const std::string src)
    {
        std::string res = "";

        for (auto &&i : src) {
            res.push_back(tolower(i));
        }
        return res;
    }

    std::vector<std::string> stringSplit(std::string src, char delimiter)
    {
        std::stringstream input(src);
        std::string segment;
        std::vector<std::string> seglist;

        while(std::getline(input, segment, delimiter)) {
            seglist.push_back(segment);
        }
        return (seglist);
    }

    /*int getMaybeInput(std::string &dest)
    {
        fd_set rfds;
        struct timeval tv = {.tv_sec = 0, .tv_usec = 0};

        FD_ZERO(&rfds);
        FD_SET(0, &rfds);
        if (select(FD_SETSIZE, &rfds, NULL, NULL, &tv) == -1) {
            perror("select");
            return 0;
        }
        if (FD_ISSET(0, &rfds)) {
            std::string str;
            if (!getline(std::cin, str))
                return 0;
            dest = str;
            return 1;
        }
        return -1;
    }

    int getMaybeInput(void)
    {
        fd_set rfds;
        struct timeval tv = {.tv_sec = 0, .tv_usec = 0};

        FD_ZERO(&rfds);
        FD_SET(0, &rfds);
        if (select(FD_SETSIZE, &rfds, NULL, NULL, &tv) == -1) {
            perror("select");
            return 0;
        }
        if (FD_ISSET(0, &rfds)) {
            std::string str;
            if (!getline(std::cin, str))
                return 0;
            return 1;
        }
        return -1;
    }*/
} // namespace lib
