/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 13:10:16 by rrasezin          #+#    #+#             */
/*   Updated: 2023/09/21 15:26:44 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(){};

Intern::Intern(const Intern& copy)
{
	(void)copy;	
}

Intern& Intern::operator=(const Intern& assignement)
{
	(void)assignement;
    return (*this);
}

Intern::~Intern(){};

AForm*  Intern::createShrubberyCreationForm(std::string target)
{
    return (new ShrubberyCreationForm(target));
}

AForm*	Intern::createRobotomyRequestForm(std::string target)
{
    return (new RobotomyRequestForm(target));
}

AForm*	Intern::createPresidentialPardonForm(std::string target)
{
    return (new PresidentialPardonForm(target));
}

AForm*	Intern::makeForm(std::string name, std::string target)
{
    ptrToMemberFunc forms[4] = {&Intern::createShrubberyCreationForm, &Intern::createRobotomyRequestForm, &Intern::createPresidentialPardonForm};
    std::string formName[4] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};
    int i = 0;

    while (name != formName[i] && i < 3)
        i++;
    if (i >= 3)
        throw Intern::FormNotFound();
    std::cout << "Intern creates : " << formName[i] << std::endl;
    return ((this->*forms[i])(target));
}

const char * Intern::FormNotFound::what() const throw()
{
    return "Form not found !";
}