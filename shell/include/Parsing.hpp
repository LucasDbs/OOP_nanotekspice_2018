//
// EPITECH PROJECT, 2019
// NanoTekSpice
// File description:
// Parsing Shell header
//
 
#if !defined(PARSING_HPP_)
#define PARSING_HPP_

#include <iostream>
#include <fstream>
#include "../../components/include/IComponent.hpp"

class Parsing {
        public:
                Parsing(const std::string &filename);
                ~Parsing() {};
                nts::IComponent *getInputs();
                nts::IComponent *getOutputs();
                nts::IComponent *getComponents();
                std::string removeComments(std::string &line);
                bool parseFile();
        private:
                std::ifstream _file;
                nts::IComponent *_inputs;
                nts::IComponent *_outputs;
                nts::IComponent *_components;
};

#endif // PARSING_HPP_
