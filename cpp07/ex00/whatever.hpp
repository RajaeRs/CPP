/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 09:05:47 by rrasezin          #+#    #+#             */
/*   Updated: 2023/09/29 12:07:47 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

template<typename T>
void    swap(T &first, T &second)
{
    T tmp;

    tmp = first;
    first = second;
    second = tmp;
    return ;
}

template<typename T>
T   min(T &first, T &second)
{
    if (second <= first)
        return (second);
    else
        return (first);
}

template<typename T>
T   max(T &first, T &second)
{
    if (second >= first)
        return (second);
    else
        return (first);
}