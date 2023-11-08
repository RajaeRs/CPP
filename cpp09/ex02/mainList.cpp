/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainList.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 12:43:26 by rrasezin          #+#    #+#             */
/*   Updated: 2023/11/08 21:58:26 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list>
#include <sstream>
#include <iostream>

int g_size;
int cmp;

typedef std::list<int>::iterator iterator;

int jacobsthal(int index)
{
    if (index == 0)
        return 0;
    if (index == 1)
        return 1;
    return jacobsthal(index - 1) + 2 * jacobsthal(index - 2);
}


std::list<int> build_jacob_insertion_sequence(int len)
{
    std::list<int> jacob;
    int jacob_len = 3;
    while(jacobsthal(jacob_len) < len)
    {
        jacob.push_back(jacobsthal(jacob_len) - 1);
        jacob_len++;
    }
    return jacob;
    
}

void	printData(std::list<int>& data, int sPeer, std::string name)
{
	std::list<int>::iterator it = data.begin();
    int i = 0;
    std::cout << name << " : ";
	while (it != data.end())
	{
		std::cout << *it << " " ;
		it++;
        i++;
        if (i % sPeer == 0)
            std::cout << "   ";
	}
	std::cout << std::endl;
}

std::list<int> getPaind(std::list<int> &data, int sPeer)
{
    std::list<int>::iterator start = data.begin();
    std::list<int> paind;
    int i;

    while(start != data.end())
    {
        i = 0;
        while (i < sPeer)
        {
	        printData(data, 1, "data");
            paind.push_back(*start);
            data.erase(start);
            start++;
            i++;
        }
        i = 0;
        if (start != data.end())
        {
            while (i < sPeer)
            {
                start++;
                i++;
            }
        }
    }
    return paind;
}

bool	upperComp(int f, int s)
{
	cmp++;
	return(f<s);
}

int	get_dest(std::list<int> data, int position, int sPeer, int val)
{
	std::list<int> max;
	iterator tmp;
	
	tmp = data.begin();
	std::advance(tmp, (sPeer - 1));
    iterator t = data.end();
    t--;
	while (tmp != t)
	{
		max.push_back(*tmp);
		std::advance(tmp, sPeer);
	}
	max.push_back(*tmp);
	iterator last = max.begin();
	if (position != 0)
		std::advance(last, position);
	else
	{
		last = max.end();
	}
	iterator mt = upper_bound(max.begin(), last, val, upperComp);
	return (std::distance(max.begin() , mt));
}

std::list<int> get_position(int size)
{
	std::list<int> position;
	int i = 0;
	while (i < size)
	{
		position.push_back(i);
		i++;
	}
	position.push_back(0);
	return position;
}

void	acrPos(std::list<int> &position, int index)
{
	iterator it = position.begin();
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


void	MainChain(std::list<int> &data, std::list<int>::iterator bmch, int sPeer)
{
	
	std::list<int> tmp;
	std::list<int>::iterator it = bmch;
	std::list<int> jacob;
	std::list<int> position;
	std::pair<iterator, iterator> src;
	iterator dest;
	while (it != data.end())
	{
		tmp.push_back(*it);
		data.erase(it);
	}
    
    std::list<int> paind = getPaind(data, sPeer);
    jacob = build_jacob_insertion_sequence(paind.size() / sPeer);
	jacob.push_back(0);
	// position.reserve(data.size() / sPeer + 1);
	position = get_position(data.size() / sPeer);
	// printData(jacob, 1 ,"jacob");
	
	src.first = paind.begin();
	src.second = src.first;
	std::advance(src.second, sPeer);
	data.insert(data.begin(), src.first, src.second);
	acrPos(position, 0);
	iterator jtt = jacob.begin();
	int j = *jtt;
	int lenght;
	int size = paind.size()/sPeer -1;
	int m = 0;
	int stop;
	printData(paind, sPeer, "paind");
	printData(data, sPeer, "data");
	if (j == 0)
	{
		j = 1;
		stop = -1;
	}
	else
		stop = 1;
	// printData(data, sPeer, "data --");
	
	while (size)
	{
		iterator tfo;

		tfo = position.begin();
		if (j < position.size()-1)
			std::advance(tfo, j);
		else
			*tfo = 0;
		// std::cout << "J => " << j << "  position => " << *tfo << std::endl;
		src.first = paind.begin();
		std::advance(src.first, j * sPeer);
		src.second = src.first;
		std::advance(src.second, sPeer);
		// std::cout << "first : " << *src.first << "   j * sPeer : " << j*sPeer << std::endl;
        iterator tmp = src.second;
        tmp--;
		lenght = get_dest(data, *tfo, sPeer, *tmp);
		dest = data.begin();
		std::advance(dest, lenght*sPeer);
		data.insert(dest, src.first, src.second);
		acrPos(position, lenght);
		// printData(data, sPeer, "data --");
		if (stop == -1)
			j++;
		else if (j > m + 1)
			j--;
		else
		{
			m = (*jtt);
			jtt++;
			j = *jtt;
			if (j == 0)
			{
				stop = -1;
				j = m + 1;
			}
		}
		size--;
	}
	// printData(data, sPeer, "data");
	data.insert(data.end(),tmp.begin(), tmp.end());
}

void	MergeSort(std::list<int>& data, float sPeer) // good with list
{
	// data.reserve(g_size + 5);
    std::list<int>::iterator tmp;
	if (sPeer <= (g_size/2))
	{
        std::list<int>::iterator first = data.begin();
        std::advance(first, sPeer -1);
        std::list<int>::iterator second = first;
        int i = 1;
		while (i * sPeer * 2 <= g_size)
		{
			std::advance(first, sPeer);
			cmp++;
			if (*first < *second)
            {
                tmp = first;
                std::advance(tmp, -(sPeer - 1));
                std::advance(second, -(sPeer - 1));
				std::swap_ranges(second, tmp, tmp);
            }
			std::advance(first, sPeer);
			second = first;
			i++;
		}
		MergeSort(data, (sPeer * 2));
	}
    int eoP = static_cast<int>(g_size/sPeer) * static_cast<int>(sPeer);
	if (eoP == sPeer)
		return ;
	std::list<int>::iterator eoMC = data.begin();
	std::advance(eoMC, eoP);
    MainChain(data, eoMC, sPeer);
}

int main(int ac, char **av)
{
    std::list<int> data;
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
	
	g_size = data.size();
	printData(data, 1, "Befor sort");
    MergeSort(data, 1);

	if (std::is_sorted(data.begin(), data.end()))
		std::cout << "\033[32m" << "data is Sorted " << "\033[0m" << std::endl;
	else
		std::cout << "\033[31m" << "Not Sorted " << "\033[0m" << std::endl;
	printData(data, 1, "After sort");

	std::cout << "Comp : " << cmp << std::endl;
}