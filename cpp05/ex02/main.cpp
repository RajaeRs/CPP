/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 10:32:59 by rrasezin          #+#    #+#             */
/*   Updated: 2023/09/20 00:39:28 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
    try
    {
        Bureaucrat mark("Mark", 100);
        mark.incrementBureaucratGarde();
        try
        {
            ShrubberyCreationForm miniForm("miniForm");
            miniForm.beSigned(mark);
            miniForm.execute(mark);
            std::cout << miniForm << std::endl;
        }
        catch (const AForm::AlreadySigned &exp)
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
