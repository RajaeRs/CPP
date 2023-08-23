/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 12:03:15 by rrasezin          #+#    #+#             */
/*   Updated: 2023/08/23 11:51:26 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class   Dog : public Animal
{
    private:
        Brain* dogBrain;
    public:
        Dog();
        Dog(std::string name, int nb);
        Dog(const Dog& copy);
        Dog& operator=(const Dog& assignement);
        std::string getType(void) const;
        void    makeSound(void) const;
        void    printIdeas(void) const;
        ~Dog();
};