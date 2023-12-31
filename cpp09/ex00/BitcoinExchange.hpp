/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 16:59:56 by rrasezin          #+#    #+#             */
/*   Updated: 2023/10/16 17:21:52 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <string>

class   FailedToOpenFile : public std::exception
{
    public :
        const char * what() const throw()
        {
            return "Error: could not open file.";
        }
};

typedef std::multimap<std::string, double> map;

double	check_value(std::string value, std::string ext);
int		dayInFebruary(int year);
bool	check_date(std::string date);
map		get_data_from_input(std::string input_file, char delimiter, std::string ext, std::string header);
void	btc(map data, map base);