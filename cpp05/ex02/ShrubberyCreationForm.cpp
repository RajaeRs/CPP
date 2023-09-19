/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 22:52:49 by rrasezin          #+#    #+#             */
/*   Updated: 2023/09/20 00:42:42 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("shrubbery", 72, 137)
{
    this->setSigne(false);
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string name) : AForm(name, 72, 137)
{
    this->setSigne(false);
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy)
{
	this->setSigne(copy.getSigne());
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& assignement)
{
	this->setSigne(assignement.getSigne());
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "Shrubbery Destroctor called" << std::endl; 
}

void    ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    // if (!this->getSigne())
    // {
    //     std::cout << "\n most throw an exception \n" << std::endl;
    // }
    std::ofstream   shrubbery;
    std::string treeName;

    treeName = executor.getName() + "_" + "shrubbery";
    
    shrubbery.open(treeName);
    if (!shrubbery.is_open())
    {
        std::cerr << "Error opening file" << std::endl;
        //throw an exeption
    }
    shrubbery << "\n"
            << "        ; ; ;\n"
            << "      ;        ;  ;     ;;    ;\n"
            << "   ;                 ;         ;  ;\n"
            << "                   ;\n"
            << "                  ;                ;;\n"
            << "  ;          ;            ;              ;\n"
            << "  ;            ';,        ;               ;\n"
            << "  ;              'b      *\n"
            << "   ;              '$    ;;                ;;\n"
            << "  ;    ;           $:   ;:               ;\n"
            << ";;      ;  ;;      *;  @):        ;   ; ;\n"
            << "             ;     :@,@):   ,;**:'   ;\n"
            << " ;      ;,         :@@*: ;;**'      ;   ;\n"
            << "          ';o;    ;:(@';@*\"'  ;\n"
            << "  ;  ;       'bq,;;:,@@*'   ,*      ;  ;\n"
            << "             ,p$q8,:@)'  ;p*'      ;\n"
            << "      ;     '  ; '@@Pp@@*'    ;  ;\n"
            << "       ;  ; ;;    Y7'.'     ;  ;\n"
            << "                 :@):.\n"
            << "                .:@:'.\n"
            << "              .::(@:."
            << std::endl;
    shrubbery.close();
}