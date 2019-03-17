//
// EPITECH PROJECT, 2019
// NanoTekSpice
// File description:
// Parser Shell
//

#include <algorithm>
#include <regex>
#include "../include/Parser.hpp"
#include "../include/ErrorManaging.hpp"
#include "../../factory/componentFactory.hpp"

Parser::Parser(const std::string &filename)
{
        _file.open(filename.data());

        if (!_file.is_open())
                throw ErrorManaging("The file cannot be open : check if file exist or if you have the rights");
}

Parser::~Parser()
{
        _file.close();
}

std::map<std::string, std::string> Parser::getChipset()
{
        return _chipset;
}

std::map<std::string, nts::IComponent *> Parser::getComponent()
{
        return _components;
}

void Parser::createComponents()
{
        componentFactory fact;
        std::map<std::string, std::string>::iterator it;

        for (it = _chipset.begin(); it != _chipset.end(); it++) {
                if (it->second == "input")
                        throw ErrorManaging("Error: input " + it->first + " is unspecified.");
                _components[it->first] = fact.createComponent(it->second, it->first);
        }
}

void Parser::verifyInput(char **av)
{
        int i = 2;
        std::string str;
        std::string name;
        std::string value;
        std::regex pattern { "[A-Za-z0-9]+=[0|1]" };
        componentFactory fact;

        while (av[i]) {
                str = av[i];
                if (std::regex_match(str, pattern)) {
                        name = str.substr(0, str.find("="));
                        value = str.substr(str.find("=") + 1, std::string::npos);
                        if (_chipset[name].empty())
                                throw ErrorManaging("Error: " + name + " don't exist in file");
                        else if (_chipset[name] != "input" && _chipset[name] != "clock")
                                throw ErrorManaging("Error: " + name + " isn't a input");
                        else {
                                _components[name] = fact.createComponent(_chipset[name], value);
                                _chipset.erase(name);
                        }
                } else
                        throw ErrorManaging("Error: input " + str + " don't respect the format.");
                i++;
        }
}

void Parser::fillChipset(std::string &line)
{
        std::string first;
        std::string second;
        std::regex pattern { "[A-Za-z0-9]+ +[A-Za-z0-9]+" };

        while (std::getline(_file, line)) {
                if (line.find(".links") != std::string::npos)
                        return ;
                if (std::regex_match(line, pattern)) {
                        first = line.substr(0, line.find(" "));
                        second = line.substr(line.find(" "), std::string::npos);
                        second.erase(std::remove(second.begin(), second.end(), ' '), second.end());
                        if (_chipset[second].empty())
                                _chipset[second] = first;
                        else
                                throw ErrorManaging("Error in configuration file: " + second + " already exist");
                } else if (!line.empty())
                        if (line.at(0) != '#')
                                throw ErrorManaging("Error parsing: syntaxe error in \".chipset\" section");
        }
}

void Parser::parseChipset(char **av)
{
        std::string line;
        _file.clear();
        _file.seekg(0);

        while (std::getline(_file, line)) {
                if (line.find(".chipsets") != std::string::npos) {
                        fillChipset(line);
                        verifyInput(av);
                        createComponents();
                        return ;
                }
        }
        throw ErrorManaging("No \".chipset\" section found in file.");
}

void Parser::makeLinks(std::string &line)
{
        std::regex pattern { "[A-Za-z0-9]+:[0-9]+ +[A-Za-z0-9]+:[0-9]+" };
        std::string cmp1;
        std::string cmp2;
        std::string name1;
        std::string value1;
        std::string name2;
        std::string value2;

        while (std::getline(_file, line)) {
                if (line.find(".chipsets") != std::string::npos)
                        return ;
                if (std::regex_match(line, pattern)) {
                        cmp1 = line.substr(0, line.find(" "));
                        cmp2 = line.substr(line.find(" ") + 1, std::string::npos);
                        cmp2.erase(std::remove(cmp2.begin(), cmp2.end(), ' '), cmp2.end());
                        name1 = cmp1.substr(0, cmp1.find(':'));
                        value1 = cmp1.substr(cmp1.find(':') + 1, std::string::npos);
                        name2 = cmp2.substr(0, cmp2.find(':'));
                        value2 = cmp2.substr(cmp2.find(':') + 1, std::string::npos);
                        if (!_components[name1])
                                throw ErrorManaging("Error link: " + name1 + " not found");
                        else if (!_components[name2])
                                throw ErrorManaging("Error link: " + name2 + " not found");
                        else
                                _components[name1]->setLink(std::stoi(value1), *_components[name2], std::stoi(value2));
                } else if (!line.empty()) {
                        if (line.at(0) != '#')
                                throw ErrorManaging("Error parsing: syntaxe error in \".links\" section");
                }
        }
}

void Parser::parseLink()
{
        std::string line;
        _file.clear();
        _file.seekg(0);

        while (std::getline(_file, line)) {
                if (line.find(".links") != std::string::npos) {
                        makeLinks(line);
                        return ;
                }
        }
        throw ErrorManaging("No \".links\" section found in file.");
}