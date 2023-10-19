/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:59:26 by rrasezin          #+#    #+#             */
/*   Updated: 2023/10/18 12:15:14 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <sstream>

typedef std::vector<std::vector<int> > double_vector;

void	print_double_vector(double_vector &data)
{
	double_vector::iterator it = data.begin();
	std::vector<int>::iterator itt;
	while (it != data.end())
	{
		itt = (*it).begin();
		while(itt != (*it).end())
		{
			std::cout << *itt << " ";
			itt++;
		}
		it++;
	}
	std::cout << std::endl;
}

void	MergeSort(double_vector& data, int pair)
{
	if (data.size() != 1)
	{
		
	}
}

int	main(int ac, char **av)
{
	double_vector data;
	std::vector<int> tmp;
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
			tmp.push_back(value);
			data.push_back(tmp);
			tmp.clear();
		}
		if (!ss.eof())
		{
			std::cout << "Failed" << std::endl;
			break;
		}
		ss.clear();
		i++;
	}
	print_double_vector(data);
}