/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 11:22:35 by rrasezin          #+#    #+#             */
/*   Updated: 2023/08/23 21:35:43 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

void    AnimalAsPointer(AAnimal& animal)
{
    animal.makeSound();
    return ;
}

int main()
{
    const AAnimal* j = new Dog();
    const AAnimal* i = new Cat();
    
    Cat     catAnimal;

    delete j;//should not create a leak
    delete i;
    
    AnimalAsPointer(catAnimal);

    return (0);
}
