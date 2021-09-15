/*
** EPITECH PROJECT, 2020
** B-CCP-400-MPL-4-1-theplazza-corentin.petrau
** File description:
** Reception.cpp
*/

#include "../inc/Reception.hpp"
#include "../inc/IPC.hpp"
#include "../inc/Process.hpp"


Reception::Reception(char **tab, Logfile *log)
{
    size_t pos;
    this->_log = log;

    this->_cooking_time_multiplier = std::stod(tab[1], &pos);

    this->_nb_cooks = std::stoul(tab[2], &pos);

    this->_time = std::chrono::milliseconds{std::stoul(tab[3], &pos)};
}

void Reception::Take_order()
{
    this->_pizza.clear();
    this->_nbPizza.clear();
    this->_size.clear();
    if (this->_order == "end" || this->_order == "quit") {
        this->_log->~Logfile();
        this->_end = true;
    }
    Get_order();
}

void Reception::Get_order()
{
    if (this->_end == true)
        return;
    size_t current = 0;
    size_t previous = 0;
    std::string tmp;
    std::string Wpizza = "Your pizza : ";
    std::string Wsize = "Your size : ";
    std::string Wquantity = "Quantity : ";
    this->_order = this->_order + " ";
    std::vector<std::string> vec_tmp = split_string();
    for (size_t i = 0; i < vec_tmp.size(); i++) {
    current = vec_tmp[i].find_first_of(" ");
        while (current != std::string::npos) {
            tmp = vec_tmp[i].substr(previous, current - previous);
            if (tmp == "margarita" || tmp == "americana" || tmp == "fantasia" || tmp == "regina")
                this->_pizza.push_back(tmp);
            else if (tmp == "S" || tmp == "M" || tmp == "L" || tmp == "XL" || tmp == "XXL")
                this->_size.push_back(tmp);
            else if (tmp != "\0") {
                tmp = tmp.substr(1);
                this->_nbPizza.push_back(atoi(tmp.c_str()));
            }
            tmp.clear();
            previous = current + 1;
            current = vec_tmp[i].find_first_of(" ;", previous);
        }
    }
    vec_tmp.clear();
    if (this->_pizza.size() != this->_size.size() || this->_pizza.size() != this->_nbPizza.size()) {
        std::cout << "Sorry but your order is wrong, please can you retry." << std::endl;
        this->_pizza.clear();
        this->_nbPizza.clear();
        this->_size.clear();
        this->_error = true;
        return ;
    }
    std::cout << "-----------------------------" << std::endl;
    std::cout << "           TICKETS           " << std::endl;
    std::cout << "-----------------------------" << std::endl;
    for (size_t i = 0; this->_pizza.size() > i; i++)
    {
        std::cout << "Your Pizza : " << this->_pizza[i].c_str() << std::endl;
        std::cout << "Your Size : " << this->_size[i].c_str() << std::endl;
        std::cout << "Number : " << this->_nbPizza[i] << std::endl;
    }
    std::cout << "----------------------------\n" << std::endl;
    this->_log->CommandMessage();
    for (size_t i = 0; this->_pizza.size() > i; i++)
    {
        Wpizza += this->_pizza[i];
        Wsize += this->_size[i];
        Wquantity += std::to_string(this->_nbPizza[i]);
        this->_log->LMessage(Wpizza);
        this->_log->LMessage(Wsize);
        this->_log->LMessage(Wquantity);
        Wpizza.clear();
        Wsize.clear();
        Wquantity.clear();
        Wpizza = "Your pizza : ";
        Wsize = "Your size : ";
        Wquantity = "Quantity : ";
    }
    this->_error = false;
    this->_log->EndCommandMessage();
}

std::vector<std::string> Reception::get_pizza()
{
    return this->_pizza;
}

std::vector<std::string> Reception::get_size()
{
    return this->_size;
}

std::vector<int> Reception::get_nbPizza()
{
    return this->_nbPizza;
}

double Reception::get_multiplier()
{
    return this->_cooking_time_multiplier;
}

size_t Reception::get_nbcook()
{
    return this->_nb_cooks;
}

std::chrono::milliseconds Reception::get_time()
{
    return this->_time;
}

std::vector<std::string> Reception::split_string()
{
    std::stringstream ss(this->_order);
    std::string sousChaine;
    std::vector<std::string> tmp;
    while (getline(ss, sousChaine, ','))
        tmp.push_back(sousChaine);
    return tmp;
}

void Reception::reception_loop()
{
    IPC ipc;
    while (this->End_command() == false) {
        ipc.prog_socket();
        this->_order.clear();
        this->client = ipc.read_on_in();
        if (this->client == 0) {
            this->_order = ipc.get_respond();
            Take_order();
        }
        while (this->Error_command() == true) {
            this->_order.clear();
            this->client = ipc.read_on_in();
            if (this->client == 0) {
                this->_order = ipc.get_respond();
                Take_order();
            }
            if (this->_end == true)
                exit(0);
            if (this->_error == false)
                break;
        }
        if (this->End_command() == true)
            break;
        this->_order.clear();
        for (size_t i =  0; i < this->_pizza.size(); i++) {
            Kitchen kitch(this->_cooking_time_multiplier, this->_nb_cooks, this->_time);
            Process proc;
            if (proc.getPid() == 0) {
                for (int nb = 0; nb < this->_nbPizza[i]; nb++) {
                    kitch.cooking(this->_pizza[i], this->_size[i]);
                    this->client = ipc.read_kitchen();
                    if (this->client == 1) {
                        this->_order = ipc.get_respond();
                        this->_order += " number : " + std::to_string(nb+1);
                        this->_log->LMessage(this->_order);
                        std::cout << this->_order << std::endl;
                        this->_order.clear();
                    }
                }
                exit(0);
            }
            proc.wait();
            this->_order.clear();
        }
        this->_order.clear();
    }
}