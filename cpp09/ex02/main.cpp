/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:59:26 by rrasezin          #+#    #+#             */
/*   Updated: 2023/10/27 12:02:40 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <sstream>

int	g_size;
int comp = 0;

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



typedef std::vector<int>::iterator iterator;

void	mouveFromTo(std::vector<int>& data, iterator &to, int sp)
{
	iterator from, end;
	int size, m, middel = 0;

	from = data.begin();
	size = data.size();
	m = sp * 2;
	while (size >= m)
	{
		std::advance(from, sp);
		end = from;
		std::advance(end, sp);
		data.insert(to, from, end);
		data.erase(from, end);
		m += sp * 2;
		middel++;
	}
	middel *= sp;
	middel = data.size() - middel;
	to = data.begin();
	std::advance(to, middel);
	from = data.begin();
	end = from;
	std::advance(end, sp);
	data.insert(to, from, end);
	data.erase(from, end);
	// while (sp)
	// {
	// 	to--;
	// 	sp--;
	// }
	std::advance(to, -sp);
}

//src : i get data from the first of this par to his second
//dest : i insert data from the first of this par to his second

void	insertion(std::vector<int> &data, iterator &bmch, int nPeer)
{

	std::cout <<"Insertin func : \nData : ";
	printData(data);
	std::cout <<"bmch: "<< *bmch << "\nnPeer: " << nPeer << "\nbegin : "<< *(data.begin()) << std::endl;
	std::pair<iterator, iterator> src;
	std::pair<iterator, iterator> dest;
	int dist = std::distance(data.begin(), bmch);
	std::cout << std::endl;
	printData(data);
	int i = 1;
	while (bmch != data.begin())
	{
		src.first = data.begin();
		src.second = src.first;
		std::advance(src.second, nPeer - 1);

		dest.first = bmch;
		dest.second = dest.first;
		std::advance(dest.second, nPeer - 1);
		while (*(src.second) > *(dest.second) && dest.second != (data.end()-1))
		{
			std::advance(dest.first, nPeer);
			std::advance(dest.second, nPeer);
		}
		if (dest.second == (data.end()-1))
		{
			if (*src.second < *(data.end()-1))
			{
				src.second++;
				data.insert(dest.first, src.first, src.second);
				data.erase(src.first, src.second);
			}
			else
			{
				src.second++;
				data.insert((data.end() - 1), src.first, src.second);
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
		printData(data);
		dist -= nPeer;
		bmch = data.begin();
		std::advance(bmch, dist );
		i++;
	}
}

// bmch : begin of main chain
// sp : size of peer

void	MainPaindChain(std::vector<int> &data, std::vector<int>::iterator bmch, int sp)
{
	if (sp * 2 > g_size / 2)
		return ;
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
	printData(tmp); 
	std::cout << "Data : ";
	printData(data);
	// mouveFromTo(data, bmch, sp);
	
	// insertion(data, bmch, sp);
	
	// data.insert(data.end(),tmp.begin(), tmp.end());
}

void	MergeSort(std::vector<int>& data, float idxA)
{
	std::vector<int>::iterator first = data.begin();
	std::advance(first, idxA - 1);
	std::vector<int>::iterator second = first;
	iterator from;
	iterator to;
	int i = 1;
	
	if (idxA < (g_size/2))
	{
		while (i * idxA * 2 <= g_size)
		{
			comp++;
			std::advance(first, idxA);
			std::cout << "first : " << *first << "\nsecond : " << *second << std::endl;
			if (*first < *second)
			{
				from = second;
				std::advance(from, -(idxA - 1));
				std::swap_ranges(from, first, first);
			}
			std::advance(first, idxA);
			second = first;
			i++;
		}
		std::cout << "idxA : " << idxA << " => "; 
		printData(data);
		MergeSort(data, idxA * 2);
	}
	int soM = static_cast<int>(g_size/idxA) * static_cast<int>(idxA);
	if (soM == idxA)
		return ;
	std::vector<int>::iterator it = data.begin();
	std::cout << "result of merge : ";
	std::advance(it, soM);
	std::cout << "Bmch : " << *it << "\nidxA : " << idxA << "\nsoM : "<< soM<< std::endl;;
	MainPaindChain(data, it, idxA);
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

	MergeSort(data, 1);
	// printData(data);
	// iterator bmch = data.begin();
	// std::advance(bmch, 8);
	// insertion(data, bmch, 4);

}