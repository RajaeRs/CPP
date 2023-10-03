/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 14:42:45 by rrasezin          #+#    #+#             */
/*   Updated: 2023/10/03 16:28:50 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main()
{
    int integer[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    iter<int>(integer, 10, func);

    char character[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    iter<char>(character, 10, func);

    std::cout << "Integer : ";
    print<int>(integer, 10);

    std::cout << "Character : ";
    print<char>(character, 10);
}