/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 20:52:31 by rrasezin          #+#    #+#             */
/*   Updated: 2023/08/25 20:10:14 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "AMateria.hpp"

class   Ice : public AMateria
{
    public :
        Ice();
        Ice(const Ice& copy);
        Ice& operator=(const Ice& assignement);
        void use(ICharacter& target);
        AMateria* clone() const;
        ~Ice();
};