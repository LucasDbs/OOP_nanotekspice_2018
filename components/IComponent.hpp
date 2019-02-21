        //
// EPITECH PROJECT, 2019
// IComponent.hpp
// File description:
// Sabri Ouaked ~ IComponent.hpp Include file
//
 
#if !defined(ICOMPONENTS)
#define ICOMPONENTS

#include <iostream>
#include "../Gates.hpp"

namespace nts
{
        class IComponent
        {
                public:
                        virtual ~IComponent() = default;
                        virtual Pins **getPins() = 0;
                        virtual Gates **getGates() = 0;
                        virtual int countPins() = 0;
                        virtual int countGates() = 0;
                        Pins *findPin(std::size_t id);
                        Gates *findGate(size_t id);

                        virtual nts::Tristate compute(std::size_t  pin = 1) = 0;
                        virtual void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) = 0;
                        //     virtual void dump() const = 0;
        };
};

Pins *nts::IComponent::findPin(std::size_t id)
{
        Gates **gates = getGates();
        Pins **pins = getPins();
        Pins *gates_pin;

        for (int i = 0; i < countPins(); i++) {
                if (pins[i]->getId() == id)
                        return pins[i];
        }
        for (int a = 0; a < countGates(); a++) {
                gates_pin = gates[a]->getInputs();
                for (int it = 0; it < gates[a]->countInputs(); it++) {
                        if (gates_pin[it].getId() == id)
                                return &gates_pin[it];
                }
        }
        return NULL;
}


Gates *nts::IComponent::findGate(size_t id)
{
        Gates **gates = getGates();
        for (int i = 0; i < countGates(); i++) {
                if (gates[i]->getId() == id)
                        return gates[i];
        }
        return NULL;
}


#endif // ICOMPONENTS
