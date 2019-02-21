//
// EPITECH PROJECT, 2019
// simulator.cpp
// File description:
// Gautier PLANCQ ~ simulator.cpp Source file
//
 
#include <iostream>
#include <csignal>
#include <map>
#include "Simulator.hpp"

bool LOOP = false;

Simulator::Simulator(const std::string &filename) : _exit(false)
{
        Parsing parsed(filename);

        parsed.parseFile();
        this->_inputs = parsed.getInputs();
        this->_outputs = parsed.getOutputs();
        this->_components = parsed.getComponents();
        this->_command["simulate"] = &Simulator::simulate;
        this->_command["loop"] = &Simulator::loop;
        this->_command["dump"] = &Simulator::dump;
        this->_command["display"] = &Simulator::display;
        this->_command["exit"] = &Simulator::exit;
        this->_command["changeValue"] = &Simulator::changeValue;
}

int Simulator::launch()
{
        while (this->_exit == false) {
                this->prompt();
                if (this->exec_command() == 84)
                        return (84); 
        }
        return 0;
}

int Simulator::simulate()
{
        std::cout << "simulate" << std::endl;
        return 0;
}

int Simulator::changeValue()
{
        std::string input;
        std::string value;

        if (_lastCommand.find_first_of("=") == _lastCommand.npos)
                throw ErrorManaging("The command entered is unknown");
        input = _lastCommand.substr(0, _lastCommand.find_first_of("="));
        value = _lastCommand.substr(_lastCommand.find_first_of("=") + 1, _lastCommand.size());
        if (input.empty())
                throw ErrorManaging("The input name is not entered");
        else if (value.empty())
                throw ErrorManaging("The value's input is not entered");
        return 0;
}

void Simulator::exit_loop(int signal)
{
        std::signal(SIGINT, SIG_DFL);
        LOOP = false;
}

int Simulator::loop()
{
        std::signal(SIGINT, &Simulator::exit_loop);
        LOOP = true;
        while (LOOP)
                std::cout << "loop" << std::endl;
        return 0;
}

int Simulator::exec_command()
{
        auto command_fct = _command.find(_lastCommand);

        if (command_fct != _command.end())
                return (this->*(command_fct->second))();
        try {
                return changeValue();
        } catch (ErrorManaging &e) {
                std::cerr << e.what() << std::endl;
                std::exit(84);
        }
        return (0);
}

void Simulator::prompt()
{
        std::string result;

        std::cout << "> ";
        std::cin >> _lastCommand;
        if (std::cin.eof())
              _lastCommand = "exit";
}

int Simulator::dump()
{
        std::cout << "dump" << std::endl;
}

int Simulator::display()
{
        std::cout << "display" << std::endl;
}

int Simulator::exit()
{
        this->_exit = true;
        return (0);
}