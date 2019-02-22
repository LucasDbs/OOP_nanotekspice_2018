//
// EPITECH PROJECT, 2019
// 4017.hpp
// File description:
// Lucas Duboisse
//

#if !defined(GATES_HPP)
#define GATES_HPP

#include <iostream>
#include "Pins.hpp"

class Gates
{
        public:
                Gates(int inputs_nb, int outputs_nb,  bool (*fct)(bool *calc), size_t id);
                ~Gates();
                Pins *getInputs();
                Pins *getOuputs();
                int countInputs();
                int countOutputs();
                std::size_t getId();
                // bool compute();
        private:
                int _inputs_nb;
                int _outputs_nb;
                Pins *_inputs;
                Pins *_outputs;
                size_t _id;
                bool (*calc)(bool *);
};

#endif // GATES_HPP
