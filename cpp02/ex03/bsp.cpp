/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 11:48:33 by rrasezin          #+#    #+#             */
/*   Updated: 2023/08/12 12:32:08 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    float w1;
    float w2;

    w1 = (a.getFixedPointX() * (c.getFixedPointY() - a.getFixedPointY())
        + (point.getFixedPointY() - a.getFixedPointY()) * (c.getFixedPointX() - a.getFixedPointX())
        - (point.getFixedPointX() * (c.getFixedPointY() - a.getFixedPointY()))).toFloat()
        / ((b.getFixedPointY() - a.getFixedPointY()) * (c.getFixedPointX() - a.getFixedPointX())
            - (b.getFixedPointX() - a.getFixedPointX()) * (c.getFixedPointY() - a.getFixedPointY())).toFloat();
    
    Fixed w(w1);

    w2 = ((point.getFixedPointY() - a.getFixedPointY() - w * (b.getFixedPointY() - a.getFixedPointY()))
        / (c.getFixedPointY() - a.getFixedPointY())).toFloat();

    if (w1 > 0 && w2 > 0 && (w1 + w2) < 1)
        return (true);
    else
        return (false);
}