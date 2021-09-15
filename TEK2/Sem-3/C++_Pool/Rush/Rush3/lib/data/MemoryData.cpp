/*
** EPITECH PROJECT, 2020
** B-CPP-300-MPL-3-1-CPPrush3-lyvia.mallereau
** File description:
** MemoryData.cpp
*/

#include "MemoryData.hpp"
#include "lib.hpp"

MemoryData::MemoryData(void)
{
    const std::string cat_res = string_exec("cat /proc/meminfo");

    std::regex MemTotalRegex("(MemTotal:\\s+)" "(\\d+)" "(\\skB)");
    float MemTotal = 1;
    std::regex MemFreeRegex("(MemFree:\\s+)" "(\\d+)" "(\\skB)");
    float MemFree = 0.5;
    std::regex SwapTotalRegex("(SwapTotal:\\s+)" "(\\d+)" "(\\skB)");
    float SwapTotal = 1;
    std::regex SwapFreeRegex("(SwapFree:\\s+)" "(\\d+)" "(\\skB)");
    float SwapFree = 0.5;
    std::smatch match;

    if (std::regex_search(cat_res.begin(), cat_res.end(), match, MemTotalRegex)) {
        MemTotal = std::stoi(match[2]);
    }
    if (std::regex_search(cat_res.begin(), cat_res.end(), match, MemFreeRegex)) {
        MemFree = std::stoi(match[2]);
    }
    if (std::regex_search(cat_res.begin(), cat_res.end(), match, SwapTotalRegex)) {
        SwapTotal = std::stoi(match[2]);
    }
    if (std::regex_search(cat_res.begin(), cat_res.end(), match, SwapFreeRegex)) {
        SwapFree = std::stoi(match[2]);
    }

    this->ram_ratio = (1 - (MemFree / MemTotal)) * 100;
    this->swap_ratio = (1 - (SwapFree / SwapTotal)) * 100;
}

MemoryData::~MemoryData(void) {}

void MemoryData::refreshData(void)
{
    const std::string cat_res = string_exec("cat /proc/meminfo");

    std::regex MemTotalRegex("(MemTotal:\\s+)" "(\\d+)" "(\\skB)");
    float MemTotal = 1;
    std::regex MemFreeRegex("(MemFree:\\s+)" "(\\d+)" "(\\skB)");
    float MemFree = 1;
    std::regex SwapTotalRegex("(SwapTotal:\\s+)" "(\\d+)" "(\\skB)");
    float SwapTotal = 1;
    std::regex SwapFreeRegex("(SwapFree:\\s+)" "(\\d+)" "(\\skB)");
    float SwapFree = 1;
    std::smatch match;

    if (std::regex_search(cat_res.begin(), cat_res.end(), match, MemTotalRegex)) {
        MemTotal = std::stoi(match[2]);
    }
    if (std::regex_search(cat_res.begin(), cat_res.end(), match, MemFreeRegex)) {
        MemFree = std::stoi(match[2]);
    }
    if (std::regex_search(cat_res.begin(), cat_res.end(), match, SwapTotalRegex)) {
        SwapTotal = std::stoi(match[2]);
    }
    if (std::regex_search(cat_res.begin(), cat_res.end(), match, SwapFreeRegex)) {
        SwapFree = std::stoi(match[2]);
    }

    this->ram_ratio = (1 - (MemFree / MemTotal)) * 100;
    this->swap_ratio = (1 - (SwapFree / SwapTotal)) * 100;
}

std::string MemoryData::getData(void) const
{
    return "";
}