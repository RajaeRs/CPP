/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:46:37 by rrasezin          #+#    #+#             */
/*   Updated: 2023/11/09 21:13:44 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#define RED "\033[1;31m"
#define YELLOW_BLOD "\033[1;33m"
#define YELLOW "\033[0;33m"
#define RESET "\033[0m"
#define BLUE "\033[0;34m"
#define GRAY "\033[0;30m"
#define GRAY_LINE "\033[4;30m"
#define GREEN "\033[0;32m"

#include <vector>
#include <sstream>
#include <iostream>
#include <list>
#include <ctime>

extern int g_size;
extern int cmp_vector;
extern int cmp_list;

typedef std::vector<int>::iterator iterator;

void	MergeSort_vector(std::vector<int>& data, float sPeer);
void	MergeSort_list(std::list<int>& data, float sPeer);
int jacobsthal(int index);
bool	upperComp_vector(int f, int s);
bool	upperComp_list(int f, int s);

template<typename container>
container   get_data(int ac, char **av)
{
    container data;
    std::stringstream ss;
	int value;
	int i = 1;

    if(ac < 2)
        throw "write some data!";
    while (av[i] != NULL)
	{
		ss << av[i];
		while (ss >> value)
		{
			if (value < 0)
				throw "Negative number";
			data.push_back(value);
		}
		if (!ss.eof())
			throw "Not valid number";
		ss.clear();
		i++;
	}
    return data;
}

template<typename container>
void	printData(container& data, int sPeer, std::string name)
{
	typename container::iterator it = data.begin();
    int i = 0;
    std::cout << name << " : \n      ";
	while (it != data.end())
	{
		std::cout << *it << " " ;
		it++;
        i++;
        if (i % sPeer == 0)
            std::cout << "   ";
	}
	std::cout << std::endl;
	std::cout << std::endl;
}

template<typename container>
container build_jacob_insertion_sequence(int len)
{
    container jacob;
    int jacob_len = 3;
    while(jacobsthal(jacob_len) < len)
    {
        jacob.push_back(jacobsthal(jacob_len - 1));
        jacob_len++;
    }
	jacob.push_back(0);
    return jacob; 
}


template<typename container, typename iterator_>
int	get_dest(container data, int position, int sPeer, int val, bool(*upperComp)(int f, int s))
{
	container max;
	iterator_ tmp;
	iterator_ t;

	tmp = data.begin();
	std::advance(tmp, (sPeer - 1));
	t = data.end();
    t--;
	while (tmp != t)
	{
		max.push_back(*tmp);
		std::advance(tmp, sPeer);
	}
	max.push_back(*tmp);
	iterator_ last = max.begin();
	if (position != 0)
		std::advance(last, position);
	else
	{
		last = max.end();
	}
	iterator_ mt = upper_bound(max.begin(), last, val, upperComp);
	return (std::distance(max.begin() , mt));
}

template<typename container>
container get_position(int size)
{
	container position;
	int i = 1;
	while (i < size + 1)
	{
		position.push_back(i);
		i++;
	}
	position.push_back(0);
	return position;
}

template<typename container, typename iterator_>
void	acrPos(container &position, int index)
{
	iterator_ it = position.begin();
	int size = position.size();
	int i = 0;
	while (i < size)
	{
		if (*it >= index)
			*it += 1;
		i++;
		it++;
	}
}

template<typename container>
void	print_status(container &data, double t, int c, std::string message)
{
	if (std::is_sorted(data.begin(), data.end()))
		std::cout  << GREEN
					<< "Sorted : "
					<< GRAY
                    << "Time to process a range of "
                    << YELLOW
                    << g_size
                    << GRAY
                    << " elements with "
                    << GRAY_LINE
                    << "std::" << message
                    << GRAY
                    << " => "
                    << YELLOW_BLOD
                    << t 
                    <<  " us"
					<< GRAY
					<< " -> "
					<< YELLOW_BLOD
					<< c
					<< GRAY
					<< " comparaison\n"
                    << std::endl;
	else
		std::cout << "\033[31m" << "Not Sorted." << std::endl;
}