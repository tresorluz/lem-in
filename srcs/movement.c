/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluzing <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 11:35:36 by tluzing           #+#    #+#             */
/*   Updated: 2018/09/18 17:25:31 by tluzing          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		move_right(t_lem_info *lem, char *list, int y_axis, int x_axis)
{
	if ((x_axis > lem->rooms - 1 || y_axis > lem->rooms - 1 ||
				x_axis < 0 || y_axis < 0))
		return (0);
	if (lem->map[y_axis][lem->rooms - 1] == 1)
	{
		list = add_room(lem, list, lem->rooms - 1);
		return (1);
	}
	if (lem->map[y_axis][x_axis] == 1)
	{
		lem->map[y_axis][x_axis] = 9;
		move_right(lem, list, y_axis, x_axis + 1);
		list = add_room(lem, list, x_axis);
		move_up(lem, list, y_axis - 1, x_axis);
		move_down(lem, list, y_axis + 1, x_axis);
	}
	else if (lem->map[y_axis][x_axis] == 9)
		return (0);
	else
		move_right(lem, list, y_axis, x_axis + 1);
	return (0);
}

int		move_left(t_lem_info *lem, char *list, int y_axis, int x_axis)
{
	if ((x_axis > lem->rooms - 1 || y_axis > lem->rooms - 1 ||
				x_axis < 0 || y_axis < 0))
		return (0);
	if (lem->map[y_axis][lem->rooms - 1] == 1)
	{
		list = add_room(lem, list, lem->rooms - 1);
		return (1);
	}
	if (lem->map[y_axis][x_axis] == 1)
	{
		lem->map[y_axis][x_axis] = 9;
		move_left(lem, list, y_axis, x_axis - 1);
		list = add_room(lem, list, x_axis);
		move_up(lem, list, y_axis - 1, x_axis);
		move_down(lem, list, y_axis + 1, x_axis);
	}
	else if (lem->map[y_axis][x_axis] == 9)
		return (0);
	else
		move_left(lem, list, y_axis, x_axis - 1);
	return (0);
}

int		move_up(t_lem_info *lem, char *list, int y_axis, int x_axis)
{
	if ((x_axis > lem->rooms - 1 || y_axis > lem->rooms - 1 ||
				x_axis < 0 || y_axis < 0))
		return (0);
	if (lem->map[lem->rooms - 1][x_axis] == 1)
	{
		list = add_room(lem, list, lem->rooms - 1);
		return (1);
	}
	if (lem->map[y_axis][x_axis] == 1)
	{
		lem->map[y_axis][x_axis] = 9;
		move_up(lem, list, y_axis - 1, x_axis);
		list = add_room(lem, list, y_axis);
		move_left(lem, list, y_axis, x_axis - 1);
		move_right(lem, list, y_axis, x_axis + 1);
	}
	else if (lem->map[y_axis][x_axis] == 9)
		return (0);
	else
		move_up(lem, list, y_axis - 1, x_axis);
	return (0);
}

int		move_down(t_lem_info *lem, char *list, int y_axis, int x_axis)
{
	if ((x_axis > lem->rooms - 1 || y_axis > lem->rooms - 1 ||
				x_axis < 0 || y_axis < 0))
		return (0);
	if (lem->map[lem->rooms - 1][x_axis] == 1)
	{
		list = add_room(lem, list, lem->rooms - 1);
		return (1);
	}
	if (lem->map[y_axis][x_axis] == 1)
	{
		lem->map[y_axis][x_axis] = 9;
		move_down(lem, list, y_axis + 1, x_axis);
		list = add_room(lem, list, y_axis);
		move_left(lem, list, y_axis, x_axis - 1);
		move_right(lem, list, y_axis, x_axis + 1);
	}
	else if (lem->map[y_axis][x_axis] == 9)
		return (0);
	else
		move_down(lem, list, y_axis + 1, x_axis);
	return (0);
}

void	move(t_lem_info *lem)
{
	char *tmp;

	tmp = ft_strdup(lem->rm[0].name);
	move_right(lem, tmp, 0, 0);
	free(tmp);
}
