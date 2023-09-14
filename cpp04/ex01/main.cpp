/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 11:22:35 by rrasezin          #+#    #+#             */
/*   Updated: 2023/08/24 16:13:37 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

void    arrayOfAnimals(void)
{
    Animal animalTest[20];
    int i = 0;

    while (i < 10)
    {
        animalTest[i] = Cat();
        i++;
    }
    while (i < 20)
    {
        animalTest[i] = Dog();
        i++;
    }
    return ;
}

int main()
{
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    
    arrayOfAnimals();
    
    Dog dog1("ROW Dog", 100);
    Dog dog2(dog1);

    dog1.printIdeas();
    dog2.printIdeas();

    delete j;//should not create a leak
    delete i;

    return (0);
}
