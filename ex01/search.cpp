/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 17:04:44 by rrasezin          #+#    #+#             */
/*   Updated: 2023/06/19 13:15:19 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

Contact PhoneBook::getContact(int i)
{
	return (this->contact[i]);
}

void	printPart(std::string str)
{
	int size;

	size = 0;
	if (str.length() > 10)
		std::cout << str.substr(0, 9) << ".|";
	else
	{
		size = 10 - str.length();
		std::cout << str;
		while (size--)
			std::cout << ' ';
		std::cout << '|';
	}
	return ;
}

void	desplayContact(Contact contact, int i)
{
	std::string	str;

	std::cout << "|" << i << "         |";
	printPart(contact.getFirstName());
	printPart(contact.getLastName());
	printPart(contact.getNickName());
	std::cout << std::endl;
}

void	desplayInfo(Contact contact)
{
	std::cout << "\nFirst Name    :" << contact.getFirstName() << std::endl;
	std::cout << "Last  Name    :" << contact.getLastName() << std::endl;
	std::cout << "Nickname      :" << contact.getNickName() << std::endl;
	std::cout << "Phone Number  :" << contact.getPhoneNumber() << std::endl;
	std::cout << "Darkest Secret:" << contact.getDarkestSecret() << std::endl;
	return ;
}

void PhoneBook::search()
{
	Contact contact;
	std::string strIndex;
	int			index;
	int		size;
	int		i;
	
	i = 0;
	size = getCount();
	if (size > 0)
	{
		std::cout << "\n ----------+----------+----------+----------\n";
		std::cout << "|   Index  |first name|last  name| nickname |\n";	
		std::cout << " ----------+----------+----------+----------\n";
	}
	else
	{
		std::cout << "\nPhone Book is empty" << std::endl;
		return ;
	}
	while (i < size)
	{
		contact = PhoneBook::getContact(i);
		desplayContact(contact, i);
		i++;
	}
	std::cout << "\n- Enter the Index : ";
	std::cin >> strIndex;
	if (strIndex.length() == 1 && isdigit(strIndex[0]))
	{
		index = atoi(strIndex.c_str());
		if (index > (size - 1))
			std::cout << "\nWrong index" << std::endl;	
		else
			desplayInfo(PhoneBook::getContact(index));
	}
	else
		std::cout << "\nWrong index" << std::endl;
	return ;
}