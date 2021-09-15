/*
** EPITECH PROJECT, 2020
** B-CCP-400-MPL-4-1-theplazza-alec.ferrari
** File description:
** lib/Lib.hpp
*/

#pragma once

#include "stdInclude.hpp"
#include "lib/std/SyntacticSugar.hpp"
#include "lib/std/Stopwatch.hpp"
#include "lib/std/Exception.hpp"

namespace lib
{
    std::string toUpper(const std::string src);
    std::string toLower(const std::string src);
    std::vector<std::string> stringSplit(std::string src, char delimiter);
    // int getMaybeInput(std::string &dest);
    // int getMaybeInput(void);

    template <typename T>
    size_t getPredIdx(const std::vector<T> arr, const std::function<bool (T, T)> predicate)
    {
        if (arr.size() == 0)
            throw std::out_of_range("getPredIdx can't search empty vector");

        size_t idx = 0;
        T saved = *arr.begin();
        for (auto it = arr.begin() + 1; it != arr.end(); it++) {
            if (predicate(saved, *it)) {
                saved = *it;
                idx = std::distance(arr.begin(), it);
            }
        }
        return idx;
    }
} // namespace lib

template <typename T>
std::ostream &operator<<(std::ostream &lhs, std::vector<T> &rhs)
{
    if (rhs.size() > 10) {
        lhs << "[\n\t";
        for (auto it = rhs.begin(); it + 1 != rhs.end(); it++) {
            lhs << *it;
            lhs << ",\n\t";
        }
        lhs << rhs[rhs.size() - 1] << "\n]";
        return lhs;
    }
    lhs << "[";
    for (auto it = rhs.begin(); it + 1 != rhs.end(); it++) {
        lhs << *it;
        lhs << ", ";
    }
    lhs << rhs[rhs.size() - 1] << "]";
    return lhs;
}

template <typename T, typename U>
std::ostream &operator<<(std::ostream &lhs, std::pair<T, U> &rhs)
{
    lhs << "{";
    lhs << rhs.first;
    lhs << ", ";
    lhs << rhs.second;
    lhs << "}";
    return lhs;
}

template <typename T, typename U>
std::ostream &operator<<(std::ostream &lhs, std::map<T, U> &rhs)
{
    lhs << "[";
    for (auto it = rhs.begin(); it + 1 != rhs.end(); it++) {
        lhs << "{" << it->first << ", " << it->second << "}";
    }
    auto tmp = rhs.end() - 1;
    lhs << "{" << tmp->first << ", " << tmp->second << "}";
    lhs << "]";
    return lhs;
}
