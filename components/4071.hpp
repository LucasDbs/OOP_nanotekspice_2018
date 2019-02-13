//
// EPITECH PROJECT, 2019
// NanoTekSPice
// File description:
// 4071 header
//

#include "IComponent.hpp"

class CMP4071: public nts::IComponent
{
    public:
        CMP4071(const std::string &name);
        CMP4071(const CMP4071 &);
        ~CMP4071(void);
};
