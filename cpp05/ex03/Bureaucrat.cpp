/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 17:25:24 by rrasezin          #+#    #+#             */
/*   Updated: 2023/09/20 17:25:51 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("noName")
{
    this->grade = 150;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name)
{
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& copy)
{
    this->grade = copy.getGrade();
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& assingement)
{
    this->grade = assingement.getGrade();
    return (*this);
}

int Bureaucrat::getGrade(void) const
{
    int i;

    i = this->grade;
    return (i);
}

std::string Bureaucrat::getName(void) const
{
    std::string tmpName;

    tmpName = this->name;
    return (tmpName);
}

void    Bureaucrat::incrementBureaucratGarde(void)
{
    if (this->getGrade() == 1)
        throw Bureaucrat::GradeTooHighException();
    this->grade = this->getGrade() - 1;
}

void    Bureaucrat::decrementBureaucratGarde(void)
{
    if (this->getGrade() >= 150)
        throw Bureaucrat::GradeTooLowException();
    this->grade = this->getGrade() + 1;
}

void    Bureaucrat::signForm(AForm& form)
{
    try
    {
        form.beSigned(*this);
        std::cout << this->name << " signed " << form.getName() << "." << std::endl;
    }
    catch (std::exception &exp)
    {
        std::cout << exp.what() << std::endl;
        std::cout << this->name << " couldn’t sign " << form.getName() << " because " << exp.what() << "." << std::endl;
    }
}

void    Bureaucrat::executeForm(const AForm & form) const
{
    try
    {
        form.execute(*this);
        std::cout << this->name << " executed " << form.getName() << std::endl; 
    }
    catch (std::exception &exp)
    {
        std::cout << exp.what() << std::endl;
        std::cout << "execution Failed" << std::endl;
    }
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade Too High Exception.");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade Too Low Exception.");
}

Bureaucrat::~Bureaucrat(){};

std::ostream& operator<<(std::ostream& stream, const Bureaucrat& brct)
{
    stream << brct.getName() << ", bureaucrat grade " << brct.getGrade() << '.';
    return (stream);
}