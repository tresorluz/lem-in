/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluzing <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 11:35:14 by tluzing           #+#    #+#             */
/*   Updated: 2018/09/18 11:35:16 by tluzing          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	all_info(t_lem_info *lem)
{
	readstore_info(lem);
	ft_store(lem);
	if (is_error(lem))
		exit(0);
	ft_convert_links(lem);
	move(lem);
	if (!lem->list)
	{
		ft_putstr("Error : No valid solution\n");
		exit(0);
	}
	sort_rooms(lem);
	ft_print_links(lem);
	ft_putchar('\n');
	move_ants(lem);
}

void	release_mem(t_lem_info *lem)
{
	int i;

	i = 0;
	free(lem->info);
	free(lem->rm);
	while (lem->links[i])
	{
		free(lem->links[i]);
		lem->links[i] = NULL;
		i++;
	}
	free(lem->links);
	i = 0;
	while (i < lem->rooms)
	{
		free(lem->map[i]);
		lem->map[i] = NULL;
		i++;
	}
	free(lem->map);
	free(lem->list);
	free(lem->rmf);
}

int		main(void)
{
	t_lem_info	*lem;

	lem = initialize_struct();
	all_info(lem);
	release_mem(lem);
	free(lem);
	return (0);
}
