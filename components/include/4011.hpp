//
// EPITECH PROJECT, 2019
// NanoTekSpice
// File description:
// 4011 header
//

#if !defined(_4011_HPP_)
#define _4011_HPP_

#include "IComponent.hpp"

class CMP4011: public nts::IComponent
{
    public:
        CMP4011(std::string name);
        std::string getName();
        Pins **getPins();
        Gates **getGates();
        int countPins();
        int countGates();
        Pins *findPin(std::size_t id);
        Gates *findGate(size_t id);
        nts::Tristate compute(std::size_t pin = 1);
        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin);

    private:
        int _gates_nb;
        int _pins_nb;
        std::string _name;
        Pins *pins_array[12];
        Gates *gates_array[4];
};

#endif