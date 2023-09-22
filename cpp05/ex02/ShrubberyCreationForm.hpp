/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 22:46:34 by rrasezin          #+#    #+#             */
/*   Updated: 2023/09/22 10:28:12 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include <fstream>

class   ShrubberyCreationForm : public AForm
{
    public :
        ShrubberyCreationForm();
        ShrubberyCreationForm(std::string name);
        ShrubberyCreationForm(const ShrubberyCreationForm& copy);
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm& assignement);
        void    execute(Bureaucrat const & executor) const;
		class	TreeCreationFailed;
        virtual ~ShrubberyCreationForm();
};

class	ShrubberyCreationForm::TreeCreationFailed : public std::exception
{
	public :
		const char * what() const throw();
};