/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 10:32:59 by rrasezin          #+#    #+#             */
/*   Updated: 2023/09/22 11:01:07 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    
    try
    {
        Bureaucrat mark("Mark", 5);
        // shrubbery class execution :
        std::cout << "\n *** Shrubbery class execution ***" << std::endl;
        try
        {
            ShrubberyCreationForm miniForm("Shrubbery");
            mark.signForm(miniForm);
            mark.executeForm(miniForm);
            std::cout << miniForm << std::endl;
        }
        catch(std::exception &exp)
        {
            std::cout << exp.what() << std::endl;
        }
        // Robot class execution :
        std::cout << "\n *** Robot class execution ***" << std::endl;
        try
        {
            RobotomyRequestForm miniForm("Robot");
            mark.signForm(miniForm);
            mark.executeForm(miniForm);
            std::cout << miniForm << std::endl;
        }
        catch(std::exception &exp)
        {
            std::cout << exp.what() << std::endl;
        }
        // Presidential class execution :
        std::cout << "\n *** Presidential class execution ***" << std::endl;
        try
        {
            PresidentialPardonForm miniForm("Presidential");
            mark.signForm(miniForm);
            mark.executeForm(miniForm);
            std::cout << miniForm << std::endl;
        }
        catch(std::exception &exp)
        {
            std::cout << exp.what() << std::endl;
        }
    }
    catch(std::exception &exp)
    {
        std::cout << exp.what() << std::endl;
    }
    return (0);
}
