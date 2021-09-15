/*
** EPITECH PROJECT, 2020
** B-CPP-300-MPL-3-1-CPPrush3-lyvia.mallereau
** File description:
** SysData.cpp
*/

#include "SysData.hpp"

std::string get_curr_date(void)
{
    time_t t;
    struct tm *tt;
    time(&t);
    tt = localtime(&t);
    return (std::string(asctime(tt)));
}

std::string get_distrib(void)
{
    const std::string release_details = string_exec("cat /etc/lsb-release");
    std::regex rgx(".*DISTRIB_DESCRIPTION=\"(.*)\".*");
    std::smatch match;

    if (std::regex_search(release_details.begin(), release_details.end(), match, rgx))
        return match[1];
    return std::string("");
}

SysData::SysData(void)
{
    struct utsname data;
    char buffer[101];

    if (uname(&data) < 0)
        throw std::runtime_error("uname func failed");

    memset(buffer, 0, 101);
    if (gethostname(buffer, 100) >= 0)
        this->hostname = std::string(buffer);
    memset(buffer, 0, 101);
    if (getlogin_r(buffer, 100) >= 0)
        this->username = std::string(buffer);
    this->proc_type = data.machine;
    this->curr_time = get_curr_date();
    this->machine_name = data.nodename;
    this->kernel_version = data.release;
    this->distrib = std::string(data.sysname) + " " + get_distrib();
    this->_map = {
        {"Nb of proc processes", std::to_string(this->proc_data.nb_processes)},
        {"Number of users", std::to_string(this->proc_data.nb_users)},
        {"CPU load", std::to_string(this->cpu_data.cpu_load)},
        {"RAM used", std::to_string(this->memory_data.ram_ratio)},
        {"Swap used", std::to_string(this->memory_data.swap_ratio)},
        {"WireLess Protocol Name", this->net_data.name},
        {"Emitted bytes", std::to_string(this->net_data.bytes_transmit)},
        {"Emitted packets", std::to_string(this->net_data.packets_transmit)},
        {"Received bytes", std::to_string(this->net_data.bytes_receive)},
        {"Received packets", std::to_string(this->net_data.packets_receive)}
    };
}

SysData::~SysData(void)
{
}

void SysData::refreshData(void)
{
    char buffer[101];

    memset(buffer, 0, 101);
    if (gethostname(buffer, 100) >= 0)
        this->hostname = std::string(buffer);
    memset(buffer, 0, 101);
    if (getlogin_r(buffer, 100) >= 0)
        this->username = std::string(buffer);
    this->curr_time = get_curr_date();

    this->disk_data.refreshData();
    this->proc_data.refreshData();
    this->cpu_data.refreshData();
    this->memory_data.refreshData();
    this->_map = {
        {"Nb of proc processes", std::to_string(this->proc_data.nb_processes)},
        {"Number of users", std::to_string(this->proc_data.nb_users)},
        {"CPU load", std::to_string(this->cpu_data.cpu_load)},
        {"RAM used", std::to_string(this->memory_data.ram_ratio)},
        {"Swap used", std::to_string(this->memory_data.swap_ratio)},
        {"WireLess Protocol Name", this->net_data.name},
        {"Emitted bytes", std::to_string(this->net_data.bytes_transmit)},
        {"Emitted packets", std::to_string(this->net_data.packets_transmit)},
        {"Received bytes", std::to_string(this->net_data.bytes_receive)},
        {"Received packets", std::to_string(this->net_data.packets_receive)}
    };
}

std::string SysData::getData(void) const
{
    std::stringstream s;
    s << "Machine name: " << this->machine_name << std::endl
    << this->curr_time
    << "OS: " << this->distrib << std::endl
    << "Kernel: " <<  this->kernel_version << std::endl
    << "Nb processes: " << this->proc_data.nb_processes << std::endl
    << "CPU load: " << this->cpu_data.cpu_load << "%" << std::endl
    << "Swap used: " << this->memory_data.swap_ratio << "%" << std::endl
    << "RAM used: " << this->memory_data.ram_ratio << "%" << std::endl
    << std::endl;
    return s.str();
}