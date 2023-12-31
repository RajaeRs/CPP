/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 11:37:58 by rrasezin          #+#    #+#             */
/*   Updated: 2023/08/22 16:55:42 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"

class   Cat : public Animal
{
    public:
        Cat();
        Cat(const Cat& copy);
        Cat& operator=(const Cat& assignement);
        std::string getType(void) const;
        void    makeSound(void) const;
        ~Cat();
};