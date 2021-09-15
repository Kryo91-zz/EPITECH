/*
** EPITECH PROJECT, 2020
** B-OOP-400-MPL-4-1-arcade-alec.ferrari
** File description:
** DLLoader.cpp
*/

#include "lib/std/DLLoader.hpp"

//void close_dl(void) __attribute__((destructor));
//
//void *dl_gc(const char *file, int mode, bool clear)
//{
//    static std::vector<void *> vec;
//    if (clear) {
//        for (auto &&h : vec) {
//            dlclose(h);
//        }
//        return nullptr;
//    }
//    void *h = dlopen(file, mode);
//    if (h)
//        vec.push_back(h);
//    return h;
//}
//
//void close_dl(void)
//{
//    dl_gc("", 0, true);
//    std::cout << "Dynamic libraries garbage collected" << std::endl;
//}