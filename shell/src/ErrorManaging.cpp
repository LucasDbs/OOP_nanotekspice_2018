//
// EPITECH PROJECT, 2019
// Lucas Duboisse
// File description:
// ErrorManaging.cpp
//

#include "../include/ErrorManaging.hpp"

ErrorManaging::ErrorManaging(const std::string &str) noexcept
{
        _msg = str;
}

ErrorManaging::~ErrorManaging()
{
}

const char *ErrorManaging::what() const noexcept
{
        return _msg.data();
}