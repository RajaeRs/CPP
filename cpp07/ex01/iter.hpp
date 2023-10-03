/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 12:08:37 by rrasezin          #+#    #+#             */
/*   Updated: 2023/09/30 15:28:00 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

template<typename arg>
void    func(arg &t)
{
    t = t + 49;
    if (!std::isprint(t))
        t = 'A';
}

template<typename arg>
void    print(arg *t, int length)
{
    for (int i = 0; i < length - 1; i++)
    {
        std::cout << t[i] << " - " ;
    }
    std::cout << t[length - 1] << std::endl;
}

template<typename arg, typename iterat>
void    iter(iterat *array, int length, void(*func)(arg &t))
{
    int i = 0;
    while (i < length)
    {
        func(array[i]);
        i++;
    }
    return;
}