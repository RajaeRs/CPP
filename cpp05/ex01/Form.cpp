/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 19:24:34 by rrasezin          #+#    #+#             */
/*   Updated: 2023/09/18 12:16:37 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : name("Form") , formGrade(150) , bureaucratGrade(100)
{
    this->signe = false;
}

Form::Form(std::string name, int fGrade, int bGrade) : name(name) , formGrade(fGrade) , bureaucratGrade (bGrade)
{
    if (fGrade > 150 || bGrade > 150)
        throw "Form::GradeTooLowException.";
    if (fGrade < 1 || bGrade < 1)
        throw "Form::GradeTooHighException";
    this->signe = false;
}

Form::Form(const Form& copy) : name(copy.getName()) , formGrade(copy.getFormGrade()) , bureaucratGrade(copy.getBureaucratGarde())
{
    this->signe = copy.getSigne();
}

Form& Form::operator=(const Form& assignement)
{
    this->signe = assignement.getSigne();
    return (*this);
}

std::string Form::getName(void) const
{
    return(this->name);
}

bool    Form::getSigne(void) const
{
    return(this->signe);
}

int Form::getFormGrade(void) const
{
    return(this->formGrade);
}

int Form::getBureaucratGarde(void) const
{
    return(this->bureaucratGrade);
}

void    Form::beSigned(const Bureaucrat& brct)
{
    if (this->signe == true)
    {
        brct.signForm(this->name, false, "this form is signed");
        throw "Form::AlreadySigned.";
    }
    if (brct.getGrade() > this->getBureaucratGarde())
    {
        brct.signForm(this->name, false, "Bureaucrat grad too low");
        throw "Form::GradeTooLowException.";
    }
    this->signe = true;
    brct.signForm(this->name, true, NULL);
}

Form::~Form()
{
    std::cout << "Desatructor called" << std::endl;
}
 