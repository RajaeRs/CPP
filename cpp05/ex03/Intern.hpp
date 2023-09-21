/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 12:55:42 by rrasezin          #+#    #+#             */
/*   Updated: 2023/09/21 13:51:39 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

class   Intern
{
    private :
        AForm* createShrubberyCreationForm(std::string target);
        AForm* createRobotomyRequestForm(std::string target);
        AForm* createPresidentialPardonForm(std::string target);
    public :
        Intern();
        Intern(const Intern& copy);
        Intern& operator=(const Intern& assignement);
        AForm *makeForm(std::string name, std::string target);
        class   FormNotFound;
        ~Intern();
};

class   Intern::FormNotFound : public std::exception
{
    public :
        const char * what() const throw();
};

typedef AForm* (Intern::*ptrToMemberFunc)(std::string);