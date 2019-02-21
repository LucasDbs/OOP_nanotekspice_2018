//
// EPITECH PROJECT, 2019
// 4017.hpp
// File description:
// Lucas Duboisse
//

#if !defined(PINS_HPP_)
#define PINS_HPP_

#include "IComponent.hpp"

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
                ~Pins();

                int getId();   

                nts::Tristate getState();
                void setState(nts::Tristate state);

                void setReference(Pins *Pin_next);
                Pins *getReference();

                ROLE getRole();
                void setRole(ROLE role);

                void setGateId(size_t id);
                size_t getGateId();

                void clock();
        private:
                int _id;
                nts::Tristate _state;
                ROLE _role;
                Pins *_ref;
                size_t _gate_id;
};

#endif
