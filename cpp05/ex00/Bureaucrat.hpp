/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 17:13:17 by rrasezin          #+#    #+#             */
/*   Updated: 2023/09/19 17:46:25 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

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
		void	incrementBureaucratGarde();
		void	decrementBureaucratGarde();
		class	GradeTooHighException;
		class	GradeTooLowException;
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