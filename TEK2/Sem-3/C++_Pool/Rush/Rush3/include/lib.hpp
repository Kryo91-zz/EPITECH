/*
** EPITECH PROJECT, 2020
** B-CPP-300-MPL-3-1-CPPrush3-lyvia.mallereau
** File description:
** lib.hpp
*/

#ifndef LIB_HPP_
    #define LIB_HPP_

    #include "../lib/data/Data.hpp"
    #include "../lib/data/DiskData.hpp"
    #include "../lib/data/ProcData.hpp"
    #include "../lib/data/CPUData.hpp"
    #include "../lib/data/MemoryData.hpp"
    #include "../lib/data/SysData.hpp"
    #include "templates.hpp"

    #include <string>
    #include <sys/utsname.h>
    #include <iostream>
    #include <algorithm>
    #include <stdexcept>
    #include <cerrno>
    #include <cstring>
    #include <dirent.h>
    #include <cstdio>
    #include <memory>
    #include <array>
    #include <regex>

    std::string string_exec(const char* cmd);
    std::string get_curr_date(void);

#endif