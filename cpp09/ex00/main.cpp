/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 17:09:54 by rrasezin          #+#    #+#             */
/*   Updated: 2023/10/16 17:21:13 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
    try
    {
        if (ac != 2)
            throw FailedToOpenFile();
        std::string dataFile(av[1]);
        map data = get_data_from_input(dataFile, '|', ".txt", "date | value");
        std::string baseFile("./data.csv");
        map base = get_data_from_input(baseFile, ',', ".csv", "date,exchange_rate");
        btc(data, base);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    } 
}
