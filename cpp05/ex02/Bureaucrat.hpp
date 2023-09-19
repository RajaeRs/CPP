/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 17:13:17 by rrasezin          #+#    #+#             */
/*   Updated: 2023/09/19 23:02:58 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "AForm.hpp"

class	AForm;

class   Bureaucrat
{
    private :
        const std::string	name;
        int					grade;
	public :
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat& copy);
		Bureaucrat&	operator=(const Bureaucrat& assingement);
		std::string	getName(void) const;
		int			getGrade(void) const;
		void		incrementBureaucratGarde();
		void		decrementBureaucratGarde();
		void		signForm(std::string name, bool signe, std::string message) const;
		class		GradeTooHighException;
		class		GradeTooLowException;
		~Bureaucrat();
};

class	Bureaucrat::GradeTooHighException : public std::exception
{
	public :
		const char * what() const throw();
};

class	Bureaucrat::GradeTooLowException : public std::exception
{
	public :
		const char * what() const throw();
};

std::ostream& operator<<(std::ostream& stream, const Bureaucrat& brct);
