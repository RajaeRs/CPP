/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 12:10:14 by rrasezin          #+#    #+#             */
/*   Updated: 2023/08/28 13:18:30 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character()
{
    std::cout << "Default constractor of Character." << std::endl;
    int i = 0;

    this->Name = "noName";
    inventory = new AMateria*[4];
    while (i < 4)
    {
        inventory[i] = NULL;
        i++;
    }
}

Character::Character(std::string Name)
{
    std::cout << "Constractor arg of Character." << std::endl;
    int i = 0;

    this->Name = Name;
    this->inventory = new AMateria*[4];
    while (i < 4)
    {
        inventory[i] = NULL;
        i++;
    }
}

Character::Character(const Character& copy)
{
    std::cout << "Copy constractor of Character." << std::endl;

    int i = 0;

    this->inventory = new AMateria*[4];
    this->Name = copy.getName();
    while (i < 4)
    {
        this->inventory[i] = copy.inventory[i];
        i++;
    }
}

Character& Character::operator=(const Character& assignement)
{
    std::cout << "Assignement operator of Character." << std::endl;

    int i = 0;

    if (inventory)
        delete[] inventory;
    this->inventory = new AMateria*[4];
    this->Name = assignement.getName();
    while (i < 4)
    {
        this->inventory[i] = assignement.inventory[i];
        i++;
    }
    return (*this);
}

std::string const& Character::getName() const
{
    return (this->Name);
}

void    Character::equip(AMateria* m)
{
    std::cout << "Equip." << std::endl;
    int i = 0;

    while (this->inventory[i] != NULL && i < 4)
        i++;
    if (i < 4)
    {
        this->inventory[i] = m;
    }
}

void    Character::unequip(int idx)
{

    std::cout << "Unequip." << std::endl;
    if (idx >= 0 && idx < 4)
    {
        add_back(&this->SaveAddress, new_address(this->inventory[idx]));
        this->inventory[idx] = NULL;
    }
}

void    Character::use(int idx, ICharacter& target)
{
    std::cout << "Use function of Character." << std::endl;

    if (idx >= 0 && idx < 4 && this->inventory[idx] != NULL)
    {
		this->inventory[idx]->use(target);
    }
}

Character::~Character()
{
    int i = 0;

    std::cout << "Destractor of Character." << std::endl;
    while (i < 4)
    {
        if (this->inventory[i] != NULL)
            delete this->inventory[i];
        i++;
    }
    freeFloor(SaveAddress);
    delete[] this->inventory;
};