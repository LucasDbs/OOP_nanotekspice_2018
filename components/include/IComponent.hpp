//
// EPITECH PROJECT, 2019
// IComponent.hpp
// File description:
// Lucas Duboisse
//
 
#if !defined(ICOMPONENTS)
#define ICOMPONENTS

#include <iostream>

namespace nts
{
        enum Tristate {
                UNDEFINED = (-true),
                TRUE = true,
                FALSE = false
        };

        class IComponent
        {
                public:
                        virtual ~IComponent() = default;

                        virtual nts::Tristate compute(std::size_t pin = 1) = 0;
                        virtual void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) = 0;
                        virtual void setState(const std::string &state) = 0;
                        virtual nts::Tristate getState() const = 0;
        };
};

#endif
