//
// EPITECH PROJECT, 2019
// Lucas Duboisse
// File description:
// Input.hpp
//

#if !defined(INPUT_HPP_)
#define INPUT_HPP_

#include "Pins.hpp"

class Input
{
        private:
                Pins *pin;
        public:
                Input();
                ~Input();
};

#endif // INPUT_HPP_
