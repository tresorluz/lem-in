/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluzing <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 11:34:55 by tluzing           #+#    #+#             */
/*   Updated: 2018/09/18 17:52:24 by tluzing          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int	no_rooms(t_lem_info *lem)
{
	if (lem->rooms <= 0 || lem->rooms > 1000)
	{
		ft_putstr("Error : Invalid rooms\n");
		return (1);
	}
	return (0);
}

int	no_ants(t_lem_info *lem)
{
	if (lem->ants <= 0 || lem->ants > 100)
	{
		ft_putstr("Error : Invalid ants/links\n");
		return (1);
	}
	return (0);
}

int	no_man_comm(t_lem_info *lem)
{
	int i;
	int flag;

	i = 0;
	flag = 0;
	while (lem->info[i])
	{
		if (ft_strequ("##start", lem->info[i]) ||
				ft_strequ("##end", lem->info[i]))
			flag++;
		i++;
	}
	if (flag < 2)
	{
		ft_putstr("Error : Invalid mandatory commands\n");
		return (1);
	}
	return (0);
}

int	is_error(t_lem_info *lem)
{
	if (no_ants(lem) || no_rooms(lem) || no_man_comm(lem))
		return (1);
	return (0);
}
