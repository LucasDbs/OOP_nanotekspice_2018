// //
// // EPITECH PROJECT, 2019
// // NanoTekSpice
// // File description:
// // 4069 header
// //

// #include "../include/4069.hpp"

// nts::Tristate always_true(nts::Tristate *array)
// {
//     return nts::Tristate::TRUE;
// }

// CMP4069::CMP4069(std::string name)
// {
//     int id = 1;
//     int i = 0;
//     Pins *tmp_in;
//     Pins *tmp_out;

//     gates_array[0] = new Gates(2, 1, always_true, 1);
//     gates_array[1] = new Gates(2, 1, always_true, 2);
//     gates_array[2] = new Gates(2, 1, always_true, 3);
//     gates_array[3] = new Gates(2, 1, always_true, 4);
//     gates_array[4] = new Gates(2, 1, always_true, 5);
//     gates_array[5] = new Gates(2, 1, always_true, 6);
    
//     tmp_in = gates_array[0]->getInputs();
//     tmp_out = gates_array[0]->getOuputs();
    
//     pins_array[0] = new Pins(1, ROLE::OUT, &(tmp_in[1]));
//     pins_array[1] = new Pins(2, ROLE::OUT, &(tmp_in[0]));
//     pins_array[2] = new Pins(3, ROLE::OUT, &(tmp_out[0]));

//     tmp_in = gates_array[1]->getInputs();
//     tmp_out = gates_array[1]->getOuputs();

//     pins_array[3] = new Pins(4, ROLE::IN, &(tmp_out[0]));
//     pins_array[4] = new Pins(5, ROLE::OUT, &(tmp_in[0]));
//     pins_array[5] = new Pins(6, ROLE::OUT, &(tmp_in[1]));

//     tmp_in = gates_array[1]->getInputs();
//     tmp_out = gates_array[1]->getOuputs();

//     pins_array[6] = new Pins(7, ROLE::OUT, &(tmp_in[0]));
//     pins_array[7] = new Pins(8, ROLE::OUT, &(tmp_in[1]));
//     pins_array[8] = new Pins(9, ROLE::IN, &(tmp_out[0]));

//     tmp = gates_array[2]->getInputs();
//     out = gates_array[2]->getOuputs();

//     pins_array[5] = new Pins(6, ROLE::OUT, &(tmp[1]));

//     tmp = gates_array[3]->getInputs();
//     out = gates_array[3]->getOuputs();

//     pins_array[6] = new Pins(7, ROLE::OUT, &(tmp[0]));
//     pins_array[7] = new Pins(8, ROLE::OUT, &(tmp[1]));

//     tmp = gates_array[4]->getInputs();
//     out = gates_array[4]->getOuputs();

//     pins_array[8] = new Pins(9, ROLE::IN, &out);

//     pins_array[9] = new Pins(10, ROLE::IN, &out);
//     pins_array[10] = new Pins(11, ROLE::OUT, &(tmp[1]));
    
//     tmp = gates_array[5]->getInputs();
//     out = gates_array[5]->getOuputs();

//     pins_array[11] = new Pins(12, ROLE::OUT, &(tmp[0]));

//     _name = name;
//     _gates_nb = 6;
//     _pins_nb = 12;
// }

// std::string CMP4069::getName()
// {
//     return _name;
// }

// Pins **CMP4069::getPins()
// {
//     return pins_array;
// }

// Gates **CMP4069::getGates()
// {
//     return gates_array;
// }

// int CMP4069::countPins()
// {
//     return _pins_nb;
// }

// int CMP4069::countGates()
// {
//     return _gates_nb;
// }

// // Set Link a implementer