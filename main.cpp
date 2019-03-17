//
// EPITECH PROJECT, 2019
// main.cpp
// File description:
// Georges Rached
//

#include "components/include/4081.hpp"
#include "shell/include/Shell.hpp"
#include "factory/componentFactory.hpp"
#include "shell/include/ErrorManaging.hpp"
#include "shell/include/Parser.hpp"

int main(int ac, char **av)
{
        if (ac < 2) {
                std::cerr << "No filename specified" << std::endl;
                return (84);
        }
        try {
                Parser pars(av[1]);

                pars.parseChipset(av);
                pars.parseLink();
                Shell shell(pars);

                shell.launch();
        }
        catch (const std::exception &e) {
                std::cerr << e.what() << std::endl;
                return (84);
        }
        return (0);
}