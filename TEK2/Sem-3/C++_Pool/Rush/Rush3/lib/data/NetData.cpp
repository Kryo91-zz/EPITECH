/*
** EPITECH PROJECT, 2020
** B-CPP-300-MPL-3-1-CPPrush3-lyvia.mallereau
** File description:
** NetData.cpp
*/

#include "NetData.hpp"
#include "lib.hpp"

NETData::NETData()
{
    const std::string cat_res = string_exec("cat /proc/net/dev");
    std::regex ReceiveRegex("(wlp.*):\\s+(\\d+\\s+)(\\d+\\s+)");
    std::regex EmitRegex("(wlp.*):(\\s+\\d+){8}(\\s+\\d+)(\\s+\\d+)");
    std::smatch match;

    if (std::regex_search(cat_res.begin(), cat_res.end(), match, ReceiveRegex)) {
        this->bytes_receive =  std::stoi(match[2]);
        this->packets_receive =  std::stoi(match[3]);
    }
    if (std::regex_search(cat_res.begin(), cat_res.end(), match, EmitRegex)) {
        this->bytes_transmit =  std::stoi(match[3]);
        this->packets_transmit =  std::stoi(match[4]);
    }
    if (std::regex_search(cat_res.begin(), cat_res.end(), match, ReceiveRegex)) {
        this->name = match[1];
    }
}

NETData::~NETData() {}

void NETData::refreshData(void)
{
    const std::string cat_res = string_exec("cat /proc/net/dev");
    std::regex ReceiveRegex("(wlp.*):\\s+(\\d+\\s+)(\\d+\\s+)");
    std::regex EmitRegex("(wlp.*):(\\s+\\d+){8}(\\s+\\d+)(\\s+\\d+)");
    std::smatch match;

    if (std::regex_search(cat_res.begin(), cat_res.end(), match, ReceiveRegex)) {
        this->bytes_receive =  std::stoi(match[2]);
        this->packets_receive =  std::stoi(match[3]);
    }
    if (std::regex_search(cat_res.begin(), cat_res.end(), match, EmitRegex)) {
        this->bytes_transmit =  std::stoi(match[3]);
        this->packets_transmit =  std::stoi(match[4]);
    }
    if (std::regex_search(cat_res.begin(), cat_res.end(), match, ReceiveRegex)) {
        this->name = match[0];
    }
}

std::string NETData::getData(void) const {return "";}
