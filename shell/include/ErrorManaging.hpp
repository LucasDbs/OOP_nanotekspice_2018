//
// EPITECH PROJECT, 2019
// Lucas Duboisse
// File description:
// ErrorManaging.hpp
//
 
#if !defined(ERRORMANAGING_HPP_)
#define ERRORMANAGING_HPP_

#include <exception>
#include <iostream>

class ErrorManaging : public std::exception {
        public:
                ErrorManaging(const std::string &str) noexcept;
                virtual ~ErrorManaging();
                virtual const char *what() const noexcept;
        private:
                std::string _msg;
};

#endif
