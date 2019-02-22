//
// EPITECH PROJECT, 2019
// 4017.hpp
// File description:
// Lucas Duboisse
//

#include "../include/Pins.hpp"

Pins::Pins()
{
        _id = 0;
        _role = ROLE::IN;
        _state = (-true);
        _ref = NULL;
        _gate_id = -1;
}

Pins::Pins(int id, ROLE role)
{
        _id = id;
        _role = role;
        _state = (-true);
        _ref = NULL;
        _gate_id = -1;
}

Pins::Pins(int id, ROLE role, Pins *Pin_next)
{
        _id = id;
        _role = role;
        _state = (-true);
        _ref = NULL;
        Pin_next->_ref = this;
        _gate_id = -1;
}

Pins::~Pins()
{
}

void Pins::clock()
{
        if (_role != ROLE::CLOCK) {
                // perror("error:clock Current Pin is not a clock\n");
                return;
        } else if (_state == false) {
                _state = true;
        } else { 
                _state = false;
        }
}

int Pins::getId()
{
        return _id;
}    

bool Pins::getState()
{
        return _state;
}

void Pins::setState(bool state)
{
        _state = state;
}

void Pins::setReference(Pins *Pin_next)
{
        Pin_next->_ref = _ref;
}

Pins *Pins::getReference()
{
        return _ref;
}

ROLE Pins::getRole()
{
        return _role;
}

void Pins::setRole(ROLE role)
{
        _role = role;
}

void Pins::setGateId(size_t id)
{
        _gate_id = id;
}

size_t Pins::getGateId()
{
        return _gate_id;
}
