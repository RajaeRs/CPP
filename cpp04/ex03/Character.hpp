/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 11:47:23 by rrasezin          #+#    #+#             */
/*   Updated: 2023/08/28 13:24:13 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "ICharacter.hpp"

typedef	struct	s_floor
{
	AMateria		*save;
	struct s_floor *next;
	
}				t_floor;

class   Character : public ICharacter
{
	private :
        std::string	Name;
        t_floor		*SaveAddress;
		t_floor 		*new_address(AMateria *new_);
		void			add_back(t_floor **old, t_floor *new_);
		void			freeFloor(t_floor *save);
    protected :
        AMateria	**inventory;
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
};
