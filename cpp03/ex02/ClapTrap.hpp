/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 15:40:13 by rrasezin          #+#    #+#             */
/*   Updated: 2023/08/17 11:50:34 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class   ClapTrap
{
    private:
        std::string	Name;
        unsigned int			HitPoints;
	    unsigned int			EnergyPoints;
	    unsigned int			AttackDamage;
    public:
        ClapTrap();
        ClapTrap(std::string name);
        ClapTrap(const ClapTrap& copy);
        ClapTrap& 			operator=(const ClapTrap& assignment);
        void    			attack(const std::string& target);
        void    			takeDamage(unsigned int amount);
        void    			beRepaired(unsigned int amount);
        unsigned int        getHitPoints() const;
        unsigned int        getEnergyPoints() const;
        unsigned int        getAttackDamage() const;
        void                setHitPoints(int HitPoints);
        void                setEnergyPoints(int EnergyPoints);
        void                setAttackDamage(int AttackDamage);
        void                setName(std::string Name);
        const std::string	getName() const;
        ~ClapTrap();
};