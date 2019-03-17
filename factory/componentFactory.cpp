//
// EPITECH PROJECT, 2019
// Lucas Duboisse
// File description:
// ComponentFactory.cpp
//

#include "componentFactory.hpp"
#include "../shell/include/ErrorManaging.hpp"

componentFactory::componentFactory()
{
        m_map["4081"] = [&] (const std::string value) { (void)value; return new CMP4081; };
        m_map["input"] = [&] (const std::string value) { return new Input(value); };
        m_map["output"] = [&] (const std::string value) { (void)value; return new Output; };
        m_map["clock"] = [&] (const std::string value) { return new Clock(value); };
}

nts::IComponent *componentFactory::createComponent(const std::string &type, const std::string &value)
{
        if (m_map.find(type) == m_map.end()) {
                throw ErrorManaging("There is a wrong component in your configuration file");
                return NULL;
        }
        return m_map[type](value);
}       