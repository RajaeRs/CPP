/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 14:56:47 by rrasezin          #+#    #+#             */
/*   Updated: 2023/10/03 15:31:39 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <unistd.h>

int main()
{
    try 
    {
        TemplateClass<char> arr(5);
        TemplateClass<char> arr1(arr);
        TemplateClass<char> arr2;
        
        arr2 = arr1;
        int s = arr.size();
        int i = 0;
        while ( i <= s)
        {
            std::cout << "array 0 :" << arr[i] << std::endl;
            std::cout << "array 1 :" << arr1[i] << std::endl;
            std::cout << "array 2 :" << arr2[i] << std::endl;
            i++;
        }
    }
    catch (std::exception &exp)
    {
        std::cout << exp.what() << std::endl;
    }
    return 0;
}
