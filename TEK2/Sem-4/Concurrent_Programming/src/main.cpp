/*
** EPITECH PROJECT, 2020
** B-CCP-400-MPL-4-1-theplazza-corentin.petrau
** File description:
** main.cpp
*/

#include "../inc/inc.hpp"
#include "../inc/Reception.hpp"
#include "../inc/Kitchen.hpp"
#include "../inc/Logfile.hpp"
#include "../inc/Error.hpp"

int main(int ac, char **av)
{
    try {
        unlink("Pizzeria");
        Error err(ac, av);
        Logfile *log = new Logfile();
        Reception recep(av, log);
        recep.reception_loop();
        log->~Logfile();
    } catch(Exception &e) {
        std::cout << e.what() << std::endl;
        return(84);
    }
}