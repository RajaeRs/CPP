/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 13:10:53 by rrasezin          #+#    #+#             */
/*   Updated: 2023/07/11 13:11:22 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void    Harl::debug(void)
{
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!\n" << std::endl;
}

void    Harl::info(void)
{
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n" << std::endl;
}

void    Harl::warning(void)
{
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month.\n" << std::endl;
}

void    Harl::error(void)
{
    std::cout << "This is unacceptable! I want to speak to the manager now.\n" << std::endl;
}

void    Harl::complain(std::string level)
{
    std::string     message[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    int             i;

    i = 0;
    while (i < 4)
    {
        if (level == message[i])
            break;
        i++;
    }
    switch (i)
    {
        case 0:
            std::cout << "[ DEBUG ]\n";
            debug();
        case 1:
            std::cout << "[ INFO ]\n";
            info();
        case 2:
            std::cout << "[ WARNING ]\n";
            warning();
        case 3:
            std::cout << "[ ERROR ]\n";
            error();
            break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    }       
}
