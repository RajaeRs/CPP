/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 17:36:25 by rrasezin          #+#    #+#             */
/*   Updated: 2023/11/01 17:43:09 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mergeSort.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 11:01:31 by rrasezin          #+#    #+#             */
/*   Updated: 2023/11/01 17:32:25 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <deque>
#include <sstream>
#include <algorithm>
int g_size;
int cmp;
std::pair<int, int>*	get_position(std::deque<int> data, int sPeer);
void	printData(std::deque<int>& data, int sPeer)
{
	std::deque<int>::iterator it = data.begin();
	int i = 0;
	while (it != data.end())
	{
		if (i % sPeer == 0)
			std::cout << "  ";
		std::cout << *it << " " ;
		it++;
		i++;
	}
	std::cout << std::endl;
}

// template <class ForwardIterator, class T>
//   ForwardIterator upper_bound (ForwardIterator first, ForwardIterator last, const T& val)
// {
//   ForwardIterator it;
//   iterator_traits<ForwardIterator>::difference_type count, step;
//   count = std::distance(first,last);
//   while (count>0)
//   {
//     it = first; step=count/2; std::advance (it,step);
//     if (!(val<*it))                 // or: if (!comp(val,*it)), for version (2)
//       { first=++it; count-=step+1;  }
//     else count=step;
//   }
//   std::cout << "\nDistance :" << std::distance(first, last) << std::endl;
//   return first;
// }

typedef std::deque<int>::iterator iterator;

void	mouveFromTo(std::deque<int>& data, iterator &to, int sPree)
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
	std::advance(to, -sPree);
}

//src : i get data from the first of this par to his second
//dest : i insert data from the first of this par to his second


int	get_dest(std::deque<int> data, std::pair<int, int> position, int dist, int sPeer)
{
	std::deque<int> max;
	iterator tmp;
	
	tmp = data.begin();
	std::advance(tmp, dist + (sPeer - 1));
	while (tmp != data.end()-1)
	{
		max.push_back(*tmp);
		std::advance(tmp, sPeer);
	}
	max.push_back(*tmp);
	tmp = data.begin();
	std::advance(tmp, sPeer - 1);
	iterator last = max.begin();
	if (position.second != -1)
		std::advance(last, position.second);
	else
	{
		last = max.end();
	}
	iterator mt = upper_bound(max.begin(), last, *tmp);
	return (std::distance(max.begin() , mt));
}

void	printNewPosition(std::pair<int, int>* position, int pairSize)
{
	int i = 0;
	while (i < pairSize)
	{
		std::cout << i << " => " << position[i].second << "  ";
		i++;
	}
	std::cout << std::endl;
}


void	insertion_old(std::deque<int> &data, iterator &bmch, int sPeer)
{
	std::cout << std::endl <<"bmch: "<< *bmch << "\nnPeer: " << sPeer << "\nbegin : "<< *(data.begin()) << std::endl;
	std::pair<iterator, iterator> src;
	iterator dest;
	std::pair<int, int> *position = get_position(data, sPeer);
	int dist = std::distance(data.begin(), bmch);

	std::cout  << "\033[33m" << "bigenOfInsertion => " ;
	printData(data, sPeer);
	std::cout << "\033[0m";
	int l;
	int i = 0;
	int pairSize = (data.size() / sPeer) / 2 ;
	while (bmch != data.begin())
	{
		int k = 0;
		src.first = data.begin();
		src.second = src.first;
		std::advance(src.second, sPeer);
		
		l = get_dest(data, position[i], dist, sPeer);

		dest = bmch;
		std::advance(dest, l*sPeer);
		
		data.insert(dest, src.first, src.second);
		data.erase(src.first, src.second);
		
		while (k < pairSize - 1)
		{
			if (position[k].second >= l)
			{
				while (k < pairSize - 1)
				{
					position[k].second += 1;
					k++;
				}
				break;
			}
			k++;
		}
		printNewPosition(position, pairSize);
			
		std::cout << i << " insertion : ";
		printData(data, sPeer);
		dist -= sPeer;
		bmch = data.begin();
		std::advance(bmch, dist );
		if (i < pairSize-1)
			i++;
	}
}


// bmch : begin of main chain
// sPree : size of peer
// eoMC : end of main chain
void	MainPaindChain(std::deque<int> &data, std::deque<int>::iterator bmch, int sPree)
{
	std::deque<int> tmp;
	std::deque<int>::iterator it = bmch;
	int size;
	int m;
	
	while (it != data.end())
	{
		tmp.push_back(*it);
		data.erase(it);
	}

	mouveFromTo(data, bmch, sPree);
	
	insertion_old(data, bmch, sPree);
	
	data.insert(data.end(),tmp.begin(), tmp.end());
}

// eoP : end of peers

void	MergeSort(std::deque<int>& data, float sPeer)
{
    std::deque<int>::iterator tmp;
	if (sPeer <= (g_size/2))
	{
        std::deque<int>::iterator first = data.begin();
        std::advance(first, sPeer -1);
        std::deque<int>::iterator second = first;
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
	std::deque<int>::iterator eoMC = data.begin();
	std::advance(eoMC, eoP);

	MainPaindChain(data, eoMC, sPeer);
}



std::pair<int, int>*	get_position(std::deque<int> data, int sPeer)
{
	int size =  (data.size() / sPeer) / 2 ;
	std::pair<int, int>* position = new std::pair<int, int> [size];
	int p = 0;
	int m = 2;
	int i = 0;

	while (i < size)
	{
		position[i].first = p;
		position[i].second = m;
		p++;
		m++;
		i++;
		if (i == size)
			position[i-1].second = -1;
	}
	return (position);
}

int	main(int ac, char **av)
{
	std::deque<int> data;
	std::deque<int> data_copy;
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
			data_copy.push_back(value);
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

	std::sort(data_copy.begin(), data_copy.end());
	printData(data, 1);
	printData(data_copy, 1);
	if (std::is_sorted(data.begin(), data.end()))
		std::cout << "\033[32m" << "data is Sorted " << "\033[0m" << std::endl;
	else
		std::cout << "\033[31m" << "Not Sorted " << "\033[0m" << std::endl;
	
}