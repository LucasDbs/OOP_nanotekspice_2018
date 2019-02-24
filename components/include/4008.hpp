//
// EPITECH PROJECT, 2019
// NanoTekSPice
// File description:
// 4008 header
//

#if !defined(_4008_HPP_)
#define _4008_HPP_

#include <map>
#include <functional>
#include "IComponent.hpp"

class CMP4008: public nts::IComponent
{
        public:
                CMP4008(std::string name);
                virtual ~CMP4008();
                std::string getName() const;
                nts::Tristate compute(std::size_t pin = 1);
                void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin);

        private:
                std::string _name;
                std::map<std::size_t, std::pair<nts::IComponent *, std::size_t> > _links;
                std::map<std::size_t, std::pair<std::size_t, std::size_t> > _gates;
                std::map<std::size_t, std::function<nts::Tristate(std::size_t)> > _pin_func;

                nts::Tristate inputPin(std::size_t pin);
                nts::Tristate outputPin(std::size_t pin);
                nts::Tristate andCompute(std::size_t a, std::size_t b) const;
};

#endif
