//
// EPITECH PROJECT, 2019
// main.cpp
// File description:
// Georges Rached
//

#include <iostream>
#include "components/include/Gates.hpp"
#include "components/include/4071.hpp"
#include "shell/include/Shell.hpp"
#include "components/include/PinComponent.hpp"

int main(int ac, char **av)
{
        return 0;
        CMP4071 test("carte test");
        if (ac < 2) {
        std::cerr << "No filename specified" << std::endl;
        return (84);
        }

        Shell sim(av[1]);
        std::cout << "Le nom de la carte est: " <<  test.getName();
        return sim.launch();;
}
