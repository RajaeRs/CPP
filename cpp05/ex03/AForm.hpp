/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 19:11:02 by rrasezin          #+#    #+#             */
/*   Updated: 2023/09/20 17:23:28 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "Bureaucrat.hpp"

class	Bureaucrat;

class	AForm
{
	private:
		const std::string	name;
		bool				signe;
		const int			FormGrade;
		const int			bureaucratGrade;
	public:
		AForm();
		AForm(std::string name, int FormGrade, int bureaucratGrade);
		AForm(const AForm& copy);
		AForm& operator=(const AForm& assignement);
		void			setSigne(bool signe);
		std::string		getName(void) const;
		bool			getSigne(void) const;
		int				getAFormGrade(void) const;
		int 			getBureaucratGarde(void) const;
		void			beSigned(const Bureaucrat& brct);
		class			AlreadySigned;
		class			NotSigned;
		class			GradeTooHighException;
		class			GradeTooLowException;
		virtual void	execute(Bureaucrat const & executor) const = 0;
		virtual	~AForm();
};

class	AForm::GradeTooHighException : public std::exception
{
	public :
		const char * what() const throw();
};

class	AForm::GradeTooLowException : public std::exception
{
	public :
		const char * what() const throw();
};

class	AForm::AlreadySigned : public std::exception
{
	public :
		const char * what() const throw();
};

class   AForm::NotSigned : public std::exception
{
    public :
        const char * what() const throw();
};

std::ostream& operator<<(std::ostream& stream , const AForm& f);