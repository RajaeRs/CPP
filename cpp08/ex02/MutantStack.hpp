/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 12:26:47 by rrasezin          #+#    #+#             */
/*   Updated: 2023/10/11 17:02:31 by rrasezin         ###   ########.fr       */
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
        MutantStack();
        MutantStack(const MutantStack& copy);
        MuMutantStack &operator=(const MutantStack& assignement);
        typedef std::deque<T>::iterator iterator;
        typedef std::deque<T>::const_iterator const_iterator;
        typedef std::deque<T>::reverse_iterator reverse_iterator;
        typedef std::deque<T>::const_reverse_iterator const_reverse_iterator;
        iterator       begin();
        const_iterator begin() const;
        iterator       end();
        const_iterator end()   const;
        reverse_iterator       rbegin();
        const_reverse_iterator rbegin() const;
        reverse_iterator       rend();
        const_reverse_iterator rend()   const;
        ~MutantStack();
};

template<typename T>
MutantStack::MutantStack(){};

template<typename T>
MutantStack::MutantStack(const MutantStack& copy){};

