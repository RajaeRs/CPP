/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 23:01:23 by rrasezin          #+#    #+#             */
/*   Updated: 2023/06/15 23:33:26 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int ac, char **av)
{
	int i;
	int	j;
	char c;

	if (ac == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << '\n';
		return 0;
	}
	for (i = 1 ; i < ac ; i++)
	{
		std::string name(av[i]);
		for (j = 0; name[j]; j++)
		{
			c = std::toupper(name[j]);
			std::cout << c ;
		}
		std::cout << ' ' ;
	}
	std::cout << '\n';
	return (0);
}