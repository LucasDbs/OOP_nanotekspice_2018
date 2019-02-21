//
// EPITECH PROJECT, 2019
// NanoTekSpice
// File description:
// 4069 header
//

#ifndef	_4069_HPP_
# define _4069_HPP_

#include "IComponent.hpp"

#include "IComponent.hpp"
#include "Gates.hpp"
#include "Pins.hpp"

class CMP4069: public nts::IComponent
{
    public:
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
    
    public:
        CMP4069(std::string name);
        std::string getName() { return _name; };
};


nts::Tristate always_true(nts::Tristate *array)
{
    return nts::Tristate::TRUE;
}


CMP4069::CMP4069(std::string name)
{
    int id = 1;
    int i = 0;
    Pins *tmp;
    Pins out;

    gates_array[0] = new Gates(2, always_true);
    gates_array[1] = new Gates(2, always_true);
    gates_array[2] = new Gates(2, always_true);
    gates_array[3] = new Gates(2, always_true);
    gates_array[4] = new Gates(2, always_true);
    gates_array[5] = new Gates(2, always_true);
    
    tmp = gates_array[0]->getInputs();
    out = gates_array[0]->getOuput();
    
    pins_array[0] = new Pins(1, ROLE::OUT, &(tmp[1]));
    pins_array[1] = new Pins(2, ROLE::OUT, &(tmp[0]));

    tmp = gates_array[1]->getInputs();
    out = gates_array[1]->getOuput();

    pins_array[2] = new Pins(3, ROLE::IN, &out);

    tmp = gates_array[1]->getInputs();
    out = gates_array[1]->getOuput();

    pins_array[3] = new Pins(4, ROLE::IN, &out);
    pins_array[4] = new Pins(5, ROLE::OUT, &(tmp[0]));

    tmp = gates_array[2]->getInputs();
    out = gates_array[2]->getOuput();

    pins_array[5] = new Pins(6, ROLE::OUT, &(tmp[1]));

    tmp = gates_array[3]->getInputs();
    out = gates_array[3]->getOuput();

    pins_array[6] = new Pins(7, ROLE::OUT, &(tmp[0]));
    pins_array[7] = new Pins(8, ROLE::OUT, &(tmp[1]));

    tmp = gates_array[4]->getInputs();
    out = gates_array[4]->getOuput();

    pins_array[8] = new Pins(9, ROLE::IN, &out);

    pins_array[9] = new Pins(10, ROLE::IN, &out);
    pins_array[10] = new Pins(11, ROLE::OUT, &(tmp[1]));
    
    tmp = gates_array[5]->getInputs();
    out = gates_array[5]->getOuput();

    pins_array[11] = new Pins(12, ROLE::OUT, &(tmp[0]));

    _name = name;
    _gates_nb = 6;
    _pins_nb = 12;
}

#endif
