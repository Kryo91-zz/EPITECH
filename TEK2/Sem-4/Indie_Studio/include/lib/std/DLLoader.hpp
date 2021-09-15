/*
** EPITECH PROJECT, 2020
** B-OOP-400-MPL-4-1-arcade-alec.ferrari
** File description:
** DLLoader.hpp
*/

#pragma once

//#include <sys/types.h>
//#include <iostream>
//#include <memory>
//#include <vector>
//#include <algorithm>
//#include <dlfcn.h>
//
//void *dl_gc(const char *file, int mode, bool clear = false);
//
//namespace arcade
//{
//    template <typename T>
//    using EntryPointFunction = T *(*)(void);
//
//    template <typename T, typename F = EntryPointFunction<T>>
//    class DLLoader {
//        public:
//            DLLoader(std::string path): _path(path) {};
//            ~DLLoader(void) = default;
//            F getInstance(void) {
//                this->handle = dlopen(this->_path.c_str(), RTLD_LAZY);
//                if (!this->handle) {
//                    std::cerr << dlerror() << std::endl;
//                    throw std::runtime_error("Couldn't load dl at " + this->_path);
//                }
//                auto func_sym = reinterpret_cast<F>(dlsym(this->handle, "entryPoint"));
//                if (!func_sym) {
//                    std::cerr << dlerror() << std::endl;
//                    throw std::runtime_error("Couldn't get entryPoint symbol");
//                }
//                return func_sym;
//            }
//        private:
//            std::string _path;
//            void *handle;
//    };
//}