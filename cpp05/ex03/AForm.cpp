/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 19:24:34 by rrasezin          #+#    #+#             */
/*   Updated: 2023/09/20 17:41:50 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : name("AForm") , FormGrade(150) , bureaucratGrade(100)
{
	this->signe = false;
}

AForm::AForm(std::string name, int fGrade, int bGrade) : name(name) , FormGrade(fGrade) , bureaucratGrade (bGrade)
{
	if (fGrade > 150 || bGrade > 150)
		throw AForm::GradeTooLowException();
	if (fGrade < 1 || bGrade < 1)
		throw AForm::GradeTooHighException();
	this->signe = false;
}

AForm::AForm(const AForm& copy) : name(copy.getName()) , FormGrade(copy.getAFormGrade()) , bureaucratGrade(copy.getBureaucratGarde())
{
	this->signe = copy.getSigne();
}

AForm& AForm::operator=(const AForm& assignement)
{
	this->signe = assignement.getSigne();
	return (*this);
}

std::string AForm::getName(void) const
{
	return(this->name);
}

bool    AForm::getSigne(void) const
{
	return(this->signe);
}

int AForm::getAFormGrade(void) const
{
	return(this->FormGrade);
}

int AForm::getBureaucratGarde(void) const
{
	return(this->bureaucratGrade);
}

void	AForm::setSigne(bool signe)
{
	this->signe = signe;
}

void    AForm::beSigned(const Bureaucrat& brct)
{
	if (this->signe == true)
	{
		throw AForm::AlreadySigned();
	}
	if (brct.getGrade() > this->getBureaucratGarde())
	{
		throw AForm::GradeTooLowException();
	}
	this->signe = true;
}

const char *AForm::AlreadySigned::what() const throw()
{
	return "Exception : Already Signed.";
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return "Exception : Grade Too High Exception";
}

const char *AForm::GradeTooLowException::what() const throw()
{
		return "Exception : Grade Too Low Exception";
}

const char * AForm::NotSigned::what() const throw()
{
    return "The Form doesn't signed";
}

std::ostream& operator<<(std::ostream &stream, const AForm& f)
{
	std::string signe;

	if (f.getSigne())
		signe = "Yes";
	else
		signe = "No";
		
	stream	<< " ------------------------------------\n"
			<< "| Name : " << f.getName() << "\n"
			<< "| Grade required to sign it : " << f.getAFormGrade() << "\n"
			<< "| Grade required to execute it : " << f.getBureaucratGarde() << "\n"
			<< "| Signe : " << signe << "\n"
			<< " ------------------------------------" ;
	return stream;
}

AForm::~AForm(){};