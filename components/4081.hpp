//
// EPITECH PROJECT, 2019
// NanoTekSpice
// File description:
// 4081 header
//

#ifndef _4081_HPP_
# define _4081_HPP

#include "IComponent.hpp"

namespace nts
{
  class CM4081 : public nts::IComponent
  {
    public:
        CMP4081(const std::string &name);
        virtual ~CMP4081(void);
  };
};

#endif