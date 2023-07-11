/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 18:11:44 by rrasezin          #+#    #+#             */
/*   Updated: 2023/07/10 16:44:05 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type)
{
    this->type = type;
}

const std::string &Weapon::getType()
{
    return (this->type);
}

void    Weapon::setType(std::string newType)
{
    this->type = newType;
}