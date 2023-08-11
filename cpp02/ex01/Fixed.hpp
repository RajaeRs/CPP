/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 20:15:49 by rrasezin          #+#    #+#             */
/*   Updated: 2023/08/10 20:18:02 by rrasezin         ###   ########.fr       */
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
        Fixed ();
        Fixed (const Fixed &copy);
        Fixed (const int value);
        Fixed (const float value);
		Fixed& operator=(const Fixed& assinment);
        int getRawBits(void)const ;
        void setRawBits(int const raw);
        float   toFloat(void) const;
        int     toInt(void) const;
        ~Fixed();
};

std::ostream& operator<<(std::ostream& stream, const Fixed& value);
