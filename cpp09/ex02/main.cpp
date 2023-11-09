/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 12:43:26 by rrasezin          #+#    #+#             */
/*   Updated: 2023/11/09 21:32:14 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"


int main(int ac, char **av)
{
    std::vector<int>	data;
	std::list<int>		dataList;
	clock_t				v_start;
	clock_t				v_stop;
	// clock_t				l_start;
	// clock_t				l_stop;

	try
	{
		data = get_data<std::vector<int> >(ac, av);
		// dataList = get_data<std::list<int> >(ac, av);
		g_size = data.size();
		printData<std::vector<int> >(data, 1, "Data Befor sort");
		
		v_start = clock();
		MergeSort_vector(data, 1);
		v_stop = clock();

		// l_start = clock();
		// MergeSort_list(dataList, 1);
		// l_stop = clock();
	
		double v = (static_cast<double>(v_stop - v_start) / CLOCKS_PER_SEC) * 1000000;
		// double l = (static_cast<double>(l_stop - l_start) / CLOCKS_PER_SEC) * 1000000;
		std::cout << BLUE ;
   		printData<std::vector<int> >(data, 1, "After sort");
		std::cout << RESET;
		print_status<std::vector<int> >(data, v, cmp_vector, "vector");
		// print_status<std::list<int> >(dataList, l, cmp_list, "list");

	}
	catch(const char *message)
	{
		std::cerr << message << '\n';
	}
}