// //
// // EPITECH PROJECT, 2019
// // 4017.hpp
// // File description:
// // Lucas Duboisse
// //

// #include "../include/Gates.hpp"

// Gates::Gates(int inputs_nb, int outputs_nb, nts::Tristate (*fct)(nts::Tristate *calc), size_t id)
// {
//         Pins inputs[inputs_nb];
//         Pins outputs[outputs_nb];

//         for (int i = 0; i < inputs_nb; i++)
//                 inputs[i].setGateId(id);
//         for (int i = 0; i < outputs_nb; i++) {
//                 outputs[i].setRole(ROLE::OUT);
//                 outputs[i].setGateId(id);
//         }
//         _inputs_nb = inputs_nb;
//         _outputs_nb = outputs_nb;
//         _inputs = inputs;
//         _outputs = outputs;
//         _id = id; 
//         calc = fct;
// }

// Gates::~Gates()
// {
// }

// // nts::Tristate Gates::compute()
// // {
// //         nts::Tristate state_array[_inputs_nb];
// //         nts::Tristate result;

// //         for (int i = 0; i < _inputs_nb; i++) {
// //                 state_array[i] = _inputs[i].getState();
// //         }
// //         if (!state_array)
// //                 return false;
// //         result = calc(state_array);
// //         for (int i = 0; i < _outputs_nb; i++)
// //                 _outputs[i].setState(result);
// //         return true;
// // }

// Pins *Gates::getInputs()
// {
//         return _inputs;
// }

// Pins *Gates::getOuputs()
// {
//         return _outputs;
// }

// int Gates::countInputs()
// {
//         return _inputs_nb;
// }

// int Gates::countOutputs()
// {
//         return _outputs_nb;
// }

// size_t Gates::getId()
// {
//         return _id;
// }
