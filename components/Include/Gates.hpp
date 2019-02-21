//
// EPITECH PROJECT, 2019
// 4017.hpp
// File description:
// Lucas Duboisse
//

#if !defined(GATES_HPP)
#define GATES_HPP

#include "Pins.hpp"
#include "IComponent.hpp"

class Gates
{
        public:
                Gates(int inputs_nb, int outputs_nb,  nts::Tristate (*fct)(nts::Tristate *calc), size_t id);
                ~Gates();
                Pins *getInputs();
                Pins *getOuputs();
                int countInputs();
                int countOutputs();
                size_t getId();
                bool compute();
        private:
                int _inputs_nb;
                int _outputs_nb;
                Pins *_inputs;
                Pins *_outputs;
                size_t _id;
                nts::Tristate (*calc) (nts::Tristate *);
};

#endif // GATES_HPP
