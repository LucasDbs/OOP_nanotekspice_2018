//
// EPITECH PROJECT, 2019
// Lucas Duboisse
// File description:
// Clock.cpp
//

#include "../include/Clock.hpp"
#include "../../shell/include/ErrorManaging.hpp"

Clock::Clock(const std::string &name)
{
        _links[1] = std::make_pair(nullptr, 0);
        _name = name;
}

Clock::~Clock()
{
}

nts::Tristate Clock::getState() const
{
        return _state;
}

std::string Clock::getName() const
{
        return _name;
}

void Clock::setState(std::string &state)
{
        if (state == "0")
                _state = nts::Tristate::FALSE;
        else if (state == "1")
                _state = nts::Tristate::TRUE;
        else
                _state = nts::Tristate::UNDEFINED;
}

void Clock::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
        if (_links.find(pin) != _links.end()) {
                if (_links[pin].first == nullptr) {
                        _links[pin] = std::make_pair(&other, otherPin);
                        other.setLink(otherPin, *this, pin);
                }
                return ;
        }
        throw ErrorManaging("Error in Clock: Pin " + std::to_string(pin) + " doesn't exist");
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
        throw ErrorManaging("Error in Clock: Pin " + std::to_string(pin) + " doesn't exist");
        return nts::Tristate::UNDEFINED;
}