/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 12:03:15 by rrasezin          #+#    #+#             */
/*   Updated: 2023/08/18 12:03:31 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"

class   Dog : public Animal
{
    public:
        Dog();
        Dog(const Dog& copy);
        Dog& operator=(const Dog& assignement);
        std::string getType(void) const;
        void    makeSound(void);
        ~Dog();
};