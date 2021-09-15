/*
** EPITECH PROJECT, 2021
** B-CCP-400
** File description:
** Log
*/

#include "../inc/Logfile.hpp"


Logfile::Logfile()
{
    this->_stream = std::ofstream("log");
    if (!this->_stream)
        throw Exception("couldn't create log file");
    this->_stream << "------------------------------\n\n\
         Tchoupy-zza\n\
        -------------\n\n\
123 des rue du rue\n12345 Rue-ville\n\n" << currentDateTime() << "\n\n" << 
"------------------------------\n" << std::endl; 
}

Logfile::~Logfile()
{
    this->_stream << "\n------------------------------\n\n     Merci de votre visite\n\
\tAu revoir\n\n------------------------------" << std::endl;
    this->_stream.close();
}

void Logfile::LMessage(std::string message)
{
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "(%X)", &tstruct);
    this->_stream << message << " " << buf << std::endl;
}

void Logfile::CommandMessage()
{
    this->_stream << "-----------------------------" << std::endl;
    this->_stream << "           TICKETS           " << std::endl;
    this->_stream << "-----------------------------" << std::endl;
}

void Logfile::EndCommandMessage()
{
    this->_stream << "-----------------------------" << std::endl;
}

std::string Logfile::currentDateTime()
{
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "Date du ticket :\nLe %d %m %Y à %X", &tstruct);

    return buf;
}