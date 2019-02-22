//
// EPITECH PROJECT, 2019
// Georges Rached
// File description:
// Error Managing Header
//

 
#if !defined(ERRORMANAGING_HPP_)
#define ERRORMANAGING_HPP_

#include <exception>
#include <iostream>

class ErrorManaging : public std::exception {
        public:
                ErrorManaging(const std::string &msg = "Unknown error") noexcept : _str(msg) {};
                ~ErrorManaging(){};
                const char *what() const noexcept override { return _str.data(); }
        private:
                std::string _str;
};

#endif
