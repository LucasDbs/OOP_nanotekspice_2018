// //
// // EPITECH PROJECT, 2019
// // 4017.hpp
// // File description:
// // Lucas Duboisse
// //

// #include "../include/Pins.hpp"

// Pins::Pins()
// {
//         _id = 0;
//         _role = ROLE::IN;
//         _state = nts::Tristate::UNDEFINED;
//         _ref = NULL;
//         _gate_id = -1;
// }

// Pins::Pins(int id, ROLE role)
// {
//         _id = id;
//         _role = role;
//         _state = nts::Tristate::UNDEFINED;
//         _ref = NULL;
//         _gate_id = -1;
// }

// Pins::Pins(int id, ROLE role, Pins *Pin_next)
// {
//         _id = id;
//         _role = role;
//         _state = nts::Tristate::UNDEFINED;
//         _ref = NULL;
//         Pin_next->_ref = this;
//         _gate_id = -1;
// }

// Pins::~Pins()
// {
// }

// void Pins::clock()
// {
//         if (_role != ROLE::CLOCK) {
//                 // perror("error:clock Current Pin is not a clock\n");
//                 return;
//         } else if (_state == nts::Tristate::FALSE) {
//                 _state = nts::Tristate::TRUE;
//         } else { 
//                 _state = nts::Tristate::FALSE;
//         }
// }

// int Pins::getId()
// {
//         return _id;
// }    

// nts::Tristate Pins::getState()
// {
//         return _state;
// }

// void Pins::setState(nts::Tristate state)
// {
//         _state = state;
// }

// void Pins::setReference(Pins *Pin_next)
// {
//         Pin_next->_ref = _ref;
// }

// Pins *Pins::getReference()
// {
//         return _ref;
// }

// ROLE Pins::getRole()
// {
//         return _role;
// }

// void Pins::setRole(ROLE role)
// {
//         _role = role;
// }

// void Pins::setGateId(size_t id)
// {
//         _gate_id = id;
// }

// size_t Pins::getGateId()
// {
//         return _gate_id;
// }
