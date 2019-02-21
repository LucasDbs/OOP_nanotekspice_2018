//
// EPITECH PROJECT, 2019
// NanoTekSpice
// File description:
// 4081 header
//

#if !defined(_4081_HPP_)
#define _4081_HPP_

#include "IComponent.hpp"
#include "Gates.hpp"
#include "Pins.hpp"

class CMP4081: public nts::IComponent
{
    public:
        CMP4081(std::string name);
        std::string getName();
        Pins **getPins();
        Gates **getGates();
        int countPins();
        int countGates();
        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin);

    private:
        int _gates_nb;
        int _pins_nb;
        std::string _name;
        Pins *pins_array[12];
        Gates *gates_array[4];
};

#endif