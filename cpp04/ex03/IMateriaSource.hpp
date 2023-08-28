/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 11:14:28 by rrasezin          #+#    #+#             */
/*   Updated: 2023/08/27 18:58:23 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AMateria.hpp"
#include <iostream>

class IMateriaSource
{
    public:
        virtual ~IMateriaSource(){}
        virtual void learnMateria (AMateria*) = 0;
        virtual AMateria* createMateria(std::string const & type) = 0;
};