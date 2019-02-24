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
#include "shell/include/ErrorManaging.hpp"

int main()
{
        // int a = 0;
        // // int b = 1;
        // try {
        //         if (a == 0)
        //                 throw ErrorManaging("ERROR: a = 0");
        // }
        // catch (std::exception &e) {
        //         std::cout << e.what() << std::endl;
        // }
        componentFactory fact;
        auto *CMP4081 = fact.createComponent("CMP4081", "ma carte lel");
        auto *InputA = fact.createComponent("Input", "1");
        auto *InputB = fact.createComponent("Input", "0");
        auto *InputC = fact.createComponent("Input", "0");
        auto *Output = fact.createComponent("Output", "lol");

        CMP4081->setLink(1, *InputA, 1);
        CMP4081->setLink(2, *InputB, 1);
        CMP4081->setLink(3, *Output, 1);

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