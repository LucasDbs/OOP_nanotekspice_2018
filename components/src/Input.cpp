//
// EPITECH PROJECT, 2019
// Lucas Duboisse
// File description:
// Input.hpp
//

#include "../include/Input.hpp"
#include "../../shell/include/ErrorManaging.hpp"

Input::Input(const std::string &name)
{
        _links[1] = std::make_pair(nullptr, 0);
        _name = name;
}

Input::~Input()
{
}

nts::Tristate Input::getState() const
{
        return _state;
}

std::string Input::getName() const
{
        return _name;
}

void Input::setState(std::string &state)
{
        if (state == "0")
                _state = nts::Tristate::FALSE;
        else if (state == "1")
                _state = nts::Tristate::TRUE;
        else
                _state = nts::Tristate::UNDEFINED;
}

void Input::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
        if (_links.find(pin) != _links.end()) {
                if (_links[pin].first == nullptr) {
                        _links[pin] = std::make_pair(&other, otherPin);
                        other.setLink(otherPin, *this, pin);
                }
                return ;
        }
        throw ErrorManaging("Error in Input: Pin " + std::to_string(pin) + " doesn't exist");
}

nts::Tristate Input::compute(std::size_t pin)
{
        if (_links.find(pin) != _links.end())
                return _state;
        throw ErrorManaging("Error in Input: Pin " + std::to_string(pin) + " doesn't exist");        
        return nts::Tristate::UNDEFINED;
}