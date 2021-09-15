/*
** EPITECH PROJECT, 2020
** B-CPP-300-MPL-3-1-CPPrush3-lyvia.mallereau
** File description:
** ProcData.cpp
*/

#include "ProcData.hpp"

ProcData::ProcData(void)
{
    this->nb_processes = atoi(string_exec("ps -eo nlwp | tail -n +2 | awk '{ num_threads += $1 } END { print num_threads }'").c_str());
}

ProcData::~ProcData(void)
{
}

void ProcData::refreshData(void)
{
    this->nb_processes = atoi(string_exec("ps -eo nlwp | tail -n +2 | awk '{ num_threads += $1 } END { print num_threads }'").c_str());
}

std::string ProcData::getData(void) const
{
    return "";
}