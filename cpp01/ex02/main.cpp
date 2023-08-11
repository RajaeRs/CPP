/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 17:06:49 by rrasezin          #+#    #+#             */
/*   Updated: 2023/07/12 19:53:56 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
    std::string name = "HI THIS IS BRAIN";
    std::string* stringPTR = &name;
    std::string& stringREF = name;

    std::cout << "Memory address :\n";
    std::cout << "The memory address of the string variable : " << &name << "\n";
    std::cout << "The memory address held by stringPTR : " << stringPTR << "\n";
    std::cout << "The memory address held by stringREF : " << &stringREF << "\n";

    std::cout << "\nValue :\n";
    std::cout << "the value of the string variable : " << name << "\n";
    std::cout << "The value pointed to by stringPTR : " << *stringPTR << "\n";
    std::cout << "The value pointed to by stringREF : " << stringREF << std::endl;

    return (0);
}