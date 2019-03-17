//
// EPITECH PROJECT, 2019
// NanoTekSpice
// File description:
// 4011 header
//

#include <string>
#include "../include/4011.hpp"
#include "../include/Output.hpp"
#include "../../shell/include/ErrorManaging.hpp"

CMP4011::CMP4011(std::string name)
{
        for(std::size_t i = 1; i <= 14; i++)
                _links[i] = std::make_pair(nullptr, 0);

        _pin_func[1] = std::bind(&CMP4011::inputPin, this, std::placeholders::_1);
        _pin_func[2] = std::bind(&CMP4011::inputPin, this, std::placeholders::_1);
        _pin_func[5] = std::bind(&CMP4011::inputPin, this, std::placeholders::_1);
        _pin_func[6] = std::bind(&CMP4011::inputPin, this, std::placeholders::_1);
        _pin_func[8] = std::bind(&CMP4011::inputPin, this, std::placeholders::_1);
        _pin_func[9] = std::bind(&CMP4011::inputPin, this, std::placeholders::_1);
        _pin_func[12] = std::bind(&CMP4011::inputPin, this, std::placeholders::_1);
        _pin_func[13] = std::bind(&CMP4011::inputPin, this, std::placeholders::_1);

        _pin_func[3] = std::bind(&CMP4011::outputPin, this, std::placeholders::_1);
        _pin_func[4] = std::bind(&CMP4011::outputPin, this, std::placeholders::_1);
        _pin_func[10] = std::bind(&CMP4011::outputPin, this, std::placeholders::_1);
        _pin_func[11] = std::bind(&CMP4011::outputPin, this, std::placeholders::_1);


        _gates[3] = std::make_pair(1, 2);
        _gates[4] = std::make_pair(5, 6);
        _gates[10] = std::make_pair(8, 9);
        _gates[11] = std::make_pair(12, 13);
}

CMP4011::~CMP4011()
{
}

std::string CMP4011::getName() const
{
        return _name;
}

void CMP4011::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
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

nts::Tristate CMP4011::compute(std::size_t pin)
{
        if (_pin_func.find(pin) != _pin_func.end()) {
                try {
                        return _pin_func[pin](pin);
                }
                catch(const std::exception &e) {
                        std::cerr << e.what() << '\n';
                        return nts::Tristate::UNDEFINED;
                }
                
        }
        throw ErrorManaging("Error in CMP4081: Pin " + std::to_string(pin) + " doesn't exist");
        return nts::Tristate::UNDEFINED;
}

nts::Tristate CMP4011::inputPin(std::size_t pin)
{
        if (_links[pin].first) {
                if (static_cast<Output *>(_links[pin].first)) {
                        throw ErrorManaging("Error in CMP4081: Input pin " + std::to_string(pin) + " linked to Output");
                        return nts::Tristate::UNDEFINED;
                }
                return _links[pin].first->compute(_links[pin].second);
        }
        throw ErrorManaging("Error in CMP4081: Pin " + std::to_string(pin) + " isn't linked to anything");
        return nts::Tristate::UNDEFINED;        
}

nts::Tristate CMP4011::outputPin(std::size_t pin)
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

nts::Tristate CMP4011::andCompute(std::size_t a, std::size_t b) const
{
        return static_cast<nts::Tristate>(a && b);
}