/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 10:51:31 by rrasezin          #+#    #+#             */
/*   Updated: 2023/08/27 19:45:10 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure()
{
    std::cout << "Default constractor of Cure." << std::endl;

    this->type = "cure";
}

Cure::Cure(const Cure& copy)
{
    std::cout << "Copy constractor of Cure." << std::endl;

    this->type = copy.getType();
}

Cure& Cure::operator=(const Cure& assignement)
{
    std::cout << "Assignement operator of Cure." << std::endl;

    (void)assignement;
    //   this->type = assignement.getType();   check befor push
    return (*this);
}

AMateria* Cure::clone() const
{
    std::cout << "Clone function of Cure." << std::endl;

    AMateria *Cure = new class Cure();
    return (Cure);
}

void    Cure::use(ICharacter& target)
{
    std::cout << "Use function of Cure." << std::endl;

    std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}

Cure::~Cure()
{
    std::cout << "Destractor of Cure." << std::endl;
};