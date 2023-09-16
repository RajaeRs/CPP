/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 13:27:57 by rrasezin          #+#    #+#             */
/*   Updated: 2023/09/14 18:05:57 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class   testException
{
    private :
        std::string name;
        int         size;
	public :
		testException(std::string name, int size)
		{
			this->name = name;
			this->size = size;
		}
		void createGropes(int nb)
		{
			std::string message = "it's impossible to create groups";
			if (this->size % nb != 0)
				throw message;
			std::cout << "Yeee we have " <<  this->size / nb << " groups." << std::endl;
		}
		~testException()
		{
			std::cout << "Destructor called" << std::endl;
		}
};

int	main()
{
	testException Groups("Snow", 10);
	try 
	{
		Groups.createGropes(20);
	}
	catch(const std::string exception)
	{
		std::cout << exception << std::endl;
	}
	std::cout << "i'm here" << std::endl;
	return (0);
}