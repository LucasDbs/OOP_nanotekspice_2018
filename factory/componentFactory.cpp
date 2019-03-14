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
        // m_map.insert(std::make_pair("CMP2716", [&] (const std::string value) { return new CMP2716(value); }));
        // m_map.insert(std::make_pair("CMP4001", [&] (const std::string value) { return new CMP4001(value); }));
        // m_map.insert(std::make_pair("CMP4008", [&] (const std::string value) { return new CMP4008(value); }));
        // m_map.insert(std::make_pair("CMP4011", [&] (const std::string value) { return new CMP4011(value); }));
        // // m_map.insert(std::make_pair("CMP4013", [&] (const std::string value) { return new CMP4013(value); }));
        // // m_map.insert(std::make_pair("CMP4017", [&] (const std::string value) { return new CMP4017(value); }));
        // m_map.insert(std::make_pair("CMP4030", [&] (const std::string value) { return new CMP4030(value); }));
        // // m_map.insert(std::make_pair("CMP4040", [&] (const std::string value) { return new CMP4040(value); }));
        // // m_map.insert(std::make_pair("CMP4069", [&] (const std::string value) { return new CMP4069(value); }));
        // m_map.insert(std::make_pair("CMP4071", [&] (const std::string value) { return new CMP4071(value); }));
        // m_map.insert(std::make_pair("CMP4081", [&] (const std::string value) { return new CMP4081(value); }));
        m_map["4081"] = [&] (const std::string value) { (void)value; return new CMP4081; };
        m_map["input"] = [&] (const std::string value) { return new Input(value); };
        m_map["output"] = [&] (const std::string value) { (void)value; return new Output; };
        // // m_map.insert(std::make_pair("CMP4094", [&] (const std::string value) { return new CMP4094(value); }));
        // // m_map.insert(std::make_pair("CMP4514", [&] (const std::string value) { return new CMP4514(value); }));
        // // m_map.insert(std::make_pair("CMP4801", [&] (const std::string value) { return new CMP4801(value); }));
}

nts::IComponent *componentFactory::createComponent(const std::string &type, const std::string &value)
{
        if (m_map.find(type) == m_map.end()) {
                throw ErrorManaging("There is a wrong component in your configuration file");
                return NULL;
        }
        return m_map[type](value);
}       