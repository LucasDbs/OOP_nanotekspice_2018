//
// EPITECH PROJECT, 2019
// Lucas Duboisse
// File description:
// False.cpp
//

#include "../include/False.hpp"

False::False()
{
        _links[1] = std::make_pair(nullptr, 0);
        _state = nts::Tristate::FALSE;
}

False::~False()
{
}

nts::Tristate False::getState() const
{
        return _state;
}

void False::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
        if (_links.find(pin) != _links.end() && _links[pin].first == nullptr) {
                _links[pin] = std::make_pair(&other, otherPin);
                other.setLink(otherPin, *this, pin);
        }
}

nts::Tristate False::compute(std::size_t pin)
{
        if (_links.find(pin) != _links.end())
                return _state;
        return nts::Tristate::UNDEFINED;
}