/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 10:33:28 by rrasezin          #+#    #+#             */
/*   Updated: 2023/08/12 15:47:31 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <cmath>

class Fixed
{
    private :
        int                 value;
        static const int    fractionalBit = 8;
    public :
        Fixed				();
        Fixed				(const Fixed &copy);
        Fixed				(const int value);
        Fixed				(const float value);
		const Fixed&		operator=(const Fixed& assinment);
		bool				operator>(const Fixed& nb) const;
		bool				operator<(const Fixed& compar) const;
		bool				operator>=(const Fixed& compar) const;
		bool				operator<=(const Fixed& compar) const;
		bool				operator==(const Fixed& compar) const;
		bool				operator!=(const Fixed& compar) const;
		Fixed				operator+(Fixed const &nb) const;
    	Fixed				operator-(const Fixed &nb) const;
    	Fixed				operator*(const Fixed &nb) const;
    	Fixed				operator/(const Fixed &nb) const;
		Fixed&				operator++(); //pre
		Fixed				operator++(int); //post
		Fixed&				operator--();
		Fixed				operator--(int);
        int					getRawBits(void)const ;
        void				setRawBits(int const raw);
        float				toFloat(void) const;
        int					toInt(void) const;
		const static Fixed&	max(const Fixed& first, const Fixed&second);
		const static Fixed&	min(const Fixed& first, const Fixed&second);
		static Fixed&		min(Fixed& first, Fixed& second);
		static Fixed&		max(Fixed& first, Fixed& second);
        ~Fixed	();
};

std::ostream&	operator<<(std::ostream& stream, const Fixed& value);
int 			myPow(int nb, int pow);