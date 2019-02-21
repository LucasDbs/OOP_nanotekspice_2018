//
// EPITECH PROJECT, 2019
// 4017.hpp
// File description:
// Lucas Duboisse
//

#if !defined(PINS_HPP)
#define PINS_HPP

namespace nts
{
        enum Tristate {
                UNDEFINED = (-true),
                TRUE = true,
                FALSE = false
        };
}

enum ROLE
{
        OUT,
        IN,
        CLOCK
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
                void setState(nts::Tristate state) { _state = state; }

                void setReference(Pins *Pin_next) { Pin_next->_ref = _ref; }
                Pins *getReference() { return _ref; }

                ROLE getRole() { return _role; }
                void setRole(ROLE role) { _role = role; }

                void setGateId(size_t id) { _gate_id = id; }
                size_t getGateId() { return _gate_id; }

                void clock();
        private:
                int _id;
                nts::Tristate _state;
                ROLE _role;
                Pins *_ref;
                size_t _gate_id;
};

void Pins::clock()
{
        if (_role != ROLE::CLOCK) {
                perror("error:clock Current Pin is not a clock\n");
                return;
        } else if (_state == nts::Tristate::FALSE) {
                _state == nts::Tristate::TRUE;
        } else { 
                _state == nts::Tristate::FALSE;
        }
}

Pins::Pins()
{
        _id = 0;
        _role = ROLE::IN;
        _state = nts::Tristate::UNDEFINED;
        _ref = NULL;
        _gate_id = -1;
}

Pins::Pins(int id, ROLE role)
{
        _id = id;
        _role = role;
        _state = nts::Tristate::UNDEFINED;
        _ref = NULL;
        _gate_id = -1;
}

Pins::Pins(int id, ROLE role, Pins *Pin_next)
{
        _id = id;
        _role = role;
        _state = nts::Tristate::UNDEFINED;
        _ref = NULL;
        Pin_next->_ref = this;
        _gate_id = -1;
}


#endif
