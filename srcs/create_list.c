/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluzing <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 11:33:51 by tluzing           #+#    #+#             */
/*   Updated: 2018/09/18 17:51:28 by tluzing          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		ft_is_in_list(char *node, char *list)
{
	int		i;
	int		j;
	char	**s;

	i = 0;
	s = ft_strsplit(list, '-');
	while (*(s + i))
	{
		if (ft_strequ(node, s[i]))
		{
			j = 0;
			while (*(s + i + j))
				free(s[i + j++]);
			free(s);
			return (1);
		}
		free(s[i++]);
	}
	free(s);
	return (0);
}

char	*add_room(t_lem_info *lem, char *list, int rm)
{
	char *s;

	if (!ft_is_in_list(lem->rm[rm].name, list))
	{
		s = ft_strjoin(list, "-");
		list = ft_strjoin(s, lem->rm[rm].name);
		free(s);
		if (rm == lem->rooms - 1)
		{
			if (count_moves(list) < lem->len)
			{
				lem->len = count_moves(list);
				free(lem->list);
				lem->list = ft_strdup(list);
			}
		}
	}
	return (list);
}

int		count_moves(char *list)
{
	char	**str;
	int		count;

	str = ft_strsplit(list, '-');
	count = 0;
	while (*(str + count))
		free(str[count++]);
	free(str);
	return (count);
}
