/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 00:18:08 by rrasezin          #+#    #+#             */
/*   Updated: 2023/06/20 10:47:06 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

#include <iostream>
# define COUNT 8
class Contact
{
	private:
		std::string first_name;
		std::string last_name;
		std::string nick_name;
		std::string	phone_number;
		std::string	darkest_secret;
	public :
		void 		setFirstName(std::string first_name);
		void 		setLastName(std::string last_name);
		void 		setNickName(std::string nick_name);
		void 		setPhoneNumber(std::string phone_number);
		void 		setDarkestSecret(std::string darkest_secret);
		std::string getFirstName();
		std::string getLastName();
		std::string getNickName();
		std::string getPhoneNumber();
		std::string getDarkestSecret();
};

class PhoneBook
{
	private:
		Contact contact[COUNT];
		int		count;
	public:
		PhoneBook	(){
			count = 0;
		}
		~PhoneBook	(){}
		void		setCount(void);
		void		setContact(void);
		int			getCount(void);
		void		getContact(void);
};

#endif