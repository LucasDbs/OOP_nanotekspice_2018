//
// EPITECH PROJECT, 2019
// NanoTekSpice
// File description:
// AComponents header
//

#ifndef _ACOMPONENT_HPP_
# define _ACOMPONENT_HPP_

#include "IComponent.hpp"
# include "4001.hpp"
# include "4008.hpp"
# include "4011.hpp"
# include "4013.hpp"
# include "4017.hpp"
# include "4030.hpp"
# include "4040.hpp"
# include "4069.hpp"
# include "4071.hpp"
# include "4081.hpp"
# include "4094.hpp"
# include "4514.hpp"
# include "4801.hpp"
# include "2716.hpp"

namespace nts
{
    class CreateComponent
        {
            public:
                CreateComponent(void);
                ~CreateComponent(void);

                std::unique_ptr<IComponent> createComponent(const std::string &type, const std::string &value);
            
            private:
                std::unique_ptr<IComponent> create4001(const std:: string &value) const noexcept;
                std::unique_ptr<IComponent> create4008(const std:: string &value) const noexcept;
                std::unique_ptr<IComponent> create4011(const std:: string &value) const noexcept;
                std::unique_ptr<IComponent> create4013(const std:: string &value) const noexcept;
                std::unique_ptr<IComponent> create4017(const std:: string &value) const noexcept;
                std::unique_ptr<IComponent> create4030(const std:: string &value) const noexcept;
                std::unique_ptr<IComponent> create4030(const std:: string &value) const noexcept;
                std::unique_ptr<IComponent> create4040(const std:: string &value) const noexcept;
                std::unique_ptr<IComponent> create4069(const std:: string &value) const noexcept;
                std::unique_ptr<IComponent> create4071(const std:: string &value) const noexcept;
                std::unique_ptr<IComponent> create4081(const std:: string &value) const noexcept;
                std::unique_ptr<IComponent> create4094(const std:: string &value) const noexcept;
                std::unique_ptr<IComponent> create4514(const std:: string &value) const noexcept;
                std::unique_ptr<IComponent> create4801(const std:: string &value) const noexcept;
                std::unique_ptr<IComponent> create2716(const std:: string &value) const noexcept;
        };
};

#endif