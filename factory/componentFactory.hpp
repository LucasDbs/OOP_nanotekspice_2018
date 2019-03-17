//
// EPITECH PROJECT, 2019
// Lucas Duboisse
// File description:
// ComponentFactory.hpp
//

#if !defined(COMPONENT_FACTORY_HPP_)
#define COMPONENT_FACTORY_HPP_

#include <string>
#include <iostream>
#include <map>
#include <functional>
#include "../components/include/IComponent.hpp"
#include "../components/include/4081.hpp"
#include "../components/include/Input.hpp"
#include "../components/include/Output.hpp"
#include "../components/include/Clock.hpp"

class componentFactory
{
        public:
                componentFactory();
                ~componentFactory() {};

                nts::IComponent *createComponent(const std::string &type, const std::string &value);
        private:
                std::map<std::string, std::function<nts::IComponent *(const std::string &)> > m_map;
};

#endif
