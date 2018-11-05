/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluzing <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 11:36:19 by tluzing           #+#    #+#             */
/*   Updated: 2018/09/18 11:37:25 by tluzing          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		readstore_info(t_lem_info *lem)
{
	char	*line;
	int		i;

	i = 0;
	while (get_next_line(0, &line))
	{
		if (ft_strequ(line, ""))
		{
			free(line);
			return (0);
		}
		else
			lem->info[i++] = ft_strdup(line);
		free(line);
	}
	if (i == 0)
	{
		ft_putstr("Error : Empty file\n");
		exit(0);
	}
	lem->info[i] = NULL;
	return (1);
}

int		ft_store(t_lem_info *lem)
{
	int		i;
	char	*p;

	i = 0;
	while (lem->info[i])
	{
		if (ft_strequ(lem->info[i], "##start"))
			lem->start = lem->rooms;
		else if (ft_strequ(lem->info[i], "##end"))
			lem->end = lem->rooms;
		else if ((p = ft_strchr(lem->info[i], ' ')) &&
				lem->info[i][0] != '#' && (p = ft_strchr(p + 1, ' ')))
			store_room(lem, lem->info[i]);
		else if ((p = ft_strchr(lem->info[i], '-')) && ft_strcmp(p + 1, ""))
			lem->links[lem->link++] = ft_strdup(lem->info[i]);
		else if (lem->info[i][0] != '#' && !ft_strchr(lem->info[i], ' '))
			lem->ants = ft_atoi(lem->info[i]);
		i++;
	}
	lem->links[lem->link] = NULL;
	lem->rm[lem->rooms].name = NULL;
	order_rooms(lem);
	return (1);
}

void	order_rooms2(t_lem_info *lem, t_room *temp)
{
	temp->name = lem->rm[0].name;
	temp->x_axis = lem->rm[0].x_axis;
	temp->y_axis = lem->rm[0].y_axis;
	lem->rm[0].name = lem->rm[lem->start].name;
	lem->rm[0].x_axis = lem->rm[lem->start].x_axis;
	lem->rm[0].y_axis = lem->rm[lem->start].y_axis;
	lem->rm[lem->start].name = temp->name;
	lem->rm[lem->start].x_axis = temp->x_axis;
	lem->rm[lem->start].y_axis = temp->y_axis;
}

void	order_rooms(t_lem_info *lem)
{
	t_room	temp;

	if (lem->start != 0)
	{
		order_rooms2(lem, &temp);
	}
	if (lem->end != lem->rooms - 1)
	{
		temp.name = lem->rm[lem->rooms - 1].name;
		temp.x_axis = lem->rm[lem->rooms - 1].x_axis;
		temp.y_axis = lem->rm[lem->rooms - 1].y_axis;
		lem->rm[lem->rooms - 1].name = lem->rm[lem->end].name;
		lem->rm[lem->rooms - 1].x_axis = lem->rm[lem->end].x_axis;
		lem->rm[lem->rooms - 1].y_axis = lem->rm[lem->end].y_axis;
		lem->rm[lem->end].name = temp.name;
		lem->rm[lem->end].x_axis = temp.x_axis;
		lem->rm[lem->end].y_axis = temp.y_axis;
	}
}

void	store_room(t_lem_info *lem, char *str)
{
	char	**s;
	int		i;

	i = 0;
	s = ft_strsplit(str, ' ');
	lem->rm[lem->rooms].name = ft_strdup(s[0]);
	lem->rm[lem->rooms].x_axis = ft_atoi(s[1]);
	lem->rm[lem->rooms++].y_axis = ft_atoi(s[2]);
	while (*(s + i))
		free(s[i++]);
	free(s);
}
