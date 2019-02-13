//
// EPITECH PROJECT, 2019
// NanoTekSpice 
// File description:
// IComponent header
//

#include <iostream>

namespace nts
{
    enum Tristate {
        UNDEFINED = (-true),
        TRUE = true,
        FALSE = false
    };
    class IComponent
    {
        public:
            virtual ~IComponent() = default;
        
        public:
            virtual nts::Tristate compute(std:: size_t  pin = 1) = 0;
            virtual void setLink(std::size_t pin, nts::IComponent &other, std::size_t  otherPin) = 0;
            virtual void dump() const = 0;
    };
};

std::unique_ptr<IComponent>createComponent(const std::string &type, const std::string &value);
