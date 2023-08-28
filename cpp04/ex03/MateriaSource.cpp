/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 18:36:24 by rrasezin          #+#    #+#             */
/*   Updated: 2023/08/27 21:07:15 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    std::cout << "Default constractor of MateriaSource" << std::endl;
    int i = 0;

    this->inventory = new AMateria*[4];
    while (i < 4)
    {
        inventory[i] = NULL;
        i++;
    }
    return ;
}

MateriaSource::MateriaSource(MateriaSource& copy)
{
    std::cout << "Copy constractor of MateriaSource" << std::endl;
    int i = 0;

    this->inventory = new AMateria*[4];
    while (i < 4)
    {
        this->inventory[i] = copy.inventory[i];
        i++;
    }
}

MateriaSource& MateriaSource::operator=(MateriaSource& assignement)
{
    std::cout << "Assignement operator of MateriaSource" << std::endl;

    int i = 0;

    if (inventory)
        delete[] inventory;
    while (i < 4)
    {
        this->inventory[i] = assignement.inventory[i];
        i++;
    }
    return (*this);
}

void    MateriaSource::learnMateria(AMateria *source)
{
    std::cout << "Learn Materia function of MateriaSource" << std::endl;

    int i = 0;

    while(i < 4 && this->inventory[i] != NULL)
        i++;
    if (i < 4)
    {
        this->inventory[i] = source;
    }
    return ;
}

AMateria* MateriaSource::createMateria(std::string const &type)
{
    std::cout << "Create Materia function of MateriaSource" << std::endl;

    int i = 0;

    while (i < 4 && this->inventory[i] != NULL)
    {
        if (this->inventory[i]->getType() == type)
            return (this->inventory[i]->clone());
        i++;
    }
    return 0;
}

MateriaSource::~MateriaSource()
{
    int i = 0;

    std::cout << "Destractor of MateriaSource" << std::endl;
    while (i < 4)
    {
        if (this->inventory[i] != NULL)
            delete inventory[i];
        i++;
    }
    delete[] inventory;
}