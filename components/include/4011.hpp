//
// EPITECH PROJECT, 2019
// NanoTekSpice
// File description:
// 4011 header
//

#if !defined(_4011_HPP_)
#define _4011_HPP_

#include <map>
#include <functional>
#include "IComponent.hpp"

class CMP4011: public nts::IComponent
{
        public:
                CMP4011(std::string name);
                virtual ~CMP4011();
                std::string getName() const;
                nts::Tristate compute(std::size_t pin = 1);
                void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin);

        private:
                std::map<std::size_t, std::pair<nts::IComponent *, std::size_t> > _links;
                std::map<std::size_t, std::pair<std::size_t, std::size_t> > _gates;
                std::map<std::size_t, std::function<nts::Tristate(std::size_t)> > _pin_func;

                nts::Tristate inputPin(std::size_t pin);
                nts::Tristate outputPin(std::size_t pin);
                nts::Tristate andCompute(std::size_t a, std::size_t b) const;
};

#endif