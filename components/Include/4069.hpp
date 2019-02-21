//
// EPITECH PROJECT, 2019
// NanoTekSpice
// File description:
// 4069 header
//

#if !defined(_4069_HPP_)
#define _4069_HPP_

#include "IComponent.hpp"

#include "IComponent.hpp"
#include "Gates.hpp"
#include "Pins.hpp"

class CMP4069: public nts::IComponent
{
    public:
        CMP4069(std::string name);
        std::string getName() { return _name; };
        Pins **getPins() { return pins_array; }
        Gates **getGates() { return gates_array; }
        int countPins() { return _pins_nb; }
        int countGates() { return _gates_nb; }

    private:
        int _gates_nb;
        int _pins_nb;
        std::string _name;
        Pins *pins_array[12];
        Gates *gates_array[6];
};

#endif
