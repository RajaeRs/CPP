/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 09:51:12 by rrasezin          #+#    #+#             */
/*   Updated: 2023/09/29 12:07:54 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"


int main()
{
	int a = 2;
	int b = 3;
	swap(a, b);
	std::cout << "a = " << a << " b = " << b << std::endl;
	std::cout << "min(a, b) = " << min(a, b) << std::endl;
	std::cout << "max(a, b) = " << max(a, b) << std::endl;

	std::string c = "chaine1";
	std::string d = "chaine2";
	swap(c, d);
	std::cout << "c = " << c << " d = " << d << std::endl;
	std::cout << "min(c, d) = " << min(c, d) << std::endl;
	std::cout << "max(c, d) = " << max(c, d) << std::endl;
	return (0);
	
}