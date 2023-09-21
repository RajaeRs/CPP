/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 16:15:12 by rrasezin          #+#    #+#             */
/*   Updated: 2023/09/20 17:58:37 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5){};

PresidentialPardonForm::PresidentialPardonForm(std::string name) : AForm(name, 25, 5){};

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& copy) : AForm(copy){};

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& assignement)
{
    this->setSigne(assignement.getSigne());
    return (*this);
}

void    PresidentialPardonForm::execute(const Bureaucrat& executor) const
{
    if (!this->getSigne())
        throw PresidentialPardonForm::NotSigned();
    if (this->getBureaucratGarde() < executor.getGrade())
        throw PresidentialPardonForm::GradeTooLowException();
    std::cout << this->getName() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm(){};