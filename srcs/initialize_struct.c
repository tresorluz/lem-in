/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_struct.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluzing <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 11:34:32 by tluzing           #+#    #+#             */
/*   Updated: 2018/09/18 17:22:53 by tluzing          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void		initialize_struct_2(t_lem_info *lem)
{
	int			i;

	lem->map = NULL;
	lem->rooms = 0;
	lem->link = 0;
	lem->start = 0;
	lem->end = 0;
	lem->len = 999;
	lem->rmf = (int *)malloc(sizeof(int) * 1000);
	i = 0;
	while (i < 1000)
		lem->rmf[i++] = -1;
	lem->list = (char *)malloc(sizeof(char) * 1000);
	lem->list = NULL;
}

t_lem_info	*initialize_struct(void)
{
	t_lem_info	*lem;
	int			i;

	lem = (t_lem_info *)malloc(sizeof(t_lem_info));
	lem->info = (char **)malloc(sizeof(char *) * 3000);
	lem->ants = 0;
	lem->rm = (t_room *)malloc(sizeof(t_room) * 1000);
	i = 0;
	while (i < 1000)
	{
		lem->rm[i].name = NULL;
		lem->rm[i].x_axis = 0;
		lem->rm[i].y_axis = 0;
		lem->rm[i++].size = 0;
	}
	lem->links = (char **)malloc(sizeof(char *) * 2000);
	i = 0;
	initialize_struct_2(lem);
	return (lem);
}

void		ft_print_links(t_lem_info *lem)
{
	int		i;

	i = 0;
	while (lem->info[i])
	{
		ft_putstr(lem->info[i++]);
		ft_putchar('\n');
	}
}

void		ft_convert_links(t_lem_info *lem)
{
	char	**str;
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	lem->map = (int **)malloc(sizeof(int *) * lem->rooms);
	while (i < lem->rooms)
		lem->map[i++] = (int *)malloc(sizeof(int) * lem->rooms);
	while (k < lem->link)
	{
		str = ft_strsplit(lem->links[k++], '-');
		i = -1;
		while (++i < lem->rooms)
		{
			j = -1;
			while (++j < lem->rooms)
				ft_check_match(lem, str, i, j);
		}
		j = 0;
		while (*(str + j))
			free(str[j++]);
		free(str);
	}
}

void		ft_check_match(t_lem_info *lem, char **str, int i, int j)
{
	if ((!ft_strcmp(lem->rm[i].name, str[0]) &&
	!ft_strcmp(lem->rm[j].name, str[1])) || (!ft_strcmp(lem->rm[i].name, str[1])
	&& !ft_strcmp(lem->rm[j].name, str[0])))
	{
		lem->map[i][j] = 1;
		lem->map[j][i] = 1;
	}
}
