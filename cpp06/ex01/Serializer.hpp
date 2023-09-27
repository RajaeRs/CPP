/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 12:47:59 by rrasezin          #+#    #+#             */
/*   Updated: 2023/09/27 15:37:56 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <cstdint>

typedef	struct s_data
{
	std::string	name;
}				Data;

class	Serializer
{
	public :
		Serializer();
		Serializer(const Serializer& copy);
		Serializer& operator=(const Serializer& assignement);
		static	uintptr_t serialize(Data* ptr);
		static	Data* deserialize(uintptr_t raw);
		~Serializer();
};