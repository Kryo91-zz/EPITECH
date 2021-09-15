/*
** EPITECH PROJECT, 2021
** B-CCP-400-MPL-4-1-theplazza-corentin.petrau
** File description:
** Error
*/

#include "../inc/Error.hpp"

Error::Error(int nb, char **tab)
{
    size_t pos;
    if (nb != 4)
        throw Exception("Not enough argument to continue");

    if (std::stod(tab[1], &pos) <= 0)
        throw Exception("Invalid multiplier");

    if (std::stoul(tab[2], &pos) < 1)
        throw Exception("Number should be non-null and positive");

    if (std::chrono::milliseconds{std::stoul(tab[3], &pos)} < std::chrono::milliseconds(1))
        throw Exception("Invalid restock time, should be non-null and positive");
}

Error::~Error()
{
}
