/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:59:26 by rrasezin          #+#    #+#             */
/*   Updated: 2023/10/19 12:52:41 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <sstream>

int	size;

void	printData(std::vector<int>& data)
{
	std::vector<int>::iterator it = data.begin();
	while (it != data.end())
	{
		std::cout << *it << " " ;
		it++;
	}
	std::cout << std::endl;
}

void	MergeSort(std::vector<int>& data, float idxA)
{
	std::vector<int>::iterator first = data.begin();
	std::vector<int>::iterator second = first;
	int i = 1;
	
	if (idxA < (size/2))
	{
		while (i * idxA * 2 <= size)
		{
			std::advance(first, idxA);
			if (*first < *second)
				std::swap_ranges(second, first, first);
			std::advance(first, idxA);
			second = first;
			i++;
		}
		printData(data);
		MergeSort(data, idxA * 2);
	}
}




int	main(int ac, char **av)
{
	std::vector<int> data;
	std::stringstream ss;
	int value;
	int i = 1;

	while (av[i] != NULL)
	{
		ss << av[i];
		while (ss >> value)
		{
			if (value < 0)
			{
				std::cout << "Negative number" << std::endl;
				break ;
			}
			data.push_back(value);
		}
		if (!ss.eof())
		{
			std::cout << "Failed" << std::endl;
			break;
		}
		ss.clear();
		i++;
	}
	
	size = data.size();
	MergeSort(data, 1);

}