/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 16:49:37 by rrasezin          #+#    #+#             */
/*   Updated: 2023/07/10 21:04:36 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

std::string getText(std::string fileName)
{
    std::string line;
    std::string fullText;
    std::ifstream file(fileName);
    if (file.is_open() == 0)
        return ("");
    while(getline(file, line))
    {
        fullText.append(line);
        fullText.append("\n");
    }
    file.close();
    return (fullText);
}

int readAndWrite(std::string fullText, std::string name, std::string s1, std::string s2)
{
    std::string result;
    size_t      found;

    found = 1;
    std::ofstream fileResult(name.append(".replace"));
    if (!fileResult.is_open())
        return (1);
    while (found != std::string::npos)
    {
        found = fullText.find(s1);
        if (found != std::string::npos)
        {
            result = fullText.substr(0, found);
            result.append(s2);
            fullText = fullText.substr(found + s1.length());
            fileResult << result;
        }
    }
    fileResult << fullText;
    fileResult.close();
    return (0);
}

int main(int ac, char **av)
{
    std::string fullText;
    std::string result;
    size_t      found;

    if (ac != 4)
    {
        std::cout << "Enter :  a filename and two strings, s1 and s2" << std::endl;
        return (1);
    }
    std::string name = av[1];
    fullText = getText(name);
    if (fullText.empty())
    {
        std::cerr << "File not found" << std::endl;
        return (1);
    }
    if (readAndWrite(fullText, name, av[2], av[3]) != 0)
    {
        std::cerr << "Error in opening new file" << std::endl;
        return (1);
    }
    return (0);
}