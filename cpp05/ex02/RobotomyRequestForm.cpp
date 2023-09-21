/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 13:41:39 by rrasezin          #+#    #+#             */
/*   Updated: 2023/09/20 16:30:30 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robot", 72, 45) {};

RobotomyRequestForm::RobotomyRequestForm(std::string name) : AForm(name, 72, 45) {};

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy) : AForm(copy) {};

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& assignement)
{
    this->setSigne(assignement.getSigne());
    return (*this);
}

void    RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
    if (!this->getSigne())
    {
        std::cerr << "the robotomy failed." << std::endl;
        throw RobotomyRequestForm::NotSigned();
    }
    if (this->getBureaucratGarde() < executor.getGrade())
    {
        std::cerr << "the robotomy failed." << std::endl;
        throw RobotomyRequestForm::GradeTooLowException();
    }
    std::cout << "    ;     /        ,--.  \n"   
            <<"   [\"]   [\"]  ,<  |__**|    \n"
            <<"  /[_]\\  [~]\\/    |//  |            /.>         /.>\n"
            <<"   ] [   o o      /o|__|   Trat... /    Tak... / "
            << std::endl;
    std::cout << executor.getName() << " has been robotomized successfully 50% of the time." << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm(){};