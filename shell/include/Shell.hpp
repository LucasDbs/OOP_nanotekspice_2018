//
// EPITECH PROJECT, 2019
// Lucas Duboisse
// File description:
// Shell.hpp
//

#if !defined(SIMULATOR_HPP_)
#define SIMULATOR_HPP_

#include "../../components/include/IComponent.hpp"
#include "Parser.hpp"
#include <iostream>
#include <map>

class Shell
{
        public:
                Shell(Parser &parser);
                ~Shell(){};
                int launch();
        private:
                std::string _lastCommand;
                std::map<std::string, std::function<int (Shell &)> > _command;
                std::map<std::string, std::string> _chipset;
                std::map<std::string, nts::IComponent *> _components;
                bool _exit;

                int simulate();
                int changeValue();
                int loop();
                int exec_command();
                static void exit_loop(int);
                void prompt();
                int dump();
                int exit();
                int display();
};

#endif
