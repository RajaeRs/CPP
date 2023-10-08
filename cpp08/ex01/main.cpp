/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 12:28:38 by rrasezin          #+#    #+#             */
/*   Updated: 2023/10/08 13:46:56 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <random>
#include <list>
#include <deque>
#include <cstdlib>
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

void    copyTest(void)
{
    try
    {
        Span test(6);
        Span copy;
        int i = 1;
        while (i < 7)
        {
            test.addNumber(i*2);
            i++;
        }
        Span test2(test);
        test2[3] = 20;
        copy = test2;
        copy[0] = 100;
        i = 0;
        while (i < static_cast<int>(test.getData().size()))
        {
            std::cout << "index " << i << " : " << test[i] << "  |  " << test2[i] << "  |  " << copy[i] << std::endl;
            i++;
        }
    }
    catch(std::exception &exp)
    {
        std::cout << exp.what() << std::endl;
    }
}

int main()
{   
    std::deque<int> myData;
    Span    newSpan(200);
    generateRandomContainer(myData, 200);
    newSpan.addMultipleNumber(myData.begin()+10, myData.end()-10);

    int i = 0; 
    while(i < static_cast<int>(newSpan.getData().size()))
    {
        std::cout << newSpan[i] << " ";
        i++;
    }
    std::cout << std::endl;
    std::cout << "shortest Span : " << newSpan.shortestSpan() << std::endl;
    std::cout << "longest Span : " << newSpan.longestSpan() << std::endl;
    copyTest();
    return 0;
}