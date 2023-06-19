/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 16:44:40 by rrasezin          #+#    #+#             */
/*   Updated: 2023/06/19 13:27:47 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

int	main()
{
	PhoneBook phoneBook;
	std::string action;

	while (1)
	{
		std::cout << "\nEnter ADD, SEARCH or EXIT : ";
		std::cin >> action;
		if (strcmp(action.c_str(), "ADD") == 0)
			phoneBook.setContact();
		else if (strcmp(action.c_str(), "SEARCH") == 0)
			phoneBook.search();
		else if (strcmp(action.c_str(), "EXIT") == 0)
			return (0);
		else
			std::cout << "\n[!] Not valid Action" << std::endl;	
	}
	return (0);
}