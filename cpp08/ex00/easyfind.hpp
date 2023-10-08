/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 22:24:30 by rrasezin          #+#    #+#             */
/*   Updated: 2023/10/06 23:05:35 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class   notFind : public std::exception
{
    public :
        const char * what() const throw()
        {
            return ("this value not find in this container");
        }
};

template<typename T>
int easyfind(T container, int toFind)
{
    typename T::iterator it;

    it = container.begin();
    while (it != container.end())
    {
        if (*it == toFind)
            return (1);
        it++;
    }
    throw notFind();
}

