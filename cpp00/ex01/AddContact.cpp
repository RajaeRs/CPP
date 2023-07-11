/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AddContact.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 00:33:04 by rrasezin          #+#    #+#             */
/*   Updated: 2023/07/11 15:35:37 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int PhoneBook::getCount()
{
	return(this->count);
}

void PhoneBook::setCount()
{
	if (getCount() < COUNT)
		this->count++;
}


Contact	add()
{
	Contact		contact;
	std::string firstName;
	std::string lastName;
	std::string nickName;
	std::string phoneNumber;
	std::string darkest_secret;

	std::cout << "\nEnter the Contact information:\n";

	std::cout << "First Name : ";
	std::getline(std::cin >> std::ws, firstName);

	std::cout << "Last Name : ";
	std::getline(std::cin >> std::ws, lastName);

	std::cout << "Nick Name : ";
	std::getline(std::cin >> std::ws, nickName);

	std::cout << "Phone Number : ";
	std::getline(std::cin >> std::ws, phoneNumber);
	
	std::cout << "Darkest secret : ";
	std::getline(std::cin >> std::ws, darkest_secret);

	contact.setFirstName(firstName);
	contact.setLastName(lastName);
	contact.setNickName(nickName);
	contact.setPhoneNumber(phoneNumber);
	contact.setDarkestSecret(darkest_secret);
	return (contact);
}

void	PhoneBook::setContact()
{
	int size;
	int	i;

	i = 0;
	size = PhoneBook::getCount();
	if (size == COUNT)
	{
		while (i < size - 1)
		{
			this->contact[i] = this->contact[i + 1];
			i++;
		}
		this->contact[i] = add();
	}
	else
		this->contact[size] = add();
	PhoneBook::setCount();
}
