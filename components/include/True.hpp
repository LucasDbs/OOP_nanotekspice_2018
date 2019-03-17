//
// EPITECH PROJECT, 2019
// Lucas Duboisse
// File description:
// True.hpp
//

#if !defined(TRUE_HPP_)
#define TRUE_HPP_

#include <map>
#include "IComponent.hpp"

class True: public nts::IComponent
{
        public:
                True();
                virtual ~True();

                nts::Tristate getState() const;
                nts::Tristate compute(std::size_t pin = 1);
                void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin);

        private:
                nts::Tristate _state;
                std::map<std::size_t, std::pair<nts::IComponent *, size_t> > _links;
};

#endif