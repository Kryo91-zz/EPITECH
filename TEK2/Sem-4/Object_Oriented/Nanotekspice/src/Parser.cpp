/*
** EPITECH PROJECT, 2020
** B-OOP-400-MPL-4-1-tekspice-lyvia.mallereau
** File description:
** Parser.cpp
*/

#include "Parser.hpp"

namespace nts
{
    std::vector <std::pair<std::string, std::string>> Parser::getchipsets(std::vector<std::string> tab)
    {
        std::vector <std::pair<std::string, std::string>> chipsets;
        std::regex reg ("^(.(.+)?)( ([ \t]+)?)(.(.+)?)$");
        std::string type;
        std::string name;
        std::string test_tab[21] = {
            "clock", "input", "output",
            "logger", "false", "true",
            "2716", "4001", "4008",
            "4011", "4013", "4017",
            "4030", "4040", "4069",
            "4071", "4081", "4094",
            "4512", "4514", "4801"
        };

        for (long unsigned int i = 1; tab[i] != ".links:"; i++) {
            if (i + 2 >= tab.size() || std::regex_match(tab[i], reg) == false) {
                throw (Exception("syntax of the link isn't good"));
            }
            type = tab[i].substr(0, tab[i].find_first_of(" \n\r\t\f\v"));
            name = tab[i].substr(tab[i].find_last_of(" \n\r\t\f\v") + 1);
            bool t = false;
            for (int i = 0; i < 21 && !t; i++)
                if (type == test_tab[i])
                    t = true;
            if (!t)
                throw (Exception("Unknown chipset type"));
            chipsets.push_back(std::make_pair(type, name));
        }
        if (chipsets.size() == 0) {
            throw (Exception("No chipsets declared"));
        }
        std::cout << "\n";
        return(chipsets);
    }

    std::vector<std::pair<std::pair<std::string, int>, std::pair<std::string, int>>> Parser::getlinks(std::vector<std::string> tab)
    {
        std::vector<std::pair<std::pair<std::string, int>, std::pair<std::string, int>>> links;
        std::regex reg ("^(.(.+)?):([0-9]([0-9]+)?)( ([ \t]+)?)(.(.+)?):([0-9]([0-9]+)?)$");
        long unsigned int i = 0;
        std::string name;
        std::string name2;
        int nbr;
        int nbr2;


        while(tab[i] != ".links:") {
            i+=1;
            if (i >= tab.size() - 1)
                throw(Exception("no links"));
        }
        i+=1;
        for (; i < tab.size(); i++) {
            if (std::regex_match(tab[i], reg) == false)
                throw (Exception("Syntax of the links isn't good"));
            name = tab[i].substr(0, tab[i].find_first_of(":"));
            name2 = tab[i].substr(tab[i].find_last_of(" \n\r\t\f\v") + 1, tab[i].find_last_of(":") - (tab[i].find_last_of(" \n\r\t\f\v") + 1));
            nbr = atoi(tab[i].substr(tab[i].find_first_of(":") + 1, tab[i].find_first_of(" \n\r\t\f\v") - (tab[i].find_first_of(":") + 1)).c_str());
            nbr2 = atoi(tab[i].substr(tab[i].find_last_of(":") + 1).c_str());
            links.push_back(std::make_pair(std::make_pair(name, nbr), std::make_pair(name2, nbr2)));
        }
        return(links);
    }

    std::vector<std::string> Parser::readfile(std::string filepath)
    {
        std::string line;
        std::ifstream file;
        std::vector<std::string> tab;

        file.open(filepath);
        if (file.is_open() == false)
            throw (Exception("Couldn't read file"));
        while(std::getline(file, line)) {
            line.erase(0, line.find_first_not_of(" \n\r\t\f\v"));
            line.erase(line.find_last_not_of(" \n\r\t\f\v") + 1);
            if (line[0] != '#' && line[0] != '\0')
                tab.push_back(line);
        }
        file.close();
        if (tab.empty())
            throw (Exception("File is empty"));
        if (tab[0] != ".chipsets:")
            throw (Exception("First expression wasn't \".chipsets:\""));
        return(tab);
    }

    Parser::Parser(std::string file)
    {
        std::vector<std::string> tab = readfile(file);
        std::vector<std::pair<std::string, std::string>> chipsets = getchipsets(tab);
        std::vector<std::pair<std::pair<std::string, int>, std::pair<std::string, int>>> links = getlinks(tab);
    }
} // namespace nts