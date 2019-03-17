//
// EPITECH PROJECT, 2019
// Lucas Duboisse
// File description:
// True.cpp
//

#include "../include/True.hpp"
#include "../../shell/include/ErrorManaging.hpp"

True::True()
{
        _links[1] = std::make_pair(nullptr, 0);
        _state = nts::Tristate::TRUE;
}

True::~True()
{
}

nts::Tristate True::getState() const
{
        return _state;
}

void True::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
        if (_links.find(pin) != _links.end()) {
                if (_links[pin].first == nullptr) {
                        _links[pin] = std::make_pair(&other, otherPin);
                        other.setLink(otherPin, *this, pin);
                }
                return ;
        }
        throw ErrorManaging("Error in True: Pin " + std::to_string(pin) + " doesn't exist");
}

nts::Tristate True::compute(std::size_t pin)
{
        if (_links.find(pin) != _links.end())
                return _state;
        throw ErrorManaging("Error in True: Pin " + std::to_string(pin) + " doesn't exist");        
}