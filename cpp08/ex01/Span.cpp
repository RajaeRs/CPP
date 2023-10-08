/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 11:35:38 by rrasezin          #+#    #+#             */
/*   Updated: 2023/10/08 13:26:56 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <cstdlib> 
#include <iterator>
#include <algorithm>

Span::Span()
{
    this->N = 10;
}

Span::Span(unsigned int N)
{
	this->N = N;
}

Span::Span(const Span& copy)
{
	this->N = copy.N;

	for(std::vector<int>::const_iterator it = (copy.data).begin() ; it != (copy.data).end() ; it++)
		this->data.push_back(*it);
}

Span& Span::operator=(const Span& assignement)
{
	this->N = assignement.N;
	this->data.clear();
	for (std::vector<int>::const_iterator it = (assignement.data).begin() ; it != assignement.data.end() ; it++)
		this->data.push_back(*it);
	return (*this);
}

int&	Span::operator[](unsigned int i)
{
	if (i >= this->data.size())
		throw Span::OutOfRang();
	return this->data[i];
}

unsigned int Span::getSize(void) const
{
	return (this->N);
}

const std::vector<int>&	Span::getData(void) const
{
	return (this->data);
}

void	Span::addNumber(int newElement)
{
	if (this->data.size() < this->N)
		this->data.push_back(newElement);
	else
		throw Span::NoSpaceLeft();
	return ;
}

int	Span::shortestSpan(void) 
{
	unsigned int	tmp;

	if (this->data.size() <= 1)
		throw Span::NoSpanCanFind();

	std::vector<int>::iterator beginIterator = this->data.begin();
	std::vector<int>::iterator endIterator = this->data.end();
	std::vector<int>::iterator inMiddel;
	unsigned int dis = std::abs(*beginIterator - *(beginIterator + 1));
	while (beginIterator != endIterator)
	{
		inMiddel = beginIterator + 1;
		while (inMiddel != endIterator)
		{
			tmp = std::abs(*beginIterator - *inMiddel);
			if (dis > tmp)
				dis = tmp;
			inMiddel++;
		}
		beginIterator++;
	}
	return dis;
}

int	Span::longestSpan(void) 
{
	unsigned int	tmp;

	if (this->data.size() <= 1)
		throw Span::NoSpanCanFind();

	std::vector<int>::iterator beginIterator = this->data.begin();
	std::vector<int>::iterator endIterator = this->data.end();
	std::vector<int>::iterator inMiddel;
	unsigned int dis = std::abs(*beginIterator - *(beginIterator + 1));
	while (beginIterator != endIterator)
	{
		inMiddel = beginIterator + 1;
		while (inMiddel != endIterator)
		{
			tmp = std::abs(*beginIterator - *inMiddel);
			if (dis < tmp)
				dis = tmp;
			inMiddel++;
		}
		beginIterator++;
	}
	return dis;
}


const char * Span::NoSpaceLeft::what() const throw()
{
	return ("No Space Left: the vector is full");
}

const char * Span::NoSpanCanFind::what() const throw()
{
	return ("No Span Can Find");
}

const char * Span::OutOfRang::what() const throw()
{
	return ("the index is out of Rang");
}


Span::~Span(){};