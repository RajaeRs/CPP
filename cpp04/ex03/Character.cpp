/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 12:10:14 by rrasezin          #+#    #+#             */
/*   Updated: 2023/08/25 12:55:07 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character()
{
    this->Name = "noName";
    idx = 0;
    slot = new AMateria[4];
}

Character::Character(std::string Name)
{
    this->Name = Name;
    idx = 0;
    slot = new AMateria[4];
}


Character::Character(const Character& copy)
{
    int i = 0;

    this->slot = new AMateria[4];
    this->Name = copy.getName();
    this->idx = copy.idx;
    while (this->slot[i] != NULL)
    {
        this->slot[i] = copy->slot[i];
        i++;
    }
}

Character& operator=(const Character& assignement)
{
    int i = 0;

    this->idx = copy.idx;
    this->Name = copy.getName();
    while (this->slot[i] != NULL)
    {
        this->slot[i] = copy->slot[i];
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
    int i = 0;

    while (i < this->idx)
        i++;
    if (i < 4)
    {
        this->slot[i] = new AMateria();
        this->slot[i] = m;
        idx++;
    }
}

void    Character::unequip(int idx)
{
    
}