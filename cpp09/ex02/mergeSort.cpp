/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mergeSort.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 11:01:31 by rrasezin          #+#    #+#             */
/*   Updated: 2023/10/29 19:42:11 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <sstream>

int g_size;
int cmp;

void	printData(std::vector<int>& data, int sPeer)
{
	std::vector<int>::iterator it = data.begin();
	int i = 0;
	while (it != data.end())
	{
		if (i % sPeer == 0)
			std::cout << "  ";
		std::cout << *it << " " ;
		it++;
		i++;
	}
	// std::cout << "\033[32m" << "=>" << data.size() << "\033[0m";
	std::cout << std::endl;
}



typedef std::vector<int>::iterator iterator;

void	mouveFromTo(std::vector<int>& data, iterator &to, int sPree)
{
	iterator from, end;
	int size, m, middel = 0;

	from = data.begin();
	size = data.size();
	m = sPree * 2;
	while (size >= m)
	{
		std::advance(from, sPree);
		end = from;
		std::advance(end, sPree);
		data.insert(to, from, end);
		data.erase(from, end);
		m += sPree * 2;
		middel++;
	}
	middel *= sPree;
	middel = data.size() - middel;
	to = data.begin();
	std::advance(to, middel);
	from = data.begin();
	end = from;
	std::advance(end, sPree);
	data.insert(to, from, end);
	data.erase(from, end);
	while (sPree)
	{
		to--;
		sPree--;
	}
	// std::advance(to, -sPree);
}

//src : i get data from the first of this par to his second
//dest : i insert data from the first of this par to his second

void	insertion(std::vector<int> &data, iterator &bmch, int sPeer)
{

	std::cout <<"bmch: "<< *bmch << "\nnPeer: " << sPeer << "\nbegin : "<< *(data.begin()) << std::endl;
	std::pair<iterator, iterator> src;
	std::pair<iterator, iterator> dest;
	int dist = std::distance(data.begin(), bmch);
	std::cout << std::endl;
	printData(data, sPeer);
	int i = 1;
	while (bmch != data.begin())
	{
		src.first = data.begin();
		src.second = src.first;
		std::advance(src.second, sPeer - 1);

		dest.first = bmch;
		dest.second = dest.first;
		std::advance(dest.second, sPeer - 1);
		while (*(src.second) > *(dest.second) && dest.second != (data.end()-1))
		{
			cmp++;
			std::advance(dest.first, sPeer);
			std::advance(dest.second, sPeer);
		}
		cmp++;
		if (dest.second == (data.end()-1))
		{
				std::cout << "------- => " << *(data.end() - 1) << std::endl;
			if (*src.second < *(data.end()-1))
			{
				// cmp++;
				src.second++;
				data.insert(dest.first, src.first, src.second);
				data.erase(src.first, src.second);
			}
			else
			{
				src.second++;
				data.insert((data.end()), src.first, src.second);
				data.erase(src.first, src.second);
			}
		}
		else
		{
			src.second++;
			data.insert(dest.first, src.first, src.second);
			data.erase(src.first, src.second);
		}
		std::cout << i << " insertion : ";
		printData(data, sPeer);
		dist -= sPeer;
		bmch = data.begin();
		std::advance(bmch, dist );
		i++;
	}
}

// bmch : begin of main chain
// sPree : size of peer
// eoMC : end of main chain
void	MainPaindChain(std::vector<int> &data, std::vector<int>::iterator bmch, int sPree)
{
	// if (sPree * 2 > g_size / 2)
	// 	return ;
	std::vector<int> tmp;
	std::vector<int>::iterator it = bmch;
	int size;
	int m;
	
	while (it != data.end())
	{
		tmp.push_back(*it);
		data.erase(it);
	}
	std::cout << "Tmp : ";
	printData(tmp, 1); 
	std::cout << "Data : ";
	printData(data, sPree);
	mouveFromTo(data, bmch, sPree);
	std::cout << "    => " ;
	printData(data, sPree);
	
	insertion(data, bmch, sPree);
	
	data.insert(data.end(),tmp.begin(), tmp.end());
}

// eoP : end of peers

void	MergeSort(std::vector<int>& data, float sPeer)
{
    // std::cout << "Peer " << sPeer << std::endl;
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
            // std::cout << "first => " << *first << "    second => " << *second << std::endl;
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
		// printData(data);
		MergeSort(data, (sPeer * 2));
	}
    int eoP = static_cast<int>(g_size/sPeer) * static_cast<int>(sPeer);
	// std::cout << "sPeer : " << sPeer << " || end of main : " << eoP << std::endl;
	if (eoP == sPeer)
		return ;
	std::vector<int>::iterator eoMC = data.begin();
	std::advance(eoMC, eoP);
	std::cout << "\033[33m" << "after merge => " ;
	printData(data, sPeer);
	std::cout << "\033[0m" << std::endl;
	MainPaindChain(data, eoMC, sPeer);
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
	
	g_size = data.size();
	std::cout << "\033[33m" << "Size => " << g_size << "\033[0m" << std::endl;
    MergeSort(data, 1);
	std::cout << std::endl << "\033[31m";
	std::cout << "\033[0m";
    printData(data, 1);
	std::cout << "comparision : " << cmp << std::endl;
	if (std::is_sorted(data.begin(), data.end()))
		std::cout << "\033[32m" << "data is Sorted " << "\033[0m" << std::endl;
	else
		std::cout << "\033[31m" << "Not Sorted " << "\033[0m" << std::endl;
		
}