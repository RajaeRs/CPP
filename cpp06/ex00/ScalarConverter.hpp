/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 12:06:46 by rrasezin          #+#    #+#             */
/*   Updated: 2023/09/27 12:39:23 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <cctype>
#include <cmath>

class   ScalarConverter
{
    public:
        char	c;
	    int		i;
	    float	f;
	    double	d;
        ScalarConverter();
        ScalarConverter(const ScalarConverter& copy);
        ScalarConverter& operator=(const ScalarConverter& assignement);
        void    method(std::string input);
        void    setChar(char c);
        void	setInt(int i);
		void	setFloat(float f);
		void	setDouble(double d);
		void	fromDouble(std::string input) const;
		int whishDataTypeIs(std::string input);
        ~ScalarConverter();
};
