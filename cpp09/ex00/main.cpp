/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 17:09:54 by rrasezin          #+#    #+#             */
/*   Updated: 2023/10/14 14:05:33 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <string>
#include <vector>
#include <sstream>

// -1 : Error: not a positive number.
// -2 :  bad input => date input.
// -3 : Error: too large a number.

/////////////// ::::::: ------------------ ::::::: \\\\\\\\\\\\\\\/
                    // extantion check <!>

class   FailedToOpenFile : public std::exception
{
    public :
        const char * what() const throw()
        {
            return "Failed to open the file.";
        }
};

class   NotValidInput : public std::exception
{
    public :
        const char * what() const throw()
        {
            return "Not Valid Input";
        }
};

double check_value(std::string value, std::string ext)
{
    std::string::const_iterator it = value.begin();
    double tmp;
    int i = 0;

    while (it != value.end() && std::isspace(*it))
        it++;
    if (it != value.end() && *it == '-')
        it++;
    while (it != value.end() && (isdigit(*it) || (*it == '.' && i == 0 && it != value.begin())) )
    {
        if (*it == '.')
            i = 1;
        it++;
    }
    if (it != value.end())
    {
        return (-2);
    }
    try
    {
        tmp = std::stof(value);
    }
    catch(...)
    {
        tmp = -3;
    }
    if (tmp < 0)
        tmp = -1;
    else if (tmp > 1000 && ext == ".txt")
        tmp = -3;
    return (tmp);
}

int dayInFebruary(int year)
{
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        return 29;
    else
        return 28;
}

bool    check_date(std::string date)
{
    int month , year, day;
    char c;

    if (date.length() == 10)
    {
        std::istringstream is(date);
        is >> year >> c >> month >> c >> day;
        if (c != 45 || (month <= 0 || day <= 0 || year < 2009 || year >= 2024))
            return false;
        if (month < 1 || month > 12)
            return false;
        if (month == 2 && day > dayInFebruary(year))
            return false;
        else if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
            return false;
        else if (day > 31)
            return false;
    }
    else
        return false;
    return true;
}

std::multimap<std::string, double> get_data_from_input(std::string input_file, char delimiter, std::string ext, std::string header)
{
    std::ifstream inputFile(input_file);
    std::multimap<std::string, double> data;
    std::string line;
    std::string date;
    std::string value;
    double tmp;
    if (!inputFile.is_open())
        throw FailedToOpenFile();
    std::getline(inputFile, line);
    if (!(line == header) || (input_file.substr(input_file.length() - 4) != ext))
    {
        inputFile.close();
        throw NotValidInput();
    }
    while (std::getline(inputFile, line))
    {
        std::istringstream iss(line);
        std::getline(iss, date, delimiter);
        if (!std::getline(iss, value, delimiter))
            tmp = -2;
        else
            tmp = check_value(value, ext);
        if (std::getline(iss, value, delimiter))
            tmp = -2;            
        if (!date.empty() && std::isspace(date.back()))
            date.pop_back();
        if (!check_date(date))
            tmp = -2;
        data.insert(std::pair<std::string, double> (date, tmp));
    }
    inputFile.close();
    return (data);
}

void    btc(std::multimap<std::string, double> data, std::multimap<std::string, double> base)
{
    std::multimap<std::string, double>::iterator it = data.begin();
    double tmp;

    while (it != data.end())
    {
        if (it->second == -1)
            std::cout << "Error: not a positive number." << std::endl;
        else if (it->second == -2)
            std::cout << "bad input => " << it->first << std::endl;
        else if (it->second == -3)
            std::cout << "Error: too large a number." << std::endl;
        else
        {
            for(std::multimap<std::string, double>::iterator at = base.begin(); at != base.end(); at++)
            {
                if (it->first < at->first)
                {
                    if (at == base.begin())
                        std::cout << it->first << " => " << it->second << " = " << it->second * at->second << std::endl;
                    else
                       std::cout << it->first << " => " << it->second << " = " << it->second * tmp << std::endl;
                    break;
                }
                tmp = at->second;
                at++;
            }
        }
        it++;
    }
    return ;
}

int main(int ac, char **av)
{
    if (ac != 2)
        return (1);
    try
    {
        std::string dataFile(av[1]);
        std::multimap<std::string, double> data = get_data_from_input(dataFile, '|', ".txt", "date | value");
        std::string baseFile("./data.csv");
        std::multimap<std::string, double> base = get_data_from_input(baseFile, ',', ".csv", "date,exchange_rate");
        btc(data, base);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    } 
}