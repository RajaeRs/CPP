/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 22:40:18 by rrasezin          #+#    #+#             */
/*   Updated: 2023/10/12 13:21:09 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <list>

int main()
{
    try
    {
        std::list<int> nbr;

        nbr.push_back(1);
        nbr.push_back(2);
        nbr.push_back(3);
        nbr.push_back(4);
        nbr.push_back(5);
        nbr.push_back(6);
        
        std::cout << easyfind(nbr, 5) << std::endl;
    }
    catch(std::exception &exp)
    {
        std::cout << exp.what() << std::endl;
    }
}