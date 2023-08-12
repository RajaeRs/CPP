/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 12:50:00 by rrasezin          #+#    #+#             */
/*   Updated: 2023/08/12 18:23:43 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int myPow(int nb, int pow)
{
    int result;

    result = nb;
    while (--pow)
        result = result * nb;
    return (result);
}

// operators overloading ------------------
Fixed& Fixed::operator=(const Fixed& assinment)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &assinment)
		this->value = assinment.getRawBits();
	return (*this);
}

std::ostream& operator<<(std::ostream& stream, const Fixed& value)
{
    stream << value.toFloat();
    return stream;
}

// constractors : ----------------------
Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->value = 0;
}

Fixed::Fixed(const Fixed &copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}
Fixed::Fixed (const int value)
{
	std::cout << "Int constructor called" << std::endl;
    this->value = value << Fixed::fractionalBit;
}

Fixed::Fixed (const float value)
{
	std::cout << "Float constructor called" << std::endl;
    this->value = roundf((value * myPow(2, Fixed::fractionalBit)));
}

// distractors : ----------------------
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

float Fixed::toFloat(void) const
{
    float   result;

    result = (float)(this->value) / myPow(2, Fixed::fractionalBit);
    return (result);
}

int	Fixed::toInt(void) const
{
	int	result;

	result = this->value >> Fixed::fractionalBit;
	return (result);
}

void Fixed::setRawBits(int const raw)
{
	this->value = raw;
}

int Fixed::getRawBits()const
{
	return(this->value);
}