/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   templateT.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 09:10:53 by rrasezin          #+#    #+#             */
/*   Updated: 2023/09/29 09:55:29 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "templateT.hpp"

void    swap(T *first, T *second)
{
    T tmp;

    tmp = *first;
    *first = *second;
    *second = tmp;
    return ;
}

T   min(T first, T second)
{
    if (second <= first)
        return (second);
    else
        return (first);
}

T   max(T first, T second)
{
    if (second >= first)
        return (second);
    else
        return (first);
}