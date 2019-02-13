//
// EPITECH PROJECT, 2019
// NanoTekSpice
// File description:
// Pin header
//

#ifndef _PIN_HPP_
# define _PIN_HPP_

#include <string>
#include "../components/IComponent.hpp"

class Pin
    {
    private:
        id;
        role_in;
        role_out;
        pin;
        state;
        Gate *gate;

    public:
        Pin();
        ~Pin():
};

#endif