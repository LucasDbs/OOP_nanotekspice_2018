//
// EPITECH PROJECT, 2019
// NanoTekSpice
// File description:
// Pins Header
//

#if !defined(PINS_HPP)
#define PINS_HPP

#include <iostream> 
#include "IComponent.hpp"

enum ROLE {
    OUT,
    IN
};

class Pins
{
    public:
        Pins(int id, ROLE role, Pins *ref);
        Pins(int id, ROLE role);
        Pins();
        ~Pins(){};

        int getId() { return _id; }    
        nts::Tristate getState() { return _state; }
        ROLE getRole() { return _role; }
        Pins *getReference() { return _ref; }
        
        void link_to_pin(Pins *link);

    protected:
        int _id;
        nts::Tristate _state;
        ROLE _role;
        Pins *_ref;
};

Pins::Pins()
{
    _id = 0;
    _role = ROLE::IN;
    _state = nts::Tristate::UNDEFINED;
    _ref = NULL;
}

Pins::Pins(int id, ROLE role)
{
    _id = id;
    _role = role;
    _state = nts::Tristate::UNDEFINED;
    _ref = NULL;
}

Pins::Pins(int id, ROLE role, Pins *ref)
{
    _id = id;
    _role = role;
    _state = nts::Tristate::UNDEFINED;
    _ref = ref;
}

void Pins::link_to_pin(Pins *link)
{
    link->_ref = this;
    _ref = link;
}

#endif // PINS_HPP
