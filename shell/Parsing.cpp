//
// EPITECH PROJECT, 2019
// NanoTekSpice
// File description:
// Parsing Shell
//

 
#include "Parsing.hpp"

Parsing::Parsing(const std::string &filename)
{
        _file.open(filename);

        if (!_file.is_open()) {
                std::cerr << "The file cannot be open : check if file exist or if you have the rights" << std::endl;
                std::exit(84);
        }
}

std::string Parsing::removeComments(std::string &line)
{
        if (line.find('#') == line.npos)
                return line;
        return line.substr(0, line.find('#'));
}

nts::IComponent *Parsing::getInputs()
{
        return this->_inputs;
}

nts::IComponent *Parsing::getOutputs()
{
        return this->_outputs;
}

nts::IComponent *Parsing::getComponents()
{
        return this->_components;
}

bool Parsing::parseFile()
{
        std::string line;

        while (std::getline(_file, line)) {
                if (line.find(".chipsets:") != line.npos)
                        std::cout << "call chipset" << std::endl;
        }
}
