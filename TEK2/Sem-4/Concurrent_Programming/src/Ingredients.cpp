/*
** EPITECH PROJECT, 2021
** B-CCP-400-MPL-4-1-theplazza-corentin.petrau
** File description:
** Ingredients
*/

#include "../inc/Ingredients.hpp"

void Ingredients::restock()
{
    this->goat += 1;
    this->ham += 1;
    this->eggplant += 1;
    this->doe += 1;
    this->gruyere += 1;
    this->mushrooms += 1;
    this->steak += 1;
    this->tomatoe += 1;
}

bool Ingredients::regina()
{
    if (this->doe > 0 && this->tomatoe > 0 && this->gruyere > 0 && this->ham > 0 && this->mushrooms > 0) {
        this->doe -= 1;
        this->gruyere -= 1;
        this->tomatoe -= 1;
        this->ham -= 1;
        this->mushrooms -= 1;
        return (true);
    } else
        return (false);
}

bool Ingredients::margarita()
{
    if (this->doe > 0 && this->tomatoe > 0 && this->gruyere > 0) {
        this->doe -= 1;
        this->gruyere -= 1;
        return (true);
    } else
        return (false);
}

bool Ingredients::americana()
{
    if (this->doe > 0 && this->tomatoe > 0 && this->gruyere > 0 && this->steak > 0) {
        this->doe -= 1;
        this->gruyere -= 1;
        this->tomatoe -= 1;
        this->steak -= 1;
        return (true);
    } else
        return (false);
}

bool Ingredients::check_fantasia()
{
    if (this->doe > 0 && this->tomatoe > 0 && this->eggplant > 0 && this->goat > 0)
        return (true);
    else
        return (false);
}

bool Ingredients::check_regina()
{
    if (this->doe > 0 && this->tomatoe > 0 && this->gruyere > 0 && this->ham > 0 && this->mushrooms > 0)
        return (true);
    else
        return (false);
}

bool Ingredients::check_margarita()
{
    if (this->doe > 0 && this->tomatoe > 0 && this->gruyere > 0)
        return (true);
    else
        return (false);
}

bool Ingredients::check_americana()
{
    if (this->doe > 0 && this->tomatoe > 0 && this->gruyere > 0 && this->steak > 0)
        return (true);
    else
        return (false);
}

bool Ingredients::fantasia()
{
    if (this->doe > 0 && this->tomatoe > 0 && this->eggplant > 0\
    && this->goat > 0) {
        this->doe -= 1;
        this->tomatoe -= 1;
        this->eggplant -= 1;
        this->goat -= 1;
        return (true);
    } else
        return (false);
}