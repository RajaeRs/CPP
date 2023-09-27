/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 12:14:04 by rrasezin          #+#    #+#             */
/*   Updated: 2023/09/27 17:41:49 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

char    character;
int     integer;
float   floatValue;
double   doubleValue;

ScalarConverter::ScalarConverter(){};

ScalarConverter::ScalarConverter(const ScalarConverter& copy)
{
	(void)copy;
};

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& assignement)
{
	(void)assignement;
	return (*this);
}

int whishDataTypeIs(std::string input)
{			
	if (input.length() == 1 && std::isprint(input[0]) && !std::isdigit(input[0]))
	{
		character= input[0];
		return (0);
	}
	else
	{
		int i;
	
		if (input[0] == '-' || input[0] == '+')
			i = 1;
		else
			i = 0;
		while (input[i] && std::isdigit(input[i]))
			i++;
		if (input[i] == '\0')
		{
			try
			{
				integer = std::stoi(input);
				return (1);
			}
			catch (const std::out_of_range&)
			{
				return (-1);
			}
		}
		else if (i != 0 && input[i] == '.' && std::isdigit(input[i + 1]))
		{
			i++;
			while(input[i] && std::isdigit(input[i]))
				i++;
			if (input[i] == '\0')
			{
				try
				{
					doubleValue= std::stod(input);
					return (3);
				}
				catch (std::out_of_range&)
				{
					return (-1);
				}
			}
			else if (input[i] == 'f' && input[i + 1] == '\0')
			{
				try
				{
					floatValue = std::stof(input);
					return (2);
				}
				catch (std::out_of_range&)
				{
					return (-1);
				}
			}
			else
				return (-1);
		}
	}
	return (-1);
}

void	fromDouble(std::string input)
{
	if (std::isprint(doubleValue))
		std::cout << "char : " << "'" << static_cast<char>(doubleValue)<< "'" << std::endl;
	else
		std::cout << "char : " << "Non displayable" << std::endl;
	try
	{
		if (!character)
			std::stoi(input);
		std::cout << "int : " << static_cast<int>(doubleValue) << std::endl;
	}
	catch(std::out_of_range&)
	{
		std::cout << "int : " << "impossible" << std::endl;
	}
	try
	{
		if (!character)
			std::stof(input);
		double fractional_part = std::fmod(doubleValue, 1.0);
		std::cout << "float : " << static_cast<float>(doubleValue);
		if (fractional_part == 0.0)
			std::cout << ".0f" << std::endl;
		else
			std::cout << 'f' << std::endl;
	}
	catch(std::out_of_range&)
	{
		std::cout << "float : " << "impossible" << std::endl;
	}
	double fractional_part = std::fmod(doubleValue, 1.0);
	std::cout << "double : " << doubleValue;
	if (fractional_part == 0.0)
		std::cout << ".0" << std::endl;
	else
		std::cout << std::endl;
}

std::string isInfini(std::string input, int type)
{
	std::string infinit[6] = {"-inff", "+inff", "nanf", "-inf", "+inf", "nan"};
	int	i = 0;

	while (input != infinit[i] && i < 6)
		i++;
	if (i >= 6)
		return ("impossible");
	if (type == 2 && !(i >= 0 && i <= 2))
		return (infinit[i - 3]);
	else if (type == 3 && (i >= 0 && i <= 2))
		return (infinit[i + 3]);
	else
		return input;
}

void	ScalarConverter::method(std::string input)
{
	int dataType = whishDataTypeIs(input);

	if (dataType == -1)
	{
		std::cout << "char : " << "impossible" << std::endl;
		std::cout << "int : " << "impossible" << std::endl;
		std::cout << "float : " << isInfini(input, 2) << std::endl;
		std::cout << "double : " << isInfini(input, 3) << std::endl;
	}
	else
	{
		if (dataType == 0)
			doubleValue = static_cast<double>(character);
		else if (dataType == 1)
			doubleValue = static_cast<double>(integer);
		else if (dataType == 2)
			doubleValue = static_cast<double>(floatValue);
		fromDouble(input);
	}
}

ScalarConverter::~ScalarConverter(){};
