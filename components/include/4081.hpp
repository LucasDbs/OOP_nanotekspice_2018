//
// EPITECH PROJECT, 2019
// Lucas Duboisse
// File description:
// 4081.hpp
//

#if !defined(_4081_HPP_)
#define _4081_HPP_

#include <map>
#include <functional>
#include "IComponent.hpp"

class CMP4081: public nts::IComponent
{
        public:
                CMP4081();
                virtual ~CMP4081();
                std::string getName() const;
                nts::Tristate compute(std::size_t pin = 1);
                void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin);
                void setState(const std::string &state);
                nts::Tristate getState() const;

        private:
                std::map<std::size_t, std::pair<nts::IComponent *, std::size_t> > _links;
                std::map<std::size_t, std::pair<std::size_t, std::size_t> > _gates;
                std::map<std::size_t, std::function<nts::Tristate(std::size_t)> > _pin_func;

                nts::Tristate inputPin(std::size_t pin);
                nts::Tristate outputPin(std::size_t pin);
                nts::Tristate andCompute(std::size_t a, std::size_t b) const;
};

#endif