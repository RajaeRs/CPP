/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 15:40:13 by rrasezin          #+#    #+#             */
/*   Updated: 2023/08/15 13:36:24 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class   ClapTrap
{
    private:
        std::string	Name;
        int			HitPoints;
	    int			EnergyPoints;
	    int			AttackDamage;
    public:
        ClapTrap();
        ClapTrap(std::string name);
        ClapTrap(const ClapTrap& copy);
        ClapTrap& 			operator=(const ClapTrap& assignment);
        void    			attack(const std::string& target);
        void    			takeDamage(unsigned int amount);
        void    			beRepaired(unsigned int amount);
        int             	getHitPoints() const;
        int             	getEnergyPoints() const;
        int             	getAttackDamage() const;
        const std::string	getName() const;
        ~ClapTrap();
};