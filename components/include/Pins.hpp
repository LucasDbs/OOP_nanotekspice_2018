//
// EPITECH PROJECT, 2019
// 4017.hpp
// File description:
// Lucas Duboisse
//

#if !defined(PINS_HPP_)
#define PINS_HPP_

#include <iostream>

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

                bool getState();
                void setState(bool state);

                void setReference(Pins *Pin_next);
                Pins *getReference();

                ROLE getRole();
                void setRole(ROLE role);

                void setGateId(std::size_t id);
                std::size_t getGateId();

                void clock();
        private:
                int _id;
                bool _state;
                ROLE _role;
                Pins *_ref;
                size_t _gate_id;
};

#endif
