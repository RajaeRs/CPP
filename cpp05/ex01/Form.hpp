/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 19:11:02 by rrasezin          #+#    #+#             */
/*   Updated: 2023/09/18 11:49:47 by rrasezin         ###   ########.fr       */
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
		~Form();
};