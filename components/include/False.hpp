//
// EPITECH PROJECT, 2019
// Lucas Duboisse
// File description:
// False.hpp
//

#if !defined(FALSE_HPP)
#define FALSE_HPP

#include <map>
#include "IComponent.hpp"

class False: public nts::IComponent
{
        public:
                False();
                virtual ~False();

                nts::Tristate getState() const;
                nts::Tristate compute(std::size_t pin = 1);
                void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin);

        private:
                nts::Tristate _state;
                std::map<std::size_t, std::pair<nts::IComponent *, size_t> > _links;
};

#endif // FALSE_HPP
