/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 16:05:42 by rrasezin          #+#    #+#             */
/*   Updated: 2023/09/27 16:46:14 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base*   generate(void)
{
	Base	*test;
    std::srand(std::time(0));

    int random_number = std::rand() % 3;

	switch (random_number)
	{
		case 0:
			test = new A();
			break;
		case 1:
			test = new B();
			break;
		case 2:
			test = new C();
	}
	return (test);
}

void	identiy(Base* p)
{
	A *typeA = dynamic_cast<A*>(p);
	B *typeB = dynamic_cast<B*>(p);
	C *typeC = dynamic_cast<C*>(p);

	if (typeA)
		std::cout << "The type of class is : A." << std::endl;
	else if (typeB)
		std::cout << "The type of class is : B." << std::endl;
	else if (typeC)
		std::cout << "The type of class is : C." << std::endl;
	else
		std::cout << "Doesn't math with any type" << std::endl;
}

void	identiy(Base& p)
{
	A& typeA = dynamic_cast<A&>(p);
	B& typeB = dynamic_cast<B&>(p);
	C& typeC = dynamic_cast<C&>(p);

	if (&typeA == &p)
		std::cout << "The type of class is : A." << std::endl;
	else if (&typeB == &p)
		std::cout << "The type of class is : B." << std::endl;
	else if (&typeC == &p)
		std::cout << "The type of class is : C." << std::endl;
	else
		std::cout << "Doesn't math with any type" << std::endl;
}