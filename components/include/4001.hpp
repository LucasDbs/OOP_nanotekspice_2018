//
// EPITECH PROJECT, 2019
// NanotekSpice
// File description:
// 4001 header
//

#if !defined(_4001_HPP_)
#define _4001_HPP_

#include "IComponent.hpp"
#include "Gates.hpp"
#include "Pins.hpp"

class CMP4001: public nts::IComponent
{
    public:
        CMP4001(std::string name);
        std::string getName();
        Pins **getPins();
        Gates **getGates();
        int countPins();
        int countGates();
        Pins *findPin(std::size_t id);
        Gates *findGate(size_t id);
        nts::Tristate compute(std::size_t pin = 1) { return nts::Tristate::TRUE; };
        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) {};

    private:
        int _gates_nb;
        int _pins_nb;
        std::string _name;
        Pins *pins_array[12];
        Gates *gates_array[4];
};

#endif
