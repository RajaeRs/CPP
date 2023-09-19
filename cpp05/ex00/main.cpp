/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 10:32:59 by rrasezin          #+#    #+#             */
/*   Updated: 2023/09/19 22:33:03 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat mark("Mark", 10);
        mark.decrementBureaucratGarde();
        std::cout << mark << std::endl;
    }
    catch(std::exception &exp)
    {
        std::cout << exp.what() << std::endl;
    }
    try
    {
        Bureaucrat test2("Dark", 1100);
        test2.incrementBureaucratGarde();
        std::cout << test2 << std::endl;
    }
    catch(std::exception &exp)
    {
        std::cout << exp.what() << std::endl;
    }
}