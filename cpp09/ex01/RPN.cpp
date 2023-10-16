/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 17:09:31 by rrasezin          #+#    #+#             */
/*   Updated: 2023/10/16 17:10:40 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

void    addition(std::stack<double>& base)
{
    double first, second;
    
    first = base.top();
    base.pop();
    second  = base.top();
    base.pop();
    base.push(second + first);
}

void    subtraction(std::stack<double>& base)
{
    double first, second;
    
    first = base.top();
    base.pop();
    second  = base.top();
    base.pop();
    base.push(second - first);
}

void    multiplication(std::stack<double>& base)
{
    double first, second;
    
    first = base.top();
    base.pop();
    second  = base.top();
    base.pop();
    base.push(second * first);
}

void    division(std::stack<double>& base)
{
    double first, second;
    
    first = base.top();
    base.pop();
    second  = base.top();
    base.pop();
    base.push(second / first);
}

void    calculate(std::stack<double> &base, std::string &data)
{
    char c;

    if (data.length() > 1)
        throw BadInput();
    if (isnumber(data[0]))
    {
        int i = data[0] - '0';
        base.push(i);
    }
    else
    {
        c = data[0];
        if (!(c == '+' || c == '-' || c == '*' || c == '/'))
            throw BadInput();
        else if (base.size() < 2 )
            throw BadInput();
        if (c == '+')
            addition(base);
        else if (c == '-')
            subtraction(base);
        else if (c == '*')
            multiplication(base);
        else
            division (base);
    }
}