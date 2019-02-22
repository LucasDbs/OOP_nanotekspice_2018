//
// EPITECH PROJECT, 2019
// Lucas Duboisse
// File description:
// PinComponent.hpp
//

// #if !defined(PIN_COMPONENT_HPP)
// #define PIN_COMPONENT_HPP

// #include "components/IComponent.hpp"
// #include "Pins.hpp"
// #include "Gates.hpp"

// class PinComponent : public nts::IComponent
// {
//         private:
//                 int _gates_nb;
//                 int _pins_nb;
//                 std::string _name;
//                 Pins *pins_array[1];
//                 Gates *gates_array;
//         public:
//                 PinComponent(std::string name, ROLE role);
//                 Pins **getPins() { return pins_array; }
//                 Gates **getGates() { return NULL; }
//                 std::string getName() { return _name; }
//                 int countPins() { return _pins_nb; }
//                 int countGates() { return _gates_nb; };
//                 void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin);
//                 nts::Tristate compute(std::size_t  pin);               
// };

// PinComponent::PinComponent(std::string name, ROLE role)
// {
//         _name = name;
//         Pins pin(1, role);
//         _pins_nb = 1;
//         _gates_nb = 0;
//         pins_array[0] = &pin;
//         gates_array = NULL;
// }

// void PinComponent::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
// {
//         Pins *currentcmp = this->findPin(pin);
//         Pins *nextcmp = other.findPin(otherPin);
        
//         nextcmp->setReference(currentcmp);
//         // return;
// }

// nts::Tristate PinComponent::compute(std::size_t pin)
// {

// }

// #endif // PIN_COMPONENT_HPP
