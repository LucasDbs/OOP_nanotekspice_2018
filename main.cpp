//
// EPITECH PROJECT, 2019
// main.cpp
// File description:
// Georges Rached
//

#include "components/include/Gates.hpp"
#include "components/include/4081.hpp"
#include "shell/include/Shell.hpp"
#include "factory/componentFactory.hpp"

int main()
{
        componentFactory fact;
        auto *CMP4081 = fact.createComponent("CMP4081", "ma carte lel");
        auto *InputA = fact.createComponent("Input", "1");
        auto *InputB = fact.createComponent("Input", "0");
        auto *InputC = fact.createComponent("Input", "0");
        auto *Output = fact.createComponent("Output", "lol");

        CMP4081->setLink(1, *InputA, 1);
        CMP4081->setLink(2, *InputB, 1);
        CMP4081->setLink(3, *CMP4081, 4);
        CMP4081->setLink(5, *InputC, 1);
        CMP4081->setLink(6, *Output, 1);

        std::cout << Output->compute(1) << std::endl;

        delete CMP4081;
        delete InputA;
        delete InputB;
        delete InputC;
        delete Output;
        // std::cout << test->countGates() << std::endl;
        return 0;
       // CMP4071 test("carte test");
        // if (argc < 2) {
        //         std::cerr << "No filename specified" << std::endl;
        //         return (84);
        // }

        // Shell sim(argv[1]);
        // //std::cout << "Le nom de la carte est: " <<  test.getName();
        // return sim.launch();;
}