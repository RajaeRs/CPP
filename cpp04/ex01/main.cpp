/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 11:22:35 by rrasezin          #+#    #+#             */
/*   Updated: 2023/08/23 11:54:41 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
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
    // const Animal* j = new Dog();
    // const Animal* i = new Cat();
    
    // arrayOfAnimals();
    
    // delete j;//should not create a leak
    // delete i;
    
    // Dog doog;
    Dog dog1("crezy Dog", 100);
    Dog dog2(dog1);
    // doog.printIdeas();
    dog1.printIdeas();
    dog2.printIdeas();

    // dooog = doog;

    return (0);
}
