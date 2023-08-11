/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 20:06:42 by rrasezin          #+#    #+#             */
/*   Updated: 2023/08/07 20:08:05 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

void Fixed::setRawBits(int const raw)
{
	this->value = raw;
}

Fixed& Fixed::operator=(const Fixed& assinment)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &assinment)
		this->value = assinment.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

std::ostream& operator<<(std::ostream& stream, const Fixed& value)
{
    stream << value.getRawBits();
    return stream;
}

int Fixed::getRawBits()const
{
	std::cout << "getRawBits member function called" << std::endl;
	return(this->value);
}

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->value = 0;
}

Fixed::Fixed(const Fixed &copy)
{
	std::cout << "Copy constructor called" << std::endl;
    this->setRawBits(copy.getRawBits());
}
