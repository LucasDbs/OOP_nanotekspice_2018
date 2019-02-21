//
// EPITECH PROJECT, 2019
// NanoTekSpice
// File description:
// Shell Header
//


#if !defined(SIMULATOR_HPP_)
#define SIMULATOR_HPP_

#include <map>
#include "Parsing.hpp"
#include "ErrorManaging.hpp"

class Shell
{
        public:
                Shell(const std::string &filename);
                ~Shell(){};
                int launch();
        private:
                std::string _lastCommand;
                std::map<std::string, int(Shell::*)(void)> _command;
                nts::IComponent *_inputs;
                nts::IComponent *_outputs;
                nts::IComponent *_components;
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
