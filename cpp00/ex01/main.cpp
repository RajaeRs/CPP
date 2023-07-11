/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 16:44:40 by rrasezin          #+#    #+#             */
/*   Updated: 2023/07/11 15:45:00 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main()
{
	PhoneBook	phoneBook;
	std::string	action;

	while (1)
	{
		std::cout << "\nEnter ADD, SEARCH or EXIT : ";
		std::cin >> action;
		if (action.compare("ADD") == 0)
			phoneBook.setContact();
		else if (action.compare("SEARCH") == 0)
			phoneBook.getContact();
		else if (action.compare( "EXIT") == 0)
			return (0);
		else
			std::cout << "\n[!] Not valid Action" << std::endl;	
		if (std::cin.eof())
			return (1);
	}
	return (0);
}