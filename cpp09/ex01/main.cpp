/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 12:37:20 by rrasezin          #+#    #+#             */
/*   Updated: 2023/10/16 17:10:30 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int ac, char **av)
{
    try
    {
        if (ac != 2)
            throw BadInput();
        std::istringstream ss(av[1]);
        std::stack<double> base;
        std::string data;

        while (!ss.eof())
        {
            std::getline(ss, data, ' ');
            if (!data.empty())
                calculate(base, data);
        }
        if (base.size() != 1)
        {
            throw BadInput();
        }
        std::cout << base.top() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}