/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 12:28:38 by rrasezin          #+#    #+#             */
/*   Updated: 2023/10/12 13:22:30 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <random>
#include <list>
#include <ctime>


template<typename T>
void    generateRandomContainer(T& container, unsigned int size)
{
    std::srand(static_cast<unsigned int>(std::time(0)));
    unsigned int i = 0;

    while (i < size)
    {
        container.push_back(std::rand() % (1000000) + 1);
        i++;
    }
}

int main()
{   
    try
    {
        std::list<int> myData;
        Span    newSpan(200);
        generateRandomContainer(myData, 2000);
        newSpan.addMultipleNumber(myData.begin(), myData.end());

        int i = 0; 
        while(i < static_cast<int>(newSpan.getData().size()))
        {
            std::cout << newSpan[i] << " ";
            i++;
        }
        std::cout << std::endl;
        std::cout << "shortest Span : " << newSpan.shortestSpan() << std::endl;
        std::cout << "longest Span : " << newSpan.longestSpan() << std::endl;
    }
    catch (std::exception &exp)
    {
        std::cout << "\n" << exp.what() << std::endl;
    }
    return 0;
}