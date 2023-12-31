/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geters.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 00:25:17 by rrasezin          #+#    #+#             */
/*   Updated: 2023/06/19 18:11:45 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

std::string Contact::getFirstName()
{
	return (first_name);
}

std::string Contact::getLastName()
{
	return (last_name);
}

std::string Contact::getNickName()
{
	return (nick_name);
}

std::string Contact::getPhoneNumber()
{
	return (phone_number);
}

std::string Contact::getDarkestSecret()
{
	return (darkest_secret);
}
