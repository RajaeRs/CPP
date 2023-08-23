/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 17:11:01 by rrasezin          #+#    #+#             */
/*   Updated: 2023/08/23 11:40:24 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class   Brain
{
    public :
        std::string ideas[100];
        Brain();
        Brain(const Brain &copy);
        void    setIdeas(std::string animal, int nb);
        Brain& operator=(const Brain &assignement);
        ~Brain();
};