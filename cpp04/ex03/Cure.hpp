/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 20:17:21 by rrasezin          #+#    #+#             */
/*   Updated: 2023/08/25 11:02:28 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "AMateria.hpp"

class   Cure : public AMateria
{
    public :
        Cure();
		Cure(const Cure& copy);
		Cure&	operator=(const Cure& assignement);
        // void use(ICharacter& target);
		AMateria* clone() const;
		~Cure();
};