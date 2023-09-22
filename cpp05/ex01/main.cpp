/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 10:32:59 by rrasezin          #+#    #+#             */
/*   Updated: 2023/09/22 10:51:43 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try
    {
        Bureaucrat mark("Mark", 5);
        mark.incrementBureaucratGarde();
        try
        {
            Form miniForm("miniForm", 120, 10);
            mark.signForm(miniForm);
            std::cout << miniForm << std::endl;
        }
        catch (const Form::AlreadySigned &exp)
        {
            std::cout << exp.what() << std::endl;
        }
    }
    catch(std::exception &exp)
    {
        std::cout << exp.what() << std::endl;
    }
    
    return (0);
}
