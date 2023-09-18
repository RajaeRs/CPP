/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 10:32:59 by rrasezin          #+#    #+#             */
/*   Updated: 2023/09/18 12:10:24 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try
    {
        Bureaucrat dark("Dark", 100);
        dark.incrementBureaucratGarde();
        // try
        // {
            Form miniForm("miniForm", 120, 100);
            miniForm.beSigned(dark);
            std::cout << dark << std::endl;
        // }
    }
    catch(const char * err)
    {
        std::cout << err << std::endl;
    }
}