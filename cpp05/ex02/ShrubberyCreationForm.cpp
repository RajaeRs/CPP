/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 22:52:49 by rrasezin          #+#    #+#             */
/*   Updated: 2023/09/21 15:27:48 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("shrubbery", 145, 137)
{
    this->setSigne(false);
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string name) : AForm(name, 145, 137)
{
    this->setSigne(false);
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy) : AForm(copy)
{
	this->setSigne(copy.getSigne());
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& assignement)
{
	this->setSigne(assignement.getSigne());
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm(){};

void    ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    std::ofstream   shrubbery;
    std::string     treeName;

    treeName = executor.getName() + "_" + "shrubbery";
    if (!this->getSigne())
        throw ShrubberyCreationForm::NotSigned();
    if (this->getBureaucratGarde() < executor.getGrade())
        throw ShrubberyCreationForm::GradeTooLowException();
    shrubbery.open(treeName);
    if (!shrubbery.is_open())
    {
        throw ShrubberyCreationForm::TreeCreationFailed();
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

const char * ShrubberyCreationForm::TreeCreationFailed::what() const throw()
{
    return "Tree Creation Failed (Can't creat a tree)";
}