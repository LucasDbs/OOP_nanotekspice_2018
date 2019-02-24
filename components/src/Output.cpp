//
// EPITECH PROJECT, 2019
// Lucas Duboisse
// File description:
// Output.hpp
//

#include "../include/Output.hpp"

Output::Output()
{
        _links[1] = std::make_pair(nullptr, 0);
        _state = nts::Tristate::UNDEFINED;
}

Output::~Output()
{
}

nts::Tristate Output::getState() const
{
        return _state;
}

void Output::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
        if (_links.find(pin) != _links.end() && _links[pin].first == nullptr) {
                _links[pin] = std::make_pair(&other, otherPin);
                other.setLink(otherPin, *this, pin);
        }
}

nts::Tristate Output::compute(std::size_t pin)
{
        if (_links.find(pin) != _links.end() && _links[pin].first != nullptr)
                _state = _links[pin].first->compute(_links[pin].second);
        return _state;
}