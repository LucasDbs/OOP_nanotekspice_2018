//
// EPITECH PROJECT, 2019
// Lucas Duboisse
// File description:
// 4081.hpp
//

#include <string>
#include "../include/4081.hpp"
#include "../include/Output.hpp"

CMP4081::CMP4081(std::string name)
{
        _name = name;
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

std::string CMP4081::getName() const
{
        return _name;
}

void CMP4081::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
        if (_links.find(pin) != _links.end() && _links[pin].first == nullptr) {
                _links[pin] = std::make_pair(&other, otherPin);
                other.setLink(otherPin, *this, pin);
        }
}

nts::Tristate CMP4081::compute(std::size_t pin)
{
        if (_pin_func.find(pin) != _pin_func.end()) {
                try {
                        return _pin_func[pin](pin);
                }
                catch(const std::exception &e) {
                        std::cerr << e.what() << '\n';
                }
                
        }
        return nts::Tristate::UNDEFINED;
}

nts::Tristate CMP4081::inputPin(std::size_t pin)
{
        if (_links[pin].first) {
                if (static_cast<Output *>(_links[pin].first))
                        return nts::Tristate::UNDEFINED;
                return _links[pin].first->compute(_links[pin].second);
        }
        return nts::Tristate::UNDEFINED;        
}

nts::Tristate CMP4081::outputPin(std::size_t pin)
{
        nts::Tristate res = nts::Tristate::UNDEFINED;
        std::size_t pinA = 0;
        std::size_t pinB = 0;

        if (_gates.find(pin) == _gates.end())
                return nts::Tristate::UNDEFINED;
        pinA = _gates[pin].first;
        pinB = _gates[pin].second;
        if (_links[pinA].first && _links[pinB].first)
                res = andCompute(_links[pinA].first->compute(_links[pinA].second),
                        _links[pinB].first->compute(_links[pinB].second));
        return res;        
}

nts::Tristate CMP4081::andCompute(std::size_t a, std::size_t b) const
{
        return static_cast<nts::Tristate>(a && b);
}