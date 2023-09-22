/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 10:32:59 by rrasezin          #+#    #+#             */
/*   Updated: 2023/09/22 11:05:14 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

int main()
{
    try
    {
        Intern someRandomIntern;
        AForm* rrf;
        rrf = someRandomIntern.makeForm("ShrubberyCreationForm", "Bender");
        std::cout << *rrf << std::endl;
        delete rrf; 
    }
    catch(std::exception &exp)
    {
        std::cout << exp.what() << std::endl;
    }
    return (0);
}
