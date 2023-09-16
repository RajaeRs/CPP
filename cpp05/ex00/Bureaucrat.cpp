/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 17:25:24 by rrasezin          #+#    #+#             */
/*   Updated: 2023/09/15 20:11:34 by rrasezin         ###   ########.fr       */
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
        throw "Bureaucrat::GradeTooHighException.";
    if (grade > 150)
        throw "Bureaucrat::GradeTooLowException.";
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
        throw "\nBureaucrat::GradeTooHighException.\n";
    this->grade = this->getGrade() - 1;
}

void    Bureaucrat::decrementBureaucratGarde(void)
{
    if (this->getGrade() >= 150)
        throw "\nBureaucrat::GradeTooLowException.\n";
    this->grade = this->getGrade() + 1;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Destructor called" << std::endl;
}

std::ostream& operator<<(std::ostream& stream, const Bureaucrat& brct)
{
    stream << brct.getName() << ", bureaucrat grade " << brct.getGrade() << '.';
    return (stream);
}