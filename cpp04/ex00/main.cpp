/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 11:22:35 by rrasezin          #+#    #+#             */
/*   Updated: 2023/08/18 12:10:09 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
    Animal *ani = new Cat();
    Animal *ani2 = new Dog();

    std::cout << ani->getType() << std::endl;
    ani->makeSound();   
    std::cout << ani2->getType() << std::endl;
    ani2->makeSound();
    
    delete ani;
    delete ani2;
}