/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 10:41:16 by rrasezin          #+#    #+#             */
/*   Updated: 2023/08/12 11:45:46 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point (): x(0.0f), y(0.0f){};

Point::Point (const float x, const float y): x(x), y(y){};

Point::~Point(){};

Point::Point(const Point &copy):x(copy.x),y(copy.y)
{
    *this = copy;
}

Point &Point::operator=(const Point& copy)
{
    if(this != &copy){}
    return (*this);
}


Fixed Point::getFixedPointX() const
{
    return x;
}

Fixed Point::getFixedPointY() const
{
    return y;
}