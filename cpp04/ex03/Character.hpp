/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 11:47:23 by rrasezin          #+#    #+#             */
/*   Updated: 2023/08/25 12:46:53 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "ICharacter.hpp"

class   Character : public ICharacter
{
	private :
        std::string	Name;
    protected :
        AMateria	**slot;
        int			idx;
    public :
        Character();
        Character(std::string Name);
        Character(const Character& copy);
        Character&  operator=(const Character& assignement);
        std::string const& getName() const;
        void    equip(AMateria* m);
        void    unequip(int idx);
        void    use(int idx, ICharacter& target);
        ~Character();
}