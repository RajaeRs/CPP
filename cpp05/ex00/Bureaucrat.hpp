/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 17:13:17 by rrasezin          #+#    #+#             */
/*   Updated: 2023/09/15 20:10:45 by rrasezin         ###   ########.fr       */
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
		~Bureaucrat();
};

std::ostream& operator<<(std::ostream& stream, const Bureaucrat& brct);