/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 18:28:22 by rrasezin          #+#    #+#             */
/*   Updated: 2023/07/12 19:36:11 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"

class   HumanB
{
    private:
        Weapon      *weapon;
        std::string name;
    public:
        HumanB(std::string name);
        ~HumanB(){};
        void    setWeapon(Weapon &weapon);
        void    attack();
};

#endif 