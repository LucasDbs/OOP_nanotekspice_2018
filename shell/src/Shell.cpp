//
// EPITECH PROJECT, 2019
// Lucas Duboisse
// File description:
// Shell.cpp
//

#include <iostream>
#include <csignal>
#include <map>
#include <functional>
#include "../include/ErrorManaging.hpp"
#include "../include/Shell.hpp"

bool LOOP = false;

Shell::Shell(Parser &parser) : _exit(false)
{
        _chipset = parser.getChipset();
        _components = parser.getComponent();
        _command["simulate"] = &Shell::simulate;
        _command["loop"] = &Shell::loop;
        _command["dump"] = &Shell::dump;
        _command["display"] = &Shell::display;
        _command["exit"] = &Shell::exit;
        simulate();
        display();
}

int Shell::launch()
{
        while (_exit == false) {
                prompt();
                exec_command();
        }
        return 0;
}

int Shell::simulate()
{
        std::map<std::string, std::string>::iterator it;

        for (it = _chipset.begin(); it != _chipset.end(); it++) {
                if (it->second == "output")
                        _components[it->first]->compute();
        }
        return 0;
}

int Shell::changeValue()
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
        else if (!_components[input])
                throw ErrorManaging("Input doesn't exist");
        _components[input]->setState(value);
        return 0;
}

void Shell::exit_loop(int signal)
{
        (void)signal;

        std::signal(SIGINT, SIG_DFL);
        LOOP = false;
}

int Shell::loop()
{
        std::signal(SIGINT, &Shell::exit_loop);
        LOOP = true;
        while (LOOP)
                simulate();
        return 0;
}

int Shell::exec_command()
{
        auto command_fct = _command.find(_lastCommand);

        if (command_fct != _command.end())
                return _command[_lastCommand](*this);
        try {
                return changeValue();
        } catch (ErrorManaging &e) {
                std::cerr << e.what() << std::endl;
        }
        return 0;
}

void Shell::prompt()
{
        std::cout << "> ";
        std::cin >> _lastCommand;
        if (std::cin.eof())
              _lastCommand = "exit";
}

int Shell::dump()
{
        std::cout << "dump" << std::endl;
        return 0;
}

int Shell::display()
{
        std::map<std::string, std::string>::iterator it;

        for (it = _chipset.begin(); it != _chipset.end(); it++) {
                if (it->second == "output")
                        std::cout << it->first << "="
                        <<_components[it->first]->getState() << std::endl;
        }
        return 0;
}

int Shell::exit()
{
        _exit = true;
        return 0;
}
