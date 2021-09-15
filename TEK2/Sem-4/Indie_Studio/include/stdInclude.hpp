/*
** EPITECH PROJECT, 2020
** B-CCP-400-MPL-4-1-theplazza-alec.ferrari
** File description:
** stdInclude.hpp
*/

#pragma once

#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>
#include <memory>
#include <fstream>
#include <exception>
#include <regex>
#include <sstream>
#include <string.h>
#include <thread>
#include <functional>
#include <queue>
#include <mutex>
#include <condition_variable>
#include <typeinfo>
#include <set>
#include <raylib.h>
#include <raymath.h>
#include <filesystem>
#include <bitset>
#include <array>

#ifndef WIN32
	#define UNUSED __attribute__((unused))
#else
	#define UNUSED /* blank */
#endif

typedef unsigned int id_t;

template <typename T>
using ref = std::reference_wrapper<T>;