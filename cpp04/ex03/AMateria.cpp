/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 16:23:46 by rrasezin          #+#    #+#             */
/*   Updated: 2023/08/28 13:15:11 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria()
{
    std::cout << "Default constractor of AMateria." << std::endl;
    type = "noTypeYet";
}

AMateria::AMateria(std::string const& type)
{
    std::cout << "Constractor arg of AMateria." << std::endl;
    this->type = type;
}

AMateria::AMateria(const AMateria& copy)
{
    std::cout << "Copy constractor of AMateria." << std::endl;
    this->type = copy.getType();
}

AMateria&    AMateria::operator=(const AMateria& assignement)
{
    std::cout << "Assignement operator of AMateria." << std::endl;

    (void)assignement;
	return (*this);
}

std::string const& AMateria::getType()const
{
    std::cout << "Get type of AMateria." << std::endl;
	return (this->type);
}

void    AMateria::use(ICharacter& target)
{
    std::cout << "Use function of AMateria." << std::endl;
    (void)target;
};

AMateria::~AMateria()
{
    std::cout << "Destractor of AMateria." << std::endl;
    
};