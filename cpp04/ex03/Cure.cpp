/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 10:51:31 by rrasezin          #+#    #+#             */
/*   Updated: 2023/08/25 11:17:37 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure()
{
    this->type = "Cure";
}

Cure::Cure(const Cure& copy)
{
    this->type = copy.getType();
}

Cure& Cure::operator=(const Cure& assignement)
{
    (void)assignement;
    // this->type = assignement.getType(); // check befor push
    return (*this);
}

AMateria* Cure::clone() const
{
    AMateria *Cure = new class Cure();
    return (Cure);
}

// void    Cure::use(ICharacter& target)
// {
//     std::cout << "* shoots an cure bolt at" << target.getName() << std::endl;
// }

Cure::~Cure(){};