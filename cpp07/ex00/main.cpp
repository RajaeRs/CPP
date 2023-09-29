/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 09:51:12 by rrasezin          #+#    #+#             */
/*   Updated: 2023/09/29 09:53:42 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "templateT.hpp"

int main()
{
    int m = 5;
    int n = 60;

    std::cout << "Min : " << min(m, n) << std::endl;
    std::cout << "Max : " << max(m, n) << std::endl;
    swap(&m, &n);
    std::cout << "value of m : " << m << std::endl;
    std::cout << "value of n : " << n << std::endl;

}