//
// EPITECH PROJECT, 2019
// NanoTekSpice
// File description:
// Gates Header
//

#include "Pins.hpp"

#if !defined(GATES_HPP)
#define GATES_HPP


class Gates
{
    public:
        Gates(int inputs_nb, nts::Tristate (*fct)(nts::Tristate *));
        ~Gates() { }
        Pins *getInputs() { return _inputs; }
        Pins getOuput() { return _output; }
        int countInputs() { return _inputs_nb; }

    private:
        int _inputs_nb;
        Pins *_inputs;
        Pins _output;
        nts::Tristate (*calc) (nts::Tristate *);
};

Gates::Gates(int inputs_nb, nts::Tristate (*fct)(nts::Tristate *))
{
    Pins inputs[inputs_nb];
    Pins output(0, ROLE::OUT);

    _inputs_nb = inputs_nb;
    _inputs = inputs;
    _output = output; 
    calc = fct;
}

#endif
