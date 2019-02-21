//
// EPITECH PROJECT, 2019
// simulator.hpp
// File description:
// Gautier PLANCQ ~ simulator.hpp Include file
//

#if !defined(SIMULATOR_HPP_)
#define SIMULATOR_HPP_

#include <map>
#include "Parsing.hpp"
#include "ErrorManaging.hpp"

class Simulator
{
        public:
                Simulator(const std::string &filename);
                ~Simulator(){};
                int launch();
        private:
                std::string _lastCommand;
                std::map<std::string, int(Simulator::*)(void)> _command;
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

#endif // SIMULATOR_HPP_