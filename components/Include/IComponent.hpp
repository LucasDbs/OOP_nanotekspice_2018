//
// EPITECH PROJECT, 2019
// IComponent.hpp
// File description:
// Lucas Duboisse
//
 
#if !defined(ICOMPONENTS)
#define ICOMPONENTS

#include <iostream>
#include "Gates.hpp"

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
                        virtual Pins **getPins() = 0;
                        virtual Gates **getGates() = 0;
                        virtual int countPins() = 0;
                        virtual int countGates() = 0;
                        virtual Pins *findPin(std::size_t id) = 0;
                        virtual Gates *findGate(size_t id) = 0;

                        virtual nts::Tristate compute(std::size_t  pin = 1) = 0;
                        virtual void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) = 0;
                        //     virtual void dump() const = 0;
        };
};

#endif // ICOMPONENTS
