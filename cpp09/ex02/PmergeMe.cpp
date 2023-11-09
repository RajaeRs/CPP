/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:46:40 by rrasezin          #+#    #+#             */
/*   Updated: 2023/11/09 21:11:26 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "PmergeMe.hpp"


int g_size;
int cmp_vector;
int cmp_list;

int jacobsthal(int index)
{
    if (index == 0)
        return 0;
    if (index == 1)
        return 1;
    return jacobsthal(index - 1) + 2 * jacobsthal(index - 2);
}

bool	upperComp_vector(int f, int s)
{
	cmp_vector++;
	return(f<s);
}

bool	upperComp_list(int f, int s)
{
	cmp_list++;
	return(f<s);
}
// ------------------------------------------ vector ------------------------------------------

std::vector<int> getPaind_vector(std::vector<int> &data, int sPeer)
{
    std::vector<int>::iterator start = data.begin();
    std::vector<int> paind;
    int i;

    while(start != data.end())
    {
        i = 0;
        while (i < sPeer)
        {
            paind.push_back(*start);
            data.erase(start);
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

std::vector<int> get_tmp_vector(std::vector<int> &data, std::vector<int>::iterator bmch)
{
	std::vector<int> tmp;

	while (bmch != data.end())
	{
		tmp.push_back(*bmch);
		data.erase(bmch);
	}
	return tmp;
}

void	InsertionSort_vector(std::vector<int> &data, std::vector<int>::iterator bmch, int sPeer)
{
	std::vector<int> tmp = get_tmp_vector(data, bmch);
	std::vector<int> jacob, position, paind;
	std::pair<iterator, iterator> src;
	iterator dest, jtt, endOfcomp;
	int lenght, stop, size, j, m;

    paind = getPaind_vector(data, sPeer);
    jacob = build_jacob_insertion_sequence<std::vector<int> >(paind.size() / sPeer);
	position.reserve(data.size() / sPeer + 1);
	position = get_position<std::vector<int> >(data.size() / sPeer);
	src.first = paind.begin();
	src.second = src.first;
	std::advance(src.second, sPeer);
	data.insert(data.begin(), src.first, src.second);
	jtt = jacob.begin();
	j = *jtt;
	size = paind.size()/sPeer -1;
	m = 0;
	if (j == 0)
	{
		j = 1;
		stop = -1;
	}
	else
		stop = 1;
	while (size)
	{
		endOfcomp = position.begin();
		if (j < static_cast<int>(position.size()-1))
			std::advance(endOfcomp, j);
		else
			*endOfcomp = 0;
		src.first = paind.begin();
		std::advance(src.first, j * sPeer);
		src.second = src.first;
		std::advance(src.second, sPeer);
		lenght = get_dest<std::vector<int> , iterator >(data, *endOfcomp, sPeer, *(src.second-1), upperComp_vector);
		dest = data.begin();
		std::advance(dest, lenght*sPeer);
		data.insert(dest, src.first, src.second);
		acrPos<std::vector<int> , iterator >(position, lenght);
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
	data.insert(data.end(),tmp.begin(), tmp.end());
}

void	MergeSort_vector(std::vector<int>& data, float sPeer)
{
	data.reserve(g_size + 5);
    std::vector<int>::iterator tmp;
	if (sPeer <= (g_size/2))
	{
        std::vector<int>::iterator first = data.begin();
        std::advance(first, sPeer -1);
        std::vector<int>::iterator second = first;
        int i = 1;
		while (i * sPeer * 2 <= g_size)
		{
			std::advance(first, sPeer);
			cmp_vector++;
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
		MergeSort_vector(data, (sPeer * 2));
	}
    int eoP = static_cast<int>(g_size/sPeer) * static_cast<int>(sPeer);
	if (eoP == sPeer)
		return ;
	std::vector<int>::iterator eoMC = data.begin();
	std::advance(eoMC, eoP);
    InsertionSort_vector(data, eoMC, sPeer);
}

// ------------------------------------------ List ------------------------------------------
std::list<int> getPaind_list(std::list<int> &data, int sPeer)
{
    std::list<int>::iterator start = data.begin();
    std::list<int> paind;
    int i;

    while(start != data.end())
    {
        i = 0;
        while (i < sPeer)
        {
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

std::list<int> get_tmp_list(std::list<int> &data, std::list<int>::iterator bmch)
{
	std::list<int> tmp;

	while (bmch != data.end())
	{
		tmp.push_back(*bmch);
		data.erase(bmch);
        bmch++;
	}
	return tmp;
}

void	InsertionSort_list(std::list<int> &data, std::list<int>::iterator bmch, int sPeer)
{
	std::list<int> tmp = get_tmp_list(data, bmch);
	std::list<int> jacob, position, paind;
	std::pair<std::list<int>::iterator, std::list<int>::iterator> src;
	std::list<int>::iterator dest, jtt, endOfcomp, val;
	int lenght, stop, size, j, m;

    paind = getPaind_list(data, sPeer);
    jacob = build_jacob_insertion_sequence<std::list<int> >(paind.size() / sPeer);
	position = get_position<std::list<int> >(data.size() / sPeer);
	src.first = paind.begin();
	src.second = src.first;
	std::advance(src.second, sPeer);
	data.insert(data.begin(), src.first, src.second);
	jtt = jacob.begin();
	j = *jtt;
	size = paind.size()/sPeer -1;
	m = 0;
	if (j == 0)
	{
		j = 1;
		stop = -1;
	}
	else
		stop = 1;
	while (size)
	{
		endOfcomp = position.begin();
		if (j < static_cast<int>(position.size()-1))
			std::advance(endOfcomp, j);
		else
			*endOfcomp = 0;
		src.first = paind.begin();
		std::advance(src.first, j * sPeer);
		src.second = src.first;
		std::advance(src.second, sPeer);
        val = src.second;
        val--;
		lenght = get_dest<std::list<int> , std::list<int>::iterator >(data, *endOfcomp, sPeer, *val, upperComp_list);
		dest = data.begin();
		std::advance(dest, lenght*sPeer);
		data.insert(dest, src.first, src.second);
		acrPos<std::list<int> , std::list<int>::iterator >(position, lenght);
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
	data.insert(data.end(),tmp.begin(), tmp.end());
}

void	MergeSort_list(std::list<int>& data, float sPeer)
{
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
			cmp_list++;
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
		MergeSort_list(data, (sPeer * 2));
	}
    int eoP = static_cast<int>(g_size/sPeer) * static_cast<int>(sPeer);
	if (eoP == sPeer)
		return ;
	std::list<int>::iterator eoMC = data.begin();
	std::advance(eoMC, eoP);
    InsertionSort_list(data, eoMC, sPeer);
}
