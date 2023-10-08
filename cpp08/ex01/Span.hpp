/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 11:20:33 by rrasezin          #+#    #+#             */
/*   Updated: 2023/10/08 13:39:11 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <vector>

class   Span
{
    private:
        unsigned int        N;
        std::vector<int>	data;
    public:
        Span();
        Span(unsigned int N);
        Span(const Span& copy);
        Span& operator=(const Span& assignement);
        int& operator[](unsigned int i);
		unsigned int getSize(void) const;
		const std::vector<int>& getData(void) const;
        void addNumber(int newElement);
        int shortestSpan(void);
        int longestSpan(void);
		class	NoSpaceLeft;
		class	NoSpanCanFind;
		class	OutOfRang;
        template <typename T>
        void addMultipleNumber(T begin, T end)
        {
            while (this->data.size() < this->N && begin != end)
            {
                addNumber(*begin);
                begin++;
            }
        }
        ~Span();
};

class	Span::NoSpaceLeft : public std::exception
{
	public :
		const char * what() const throw();
};

class	Span::NoSpanCanFind : public std::exception
{
	public :
		const char * what() const throw();
};

class	Span::OutOfRang : public std::exception
{
	public :
		const char * what() const throw();
};