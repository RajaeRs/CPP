/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 17:15:04 by rrasezin          #+#    #+#             */
/*   Updated: 2023/08/23 21:26:05 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain constructor called" << std::endl;
}

Brain::Brain(const Brain& copy)
{
	int i = 0;

	while (i < 100)
	{
		this->ideas[i] = copy.ideas[i];
		i++;
	}
}

Brain& Brain::operator=(const Brain& assignement)
{
	int i = 0;

	while (i < 100)
	{
		this->ideas[i] = assignement.ideas[i];
		i++;
	}
	return (*this);
}

Brain::~Brain()
{
	std::cout << "Brain Destructor is called" << std::endl;
}

void	Brain::setIdeas(std::string AAnimal, int nb)
{
	int	i = 0;
	while (i < 100)
	{
		ideas[i] = "Idea " + AAnimal + " : " + std::to_string(nb);
		i++;
		nb++;
	}
	return ;
}