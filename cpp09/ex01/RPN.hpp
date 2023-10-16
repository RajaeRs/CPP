/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 17:09:26 by rrasezin          #+#    #+#             */
/*   Updated: 2023/10/16 17:11:37 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <sstream>
#include <stack>

class BadInput : public std::exception
{
    public :
        const char *what() const throw()
        {
            return "Error";
        }
};

void    addition(std::stack<double>& base);
void    subtraction(std::stack<double>& base);
void    multiplication(std::stack<double>& base);
void    division(std::stack<double>& base);
void    calculate(std::stack<double> &base, std::string &data);