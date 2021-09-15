/*
** EPITECH PROJECT, 2020
** B-CPP-300-MPL-3-1-CPPrush3-lyvia.mallereau
** File description:
** CPUData.cpp
*/

#include "CPUData.hpp"

#include <regex>
#include <iterator>
#include <iostream>
#include <string>
#include <fstream>

int getIdleProcLoad(const std::string s)
{
    int load = 0;

    std::regex words_regex("[0-9]+");
    auto words_begin =
        std::sregex_iterator(s.begin(), s.end(), words_regex);
    auto words_end = std::sregex_iterator();

    for (std::sregex_iterator i = words_begin; i != words_end; ++i) {
        std::smatch match = *i;
        std::string match_str = match.str();
        load += std::stoi(match_str);
    }

    return (load);
}

int getWorkProcLoad(const std::string s)
{
    int load = 0;
    int idx = 0;;

    std::regex words_regex("[0-9]+");
    auto words_begin =
        std::sregex_iterator(s.begin(), s.end(), words_regex);
    auto words_end = std::sregex_iterator();

    for (std::sregex_iterator i = words_begin; i != words_end && idx < 3; ++i) {
        std::smatch match = *i;
        std::string match_str = match.str();
        load += std::stoi(match_str);
        idx++;
    }

    return (load);
}

void CPUData::updateCPULoad(void)
{
    std::string line;
    std::ifstream file("/proc/stat");
    int new_work_load, new_idle_load;

    if (file.is_open()) {
        getline(file, line);
        new_work_load = getWorkProcLoad(line);
        new_idle_load = getIdleProcLoad(line);
        int work_load_diff = new_work_load - this->work_load;
        int idle_load_diff = new_idle_load - this->idle_load;
        this->work_load = new_work_load;
        this->idle_load = new_idle_load;
        this->cpu_load = ((float)work_load_diff / (float)idle_load_diff) * 100;
        file.close();
    } else
        std::cerr << "/proc/stat: " << ": No such file or directory" << std::endl;
}

CPUData::CPUData(void)
{
    std::string line;
    std::ifstream file("/proc/stat");

    if (file.is_open()) {
        getline(file, line);
        this->work_load = getWorkProcLoad(line);
        this->idle_load = getIdleProcLoad(line);
        file.close();
    } else
        std::cerr << "/proc/stat: " << ": No such file or directory" << std::endl;
}

CPUData::~CPUData(void) {}

void CPUData::refreshData(void)
{
    this->updateCPULoad();
}

std::string CPUData::getData(void) const
{
    return "";
}