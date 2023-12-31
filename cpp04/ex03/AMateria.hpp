/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 16:18:19 by rrasezin          #+#    #+#             */
/*   Updated: 2023/08/26 12:03:19 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "ICharacter.hpp"

class	ICharacter;

class   AMateria
{
    protected:
		std::string type;
    public:
        AMateria();
		AMateria(std::string const & type);
		AMateria(const AMateria & copy);
		AMateria& operator=(const AMateria& assignement);
		std::string const& getType() const;
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
		virtual ~AMateria();
};