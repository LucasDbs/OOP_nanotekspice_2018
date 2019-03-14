//
// EPITECH PROJECT, 2019
// Lucas Duboisse
// File description:
// Output.hpp
//

#include "../include/Output.hpp"
#include "../../shell/include/ErrorManaging.hpp"

Output::Output()
{
        _links[1] = std::make_pair(nullptr, 0);
        _state = nts::Tristate::UNDEFINED;
        // _name = name;
}

Output::~Output()
{
}

nts::Tristate Output::getState() const
{
        return _state;
}

// std::string Output::getName() const
// {
//         return _name;
// }

void Output::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
        if (_links.find(pin) != _links.end()) {
                if (_links[pin].first == nullptr) {
                        _links[pin] = std::make_pair(&other, otherPin);
                        other.setLink(otherPin, *this, pin);
                }
                return ;
        }
        throw ErrorManaging("Error in Output: Pin " + std::to_string(pin) + " doesn't exist");
}

nts::Tristate Output::compute(std::size_t pin)
{
        if (_links.find(pin) != _links.end()) {
                if (_links[pin].first == nullptr)
                        throw ErrorManaging("Error in Output: Pin " + std::to_string(pin) + " isn't linked to anything");
                _state = _links[pin].first->compute(_links[pin].second);
                return _state;
        }
        throw ErrorManaging("Error in Output: Pin " + std::to_string(pin) + " doesn't exist");
        return _state;
}