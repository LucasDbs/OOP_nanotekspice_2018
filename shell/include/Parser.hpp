//
// EPITECH PROJECT, 2019
// NanoTekSpice
// File description:
// Parser Shell header
//
 
#if !defined(PARSING_HPP_)
#define PARSING_HPP_

#include <iostream>
#include <fstream>
#include <map>
#include "../../components/include/IComponent.hpp"

class Parser {
        public:
                Parser(const std::string &filename);
                ~Parser();

                // std::string removeComments(std::string &line);
                void parseChipset(char **av);
                void parseLink();
                std::map<std::string, std::string> getChipset();
                std::map<std::string, nts::IComponent *> getComponent();

        private:
                std::ifstream _file;
                std::map<std::string, std::string> _chipset;
                std::map<std::string, size_t> _inputs;
                std::map<std::string, nts::IComponent *> _components;

                void createComponents();
                void fillChipset(std::string &line);
                void verifyInput(char **av);

                void makeLinks(std::string &line);
};

#endif
