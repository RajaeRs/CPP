/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 12:26:47 by rrasezin          #+#    #+#             */
/*   Updated: 2023/10/12 12:24:24 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <iterator>
#include <stack>

template<class T>
class   MutantStack : public std::stack<T>
{
    public :
        MutantStack<T>();
        MutantStack<T>(const MutantStack<T>& copy);
        MutantStack<T> &operator=(const MutantStack<T>& assignement);
        ~MutantStack<T>();
        typedef typename std::stack<T>::container_type::iterator iterator;
        typedef typename std::stack<T>::container_type::const_iterator const_iterator;
        typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
        typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;
        iterator       begin();
        const_iterator begin() const;
        reverse_iterator       rbegin();
        const_reverse_iterator rbegin() const;
        iterator       end();
        const_iterator end()   const;
        reverse_iterator       rend();
        const_reverse_iterator rend()   const;
};

template<typename T>
MutantStack<T>::MutantStack(){};

template<typename T>
MutantStack<T>::MutantStack(const MutantStack<T>& copy) : std::stack<T>(copy){}

template<typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack<T>& assignement)
{
    const_iterator it = assignement.begin();
    const_iterator itt = assignement.end();
    while (it != itt)
    {
        std::stack<T>::c.push_back(*it);
        it++;
    }
    return (*this);
}

template<typename T>
MutantStack<T>::~MutantStack(){};

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
    return (std::stack<T>::c.begin());
}

template<typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::begin() const
{
    return (std::stack<T>::c.begin());
}

template<typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rbegin()
{
    return (std::stack<T>::c.end());
}

template<typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::rbegin() const
{
    return (std::stack<T>::c.end());
}

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
    return (std::stack<T>::c.end());
}

template<typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::end() const
{
    return (std::stack<T>::c.end());
}

template<typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rend()
{
    return (std::stack<T>::c.begin());
}

template<typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::rend() const
{
    return (std::stack<T>::c.begin());
}
