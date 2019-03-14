//
// EPITECH PROJECT, 2019
// Lucas Duboisse
// File description:
// False.cpp
//

#include "../include/False.hpp"
#include "../../shell/include/ErrorManaging.hpp"

False::False()
{
        _links[1] = std::make_pair(nullptr, 0);
        _state = nts::Tristate::FALSE;
        // _name = name;
}

False::~False()
{
}

nts::Tristate False::getState() const
{
        return _state;
}

// std::string False::getName() const
// {
//         return _name;
// }

void False::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
        if (_links.find(pin) != _links.end()) {
                if (_links[pin].first == nullptr) {
                        _links[pin] = std::make_pair(&other, otherPin);
                        other.setLink(otherPin, *this, pin);
                }
                return ;
        }
        throw ErrorManaging("Error in False: Pin " + std::to_string(pin) + " doesn't exist");
}

nts::Tristate False::compute(std::size_t pin)
{
        if (_links.find(pin) != _links.end())
                return _state;
        throw ErrorManaging("Error in False: Pin " + std::to_string(pin) + " doesn't exist");
        return nts::Tristate::UNDEFINED;
}