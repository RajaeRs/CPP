/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 11:37:58 by rrasezin          #+#    #+#             */
/*   Updated: 2023/08/23 21:18:14 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class   Cat : public Animal
{
    private:
        Brain* catBrain;
    public:
        Cat();
        Cat(std::string name, int nb);
        Cat(const Cat& copy);
        Cat& operator=(const Cat& assignement);
        std::string getType(void) const;
        void    makeSound(void) const;
        void    printIdeas(void) const;
        ~Cat();
};