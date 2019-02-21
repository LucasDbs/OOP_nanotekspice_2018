//
// EPITECH PROJECT, 2019
// main.cpp
// File description:
// Gautier PLANCQ ~ main.cpp Source file
//

#include <iostream>
#include "Gates.hpp"
#include "components/4071.hpp"
#include "Simulator.hpp"
#include "PinComponent.hpp"

/*
        WRITE ALL TESTS HERE
*/

void test_Pin_component()
{
        PinComponent card("or", ROLE::IN);
        int a = 0;
        int i = 0;

        Gates **gates = card.getGates();

        std::cout << "The card name is : " << card.getName() << std::endl;
        std::cout << "The card has " << card.countPins() << " pins\n";
        while (i < card.countGates()) {
                std::cout << "Gate with " << gates[i]->countInputs() << " inputs and 1 output" << std::endl;
                i++;
        }
}

void test_CMP4071_component()
{
        CMP4071 card("cmp4071");
        int a = 0;
        int i = 0;

        Gates **gates = card.getGates();

        std::cout << "The card name is : " << card.getName() << std::endl;
        std::cout << "The card has " << card.countPins() << " pins\n";
        while (i < card.countGates()) {
                std::cout << "Gate with " << gates[i]->countInputs() << " inputs and 1 output" << std::endl;
                i++;
        }
}

int main(int argc, char const *argv[])
{
        test_Pin_component();
        test_CMP4071_component();
        return 0;
}
