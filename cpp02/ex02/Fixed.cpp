/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 13:05:19 by rrasezin          #+#    #+#             */
/*   Updated: 2023/08/12 15:48:54 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"


// constractors : ------------------------
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
    this->value = value << this->fractionalBit;
}

Fixed::Fixed (const float value)
{
	std::cout << "Float constructor called" << std::endl;
    this->value = roundf((value * myPow(2, this->fractionalBit)));
}

// distractors : ---------------------------
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

// set / get ---------------------------------
void Fixed::setRawBits(int const raw)
{
	this->value = raw;
}

int Fixed::getRawBits()const
{
	return(this->value);
}

// operators overloading --------------------
std::ostream& operator<<(std::ostream& stream, const Fixed& value)
{
    stream << value.toFloat();
    return stream;
}

Fixed& Fixed::operator=(const Fixed& assinment)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &assinment)
		this->value = assinment.getRawBits();
	return (*this);
}

Fixed Fixed::operator+(const Fixed &nb) const
{
	Fixed result;

	result.setRawBits(this->value + nb.getRawBits());
	return (result);
}

Fixed& Fixed::operator++()
{
	this->value = this->value + 1;
	return (*this);
}

Fixed& Fixed::operator--()
{
	this->value = this->value - 1;
	return (*this);
}


Fixed Fixed::operator++(int)
{
	Fixed tmp;
	tmp.setRawBits(this->value);
	value = value + 1;
	return (tmp);
}

Fixed Fixed::operator--(int)
{
	Fixed tmp;
	tmp.setRawBits(this->value);
	value = value - 1;
	return (tmp);
}

Fixed Fixed::operator-(const Fixed &nb) const
{
	Fixed result;

	result.setRawBits(this->value - nb.getRawBits());
	return (result);
}

Fixed Fixed::operator*(const Fixed &nb) const
{
	Fixed result;

	result.setRawBits((this->value * nb.getRawBits()) >> result.fractionalBit);
	return (result);
}

Fixed Fixed::operator/(const Fixed &nb) const
{
	Fixed result;

	result.setRawBits((this->value << result.fractionalBit) / nb.getRawBits());
	return (result);
}

bool Fixed::operator>(const Fixed& nb) const
{
	return this->getRawBits() > nb.getRawBits();
}

bool Fixed::operator<(const Fixed& nb) const
{
	return this->getRawBits() < nb.getRawBits();
}

bool Fixed::operator>=(const Fixed& nb) const
{
	return this->getRawBits() >= nb.getRawBits();
}

bool Fixed::operator<=(const Fixed& nb) const
{
	return this->getRawBits() <= nb.getRawBits();
}

bool Fixed::operator==(const Fixed& nb) const
{
	return this->getRawBits() == nb.getRawBits();
}

// Fixed to int / float ---------------------
float Fixed::toFloat(void) const
{
    float   result;

    result = (float)(this->value) / myPow(2, this->fractionalBit);
    return (result);
}

int	Fixed::toInt(void) const
{
	int	result;

	result = this->value >> this->fractionalBit;
	return (result);
}

// Member function overloading ---------------
const Fixed &Fixed::min(const Fixed& first, const Fixed& second)
{
	if (first > second)
		return (second);
	else
		return (first);
}

const Fixed &Fixed::max(const Fixed& first, const Fixed& second)
{
	if (first > second)
		return (first);
	else
		return (second);
}

Fixed &Fixed::min(Fixed& first, Fixed& second)
{
	if (first > second)
		return (second);
	else
		return (first);
}

Fixed &Fixed::max(Fixed& first, Fixed& second)
{
	if (first > second)
		return (first);
	else
		return (second);
}

int myPow(int nb, int pow)
{
    int result;

    result = nb;
    while (--pow)
        result = result * nb;
    return (result);
}
