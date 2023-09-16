/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 10:32:59 by rrasezin          #+#    #+#             */
/*   Updated: 2023/09/15 20:13:37 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat test;
        test.decrementBureaucratGarde();
        std::cout << test << std::endl;
    }
    catch(const char * err)
    {
        std::cout << err << std::endl;
    }
    try
    {
        Bureaucrat test2("Dark", 100);
        test2.incrementBureaucratGarde();
        std::cout << test2 << std::endl;
    }
    catch(const char * err)
    {
        std::cout << err << std::endl;
    }
}