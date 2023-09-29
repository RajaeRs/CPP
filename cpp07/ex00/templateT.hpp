/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   templateT.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 09:05:47 by rrasezin          #+#    #+#             */
/*   Updated: 2023/09/29 09:59:39 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

template<typename T>

void    swap(T *first, T *second);
T    max(T first, T second);
T    min(T first, T second);