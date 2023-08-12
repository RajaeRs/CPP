/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 10:42:16 by rrasezin          #+#    #+#             */
/*   Updated: 2023/08/12 12:32:49 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main()
{
    Point a(1, 1);
    Point b(7, 2);
    Point c(2, 7);
    Point check(2, 8);
    Point check2(4, 3);

    if (bsp(a, b, c, check))
        std::cout << "Point P is inside trangle ABC ." << std::endl;
    else
        std::cout << "Point P is not inside trangle ABC ." << std::endl;
    return (0);
}