//
// EPITECH PROJECT, 2019
// NanoTekSpcie
// File description:
// Shell Shell
//

#include <iostream>
#include <csignal>
#include <map>
#include "Shell.hpp"

bool LOOP = false;

Shell::Shell(const std::string &filename) : _exit(false)
{
        Parsing parsed(filename);

        parsed.parseFile();
        _inputs = parsed.getInputs();
        _outputs = parsed.getOutputs();
        _components = parsed.getComponents();
        _command["simulate"] = &Shell::simulate;
        _command["loop"] = &Shell::loop;
        _command["dump"] = &Shell::dump;
        _command["display"] = &Shell::display;
        _command["exit"] = &Shell::exit;
        _command["changeValue"] = &Shell::changeValue;
}

int Shell::launch()
{
        while (_exit == false) {
                prompt();
                if (exec_command() == 84)
                        return (84); 
        }
        return 0;
}

int Shell::simulate()
{
        std::cout << "simulate" << std::endl;
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
        return 0;
}

void Shell::exit_loop(int signal)
{
        std::signal(SIGINT, SIG_DFL);
        LOOP = false;
}

int Shell::loop()
{
        std::signal(SIGINT, &Shell::exit_loop);
        LOOP = true;
        while (LOOP)
                std::cout << "loop" << std::endl;
        return 0;
}

int Shell::exec_command()
{
        auto command_fct = _command.find(_lastCommand);

        if (command_fct != _command.end())
                return (*(command_fct->second))();
        try {
                return changeValue();
        } catch (ErrorManaging &e) {
                std::cerr << e.what() << std::endl;
                std::exit(84);
        }
        return (0);
}

void Shell::prompt()
{
        std::string result;

        std::cout << "> ";
        std::cin >> _lastCommand;
        if (std::cin.eof())
              _lastCommand = "exit";
}

int Shell::dump()
{
        std::cout << "dump" << std::endl;
}

int Shell::display()
{
        std::cout << "display" << std::endl;
}

int Shell::exit()
{
        _exit = true;
        return (0);
}
