/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 18:04:37 by rrasezin          #+#    #+#             */
/*   Updated: 2023/07/10 16:43:56 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>

class   Weapon
{
    private:
        std::string type;
    public:
        Weapon(){};
        Weapon(std::string type);
        const std::string &getType();
        void        setType(std::string newType);
};

#endif