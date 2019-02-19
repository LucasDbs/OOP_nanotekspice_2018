//
// EPITECH PROJECT, 2019
// Lucas Duboisse
// File description:
// ComponentFactory.hpp
//

#if !defined(COMPONENT_FACTORY_HPP_)
#define COMPONENT_FACTORY_HPP_

#include <string>
#include <utility>
#include <iostream>
#include <map>
#include <functional>
#include "../components/IComponent.hpp"
#include "../components/2716.hpp"
#include "../components/4001.hpp"
#include "../components/4008.hpp"
#include "../components/4011.hpp"
#include "../components/4013.hpp"
#include "../components/4017.hpp"
#include "../components/4030.hpp"
#include "../components/4040.hpp"
#include "../components/4069.hpp"
#include "../components/4071.hpp"
#include "../components/4081.hpp"
#include "../components/4094.hpp"
#include "../components/4514.hpp"
#include "../components/4801.hpp"

class componentFactory
{
        public:
                componentFactory();
                ~componentFactory() {};

                nts::IComponent *createComponent(const std::string &type, const std::string &value);
        private:
                std::map<std::string, std::function<nts::IComponent *(const std::string &)>> m_map;
};

#endif // COMPONENT_FACTORY_HPP_
