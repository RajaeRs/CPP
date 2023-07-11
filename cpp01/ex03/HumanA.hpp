/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 18:18:42 by rrasezin          #+#    #+#             */
/*   Updated: 2023/07/10 16:44:28 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"

class   HumanA
{
    private:
        Weapon      &weapon;
        std::string name;
    public:
        HumanA(std::string name, Weapon &weapon);
        ~HumanA(){};
        void    attack();
};

#endif