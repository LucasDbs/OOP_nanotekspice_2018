//
// EPITECH PROJECT, 2019
// main.cpp
// File description:
// Gautier PLANCQ ~ main.cpp Source file
//

#include <iostream>
#include "Gates.hpp"
#include "4071.hpp"
#include "Simulator.hpp"
#include "PinComponent.hpp"

int main(int argc, char const *argv[])
{
       // CMP4071 test("carte test");
        if (argc < 2) {
                std::cerr << "No filename specified" << std::endl;
                return (84);
        }

        Simulator sim(argv[1]);
        //std::cout << "Le nom de la carte est: " <<  test.getName();
        return sim.launch();;
}