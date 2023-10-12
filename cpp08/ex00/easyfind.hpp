/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 22:24:30 by rrasezin          #+#    #+#             */
/*   Updated: 2023/10/12 13:14:30 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class   notFind : public std::exception
{
    public :
        const char * what() const throw()
        {
            return ("this value not fond in this container");
        }
};

template<typename T>
int easyfind(T container, int toFind)
{
    typename T::iterator it = std::find(container.begin(), container.end(), toFind);
    
    if (it == container.end())
    {
        throw notFind();
    }
    return (1);
}

