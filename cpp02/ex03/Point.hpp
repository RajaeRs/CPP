/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 10:34:08 by rrasezin          #+#    #+#             */
/*   Updated: 2023/08/12 11:48:25 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "Fixed.hpp"

class   Point
{
    private :
        const Fixed x;
        const Fixed y;
    public :
        Point();
        Point(const float x, const float y);
        Point(const Point &copy);
        Point& operator=(const Point& assignment);
        Fixed getFixedPointX() const;
        Fixed getFixedPointY() const;
        ~Point();
};

bool bsp( Point const a, Point const b, Point const c, Point const point);