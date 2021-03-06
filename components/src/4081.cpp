//
// EPITECH PROJECT, 2019
// Lucas Duboisse
// File description:
// 4081.hpp
//

#include <string>
#include "../include/4081.hpp"
#include "../include/Output.hpp"
#include "../../shell/include/ErrorManaging.hpp"

CMP4081::CMP4081()
{
        for(std::size_t i = 1; i <= 14; i++)
                _links[i] = std::make_pair(nullptr, 0);

        _pin_func[1] = std::bind(&CMP4081::inputPin, this, std::placeholders::_1);
        _pin_func[2] = std::bind(&CMP4081::inputPin, this, std::placeholders::_1);
        _pin_func[5] = std::bind(&CMP4081::inputPin, this, std::placeholders::_1);
        _pin_func[6] = std::bind(&CMP4081::inputPin, this, std::placeholders::_1);
        _pin_func[8] = std::bind(&CMP4081::inputPin, this, std::placeholders::_1);
        _pin_func[9] = std::bind(&CMP4081::inputPin, this, std::placeholders::_1);
        _pin_func[12] = std::bind(&CMP4081::inputPin, this, std::placeholders::_1);
        _pin_func[13] = std::bind(&CMP4081::inputPin, this, std::placeholders::_1);

        _pin_func[3] = std::bind(&CMP4081::outputPin, this, std::placeholders::_1);
        _pin_func[4] = std::bind(&CMP4081::outputPin, this, std::placeholders::_1);
        _pin_func[10] = std::bind(&CMP4081::outputPin, this, std::placeholders::_1);
        _pin_func[11] = std::bind(&CMP4081::outputPin, this, std::placeholders::_1);


        _gates[3] = std::make_pair(1, 2);
        _gates[4] = std::make_pair(5, 6);
        _gates[10] = std::make_pair(8, 9);
        _gates[11] = std::make_pair(12, 13);
}

CMP4081::~CMP4081()
{
}

nts::Tristate CMP4081::getState() const
{
        return nts::Tristate::UNDEFINED;
}

void CMP4081::setState(const std::string &state)
{
        (void)state;
        return ;
}

void CMP4081::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
        if (_links.find(pin) != _links.end()) {
                if (_links[pin].first == nullptr) {
                        _links[pin] = std::make_pair(&other, otherPin);
                        other.setLink(otherPin, *this, pin);
                }
                return ;
        }
        throw ErrorManaging("Error in CMP4081: Pin " + std::to_string(pin) + " doesn't exist");
}

nts::Tristate CMP4081::compute(std::size_t pin)
{
        if (_pin_func.find(pin) != _pin_func.end())
                return _pin_func[pin](pin);
        throw ErrorManaging("Error in CMP4081: Pin " + std::to_string(pin) + " doesn't exist");
}

nts::Tristate CMP4081::inputPin(std::size_t pin)
{
        if (_links[pin].first) {
                if (static_cast<Output *>(_links[pin].first)) {
                        throw ErrorManaging("Error in CMP4081: Input pin " + std::to_string(pin) + " linked to Output");
                        return nts::Tristate::UNDEFINED;
                }
                return _links[pin].first->compute(_links[pin].second);
        }
        throw ErrorManaging("Error in CMP4081: Pin " + std::to_string(pin) + " isn't linked to anything");
}

nts::Tristate CMP4081::outputPin(std::size_t pin)
{
        nts::Tristate res = nts::Tristate::UNDEFINED;
        std::size_t pinA = 0;
        std::size_t pinB = 0;

        if (_gates.find(pin) != _gates.end()) {
                pinA = _gates[pin].first;
                pinB = _gates[pin].second;
                if (_links[pinA].first && _links[pinB].first)
                        res = andCompute(_links[pinA].first->compute(_links[pinA].second),
                                _links[pinB].first->compute(_links[pinB].second));
                return res;
        }
        throw ErrorManaging("Error in CMP4081: Pin " + std::to_string(pin) + " has no gates");      
}

nts::Tristate CMP4081::andCompute(std::size_t a, std::size_t b) const
{
        return static_cast<nts::Tristate>(a && b);
}