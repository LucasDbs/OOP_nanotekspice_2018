//
// EPITECH PROJECT, 2019
// Lucas Duboisse
// File description:
// Input.hpp
//

#if !defined(INPUT_HPP_)
#define INPUT_HPP_

#include <map>
#include "IComponent.hpp"

class Input: public nts::IComponent
{
        public:
                Input(const std::string &state);
                virtual ~Input();

                nts::Tristate getState() const;
                void setState(const std::string &state);
                nts::Tristate compute(std::size_t pin = 1);
                void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin);
        private:
                nts::Tristate _state;
                std::map<std::size_t, std::pair<nts::IComponent *, size_t> > _links;
};

#endif
