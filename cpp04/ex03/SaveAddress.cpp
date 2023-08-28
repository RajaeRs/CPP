/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SaveAddress.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 12:32:25 by rrasezin          #+#    #+#             */
/*   Updated: 2023/08/28 13:23:06 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

t_floor *Character::new_address(AMateria *new_)
{
    t_floor *floor = new t_floor;

    floor->save = new_;
    floor->next = NULL;
    return (floor);
}

void    Character::add_back(t_floor **old, t_floor *new_)
{
    t_floor *save = *old;

    if (!old || !*old )
        *old = new_;
    else
    {
        while (save->next != NULL)
            save = save->next;
        save->next = new_;
    }
    return ;
}

void    Character::freeFloor(t_floor *save)
{
    t_floor *tmp = save;

    while(tmp != NULL)
    {
        tmp = save->next;
        if (save->save)
            delete save->save;
        delete save;
        save = tmp;
    }
    return ;
}