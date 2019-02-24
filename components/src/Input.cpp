//
// EPITECH PROJECT, 2019
// Lucas Duboisse
// File description:
// Input.hpp
//

#include "../include/Input.hpp"

Input::Input(const std::string &state)
{
        _links[1] = std::make_pair(nullptr, 0);
        if (state == "0")
                _state = nts::Tristate::FALSE;
        else if (state == "1")
                _state = nts::Tristate::TRUE;
        else
                _state = nts::Tristate::UNDEFINED;
}

Input::~Input()
{
}

nts::Tristate Input::getState() const
{
        return _state;
}

void Input::setState(std::string &state)
{
        if (state == "0")
                _state = nts::Tristate::FALSE;
        else if (state == "1")
                _state = nts::Tristate::TRUE;
}

void Input::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
        if (_links.find(pin) != _links.end() && _links[pin].first == nullptr) {
                _links[pin] = std::make_pair(&other, otherPin);
                other.setLink(otherPin, *this, pin);
        }
}

nts::Tristate Input::compute(std::size_t pin)
{
        if (_links.find(pin) != _links.end())
                return _state;
        return nts::Tristate::UNDEFINED;
}