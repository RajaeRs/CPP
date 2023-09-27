/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 13:58:58 by rrasezin          #+#    #+#             */
/*   Updated: 2023/09/27 15:48:08 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
    Data        *ptr;
	uintptr_t	i;

	i = 5;
	ptr = Serializer::deserialize(i);
    int p = Serializer::serialize(ptr);
	std::cout << "i : " << i << std::endl;
	std::cout << "p : " << p << std::endl;
	return (0);
}