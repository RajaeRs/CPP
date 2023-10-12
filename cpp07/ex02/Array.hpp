/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 13:28:01 by rrasezin          #+#    #+#             */
/*   Updated: 2023/10/11 18:23:58 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

template<class  Array>
class   TemplateClass
{
    private:
        Array   *arr;
    public:
        TemplateClass()
        {
            this->arr = new Array();
            *(this->arr) = 'A';
        }
        TemplateClass(unsigned int n)
        {
            unsigned int i = 0;
            this->arr = new Array[n];
            while (i < n)
            {
                this->arr[i] = 'A';
                i++;
            }
        }
        TemplateClass(const TemplateClass& copy)
        {
            int s = copy.size();
            int i = 0;
            this->arr = new Array[s];
            while (i < s)
            {
                this->arr[i] = copy.arr[i];
                i++;
            }
        }
        TemplateClass& operator=(const TemplateClass& assignement)
        {
            delete[] this->arr;
            int s = assignement.size();
            int i = 0;
            this->arr = new Array[s];
            while (i < s)
            {
                this->arr[i] = assignement.arr[i];
                i++;
            }
            return (*this);
        }
        Array&   operator[](unsigned int n) const
        {
            unsigned int s = this->size();
            if (n >= s)
                throw TemplateClass::OutOfBounds();
            return(this->arr[n]);
        }
        unsigned size() const
        {
            unsigned int s = 0;

            while (this->arr && this->arr[s])
                s++;
            return (s);
        }
        class   OutOfBounds : public std::exception
        {
            public:
                const char * what() const throw()
                {
                    return ("this index is out of range");
                }
        };
        ~TemplateClass()
        {
            delete[] this->arr;
        }
};