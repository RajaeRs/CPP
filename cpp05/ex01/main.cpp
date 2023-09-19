/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 10:32:59 by rrasezin          #+#    #+#             */
/*   Updated: 2023/09/19 22:29:58 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try
    {
        Bureaucrat mark("Mark", 100);
        mark.incrementBureaucratGarde();
        try
        {
            Form miniForm("miniForm", 120, 100);
            miniForm.beSigned(mark);
            std::cout << miniForm << std::endl;
        }
        catch (const Form::AlreadySigned &exp)
        {
            std::cout << exp.checkSigne() << std::endl;
        }
    }
    catch(std::exception &exp)
    {
        std::cout << exp.what() << std::endl;
    }
    
    return (0);
}
