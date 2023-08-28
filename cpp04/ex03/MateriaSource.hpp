/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 18:36:28 by rrasezin          #+#    #+#             */
/*   Updated: 2023/08/27 21:07:15 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "IMateriaSource.hpp"

class   MateriaSource : public IMateriaSource
{
    protected:
        AMateria **inventory;
    public:
        MateriaSource();
        MateriaSource(MateriaSource &copy);
        MateriaSource& operator=(MateriaSource& assignement);
        void    learnMateria(AMateria* source);
		AMateria* createMateria(std::string const &type);
        ~MateriaSource();
};