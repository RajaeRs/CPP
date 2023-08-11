/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 20:05:32 by rrasezin          #+#    #+#             */
/*   Updated: 2023/08/07 20:11:15 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Fixed
{
    private :
        int                 value;
        static const int    fractionalBit = 8;
    public :
        Fixed ();
        Fixed (const Fixed &copy);
		Fixed& operator=(const Fixed& assinment);
        int getRawBits(void)const ;
        void setRawBits(int const raw);
        ~Fixed();
};
