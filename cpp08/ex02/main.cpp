/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 18:20:15 by rrasezin          #+#    #+#             */
/*   Updated: 2023/10/12 10:02:36 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <list>

int main()
{
    {
        MutantStack<std::string> mstack;
        mstack.push("t");
        mstack.push("a");
        std::cout << mstack.top() << std::endl;
        mstack.pop();
        std::cout << mstack.size() << std::endl;
        mstack.push("m");
        mstack.push("n");
        mstack.push("l");
        mstack.push("j");
        MutantStack<std::string>::iterator it = mstack.begin();
        MutantStack<std::string>::iterator ite = mstack.end();
        ++it;
        --it;
        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }
        MutantStack<std::string> s(mstack);
        MutantStack<std::string>::iterator itt = s.begin();
        MutantStack<std::string>::iterator itte = s.end();
        ++itt;
            std::cout << "hhhhh\n";
        --itt;
        while (it != itte)
        {
            std::cout << *itt << std::endl;
            ++itt;
        }
    }
    // list
    {
        std::cout << "List :" << std::endl;
        std::list<int> mlist;
        mlist.push_back(5);
        mlist.push_back(17);
        std::cout << mlist.back() << std::endl;
        mlist.pop_back();
        std::cout << mlist.size() << std::endl;
        mlist.push_back(3);
        mlist.push_back(5);
        mlist.push_back(737);
        mlist.push_back(0);
        std::list<int>::iterator it = mlist.begin();
        std::list<int>::iterator ite = mlist.end();
        ++it;
        --it;
        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }
        std::list<int> s(mlist);
    }
    return 0;
}