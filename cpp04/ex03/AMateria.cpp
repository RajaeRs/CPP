/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 16:23:46 by rrasezin          #+#    #+#             */
/*   Updated: 2023/08/25 11:12:12 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria()
{
    type = "noTypeYet";
}

AMateria::AMateria(std::string const& type)
{
    this->type = type;
}

AMateria::AMateria(const AMateria& copy)
{
    this->type = copy.getType();
}

AMateria&    AMateria::operator=(const AMateria& assignement)
{
	// this->type = assignement.getType();
    (void)assignement;
	return (*this);
}

std::string const& AMateria::getType()const
{
	return (this->type);
}

// void    AMateria::use(ICharacter& target){};

AMateria::~AMateria(){};