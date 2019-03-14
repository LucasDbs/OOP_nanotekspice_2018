//
// EPITECH PROJECT, 2019
// Lucas Duboisse
// File description:
// Clock.hpp
//

#if !defined(CLOCK_HPP_)
#define CLOCK_HPP_

#include <map>
#include "IComponent.hpp"

class Clock: public nts::IComponent
{
        public:
                Clock();
                virtual ~Clock();

                nts::Tristate getState() const;
                void setState(std::string &state);
                // std::string getName() const;

                nts::Tristate compute(std::size_t pin = 1);
                void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin);

        private:
                // std::string _name;
                void changeState();
                nts::Tristate _state;
                std::map<std::size_t, std::pair<nts::IComponent *, size_t> > _links;
};

#endif // CLOCK_HPP_
