//
// EPITECH PROJECT, 2019
// Lucas Duboisse
// File description:
// Clock.cpp
//

#include "../include/Clock.hpp"

Clock::Clock(const std::string &state)
{
        _links[1] = std::make_pair(nullptr, 0);
        if (state == "0")
                _state = nts::Tristate::FALSE;
        else if (state == "1")
                _state = nts::Tristate::TRUE;
        else
                _state = nts::Tristate::UNDEFINED;
}

Clock::~Clock()
{
}

nts::Tristate Clock::getState() const
{
        return _state;
}

void Clock::setState(std::string &state)
{
        if (state == "0")
                _state = nts::Tristate::FALSE;
        else if (state == "1")
                _state = nts::Tristate::TRUE;
}

void Clock::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
        if (_links.find(pin) != _links.end() && _links[pin].first == nullptr) {
                _links[pin] = std::make_pair(&other, otherPin);
                other.setLink(otherPin, *this, pin);
        }
}

void Clock::changeState()
{
        if (_state == nts::Tristate::FALSE)
                _state = nts::Tristate::TRUE;
        else if (_state == nts::Tristate::TRUE)
                _state = nts::Tristate::FALSE;
}

nts::Tristate Clock::compute(std::size_t pin)
{
        nts::Tristate to_return = _state;

        if (_links.find(pin) != _links.end()) {
                changeState();
                return to_return;
        }
        return nts::Tristate::UNDEFINED;
}