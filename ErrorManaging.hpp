//
// EPITECH PROJECT, 2019
// errorManaging.hpp
// File description:
// Gautier PLANCQ ~ errorManaging.hpp Include file
//
 
#if !defined(ERRORMANAGING_HPP_)
#define ERRORMANAGING_HPP_

#include <exception>
#include <iostream>

class ErrorManaging : public std::exception {
        public:
                ErrorManaging(const std::string &msg = "Unknown error") noexcept : _msg(msg) {};
                ~ErrorManaging(){};
                const char *what() const noexcept override { return _msg.data(); }
        private:
                std::string _msg;
};

#endif // ERRORMANAGING_HPP_
