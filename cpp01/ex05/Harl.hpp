/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 11:53:24 by rrasezin          #+#    #+#             */
/*   Updated: 2023/07/11 12:03:24 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>

class   Harl
{
    private :
        void    debug(void);
        void    info(void);
        void    warning(void);
        void    error(void);
    public :
        void    complain(std::string level);
};

typedef void (Harl::*ptrToMemberFunc)(void);

#endif