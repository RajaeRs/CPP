/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 19:11:02 by rrasezin          #+#    #+#             */
/*   Updated: 2023/09/20 17:46:18 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "Bureaucrat.hpp"

class	Bureaucrat;

class	Form
{
	private:
		const std::string	name;
		bool				signe;
		const int			formGrade;
		const int			bureaucratGrade;
	public:
		Form();
		Form(std::string name, int formGrade, int bureaucratGrade);
		Form(const Form& copy);
		Form& operator=(const Form& assignement);
		std::string	getName(void) const;
		bool		getSigne(void) const;
		int			getFormGrade(void) const;
		int 		getBureaucratGarde(void) const;
		void		beSigned(const Bureaucrat& brct);
		class		AlreadySigned;
		class		GradeTooHighException;
		class		GradeTooLowException;
		~Form();
};

class	Form::GradeTooHighException : public std::exception
{
	public :
		const char * what() const throw();
};

class	Form::GradeTooLowException : public std::exception
{
	public :
		const char * what() const throw();
};

class	Form::AlreadySigned : public std::exception
{
	public :
		const char * what() const throw();
};

std::ostream& operator<<(std::ostream& stream , const Form& f);