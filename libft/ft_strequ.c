/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluzing <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 12:42:05 by tluzing           #+#    #+#             */
/*   Updated: 2018/06/04 14:17:03 by tluzing          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strequ(char const *s1, char const *s2)
{
	if (s1 && s2)
	{
		while (*s1)
		{
			if (*s1 != *s2)
				return (0);
			s1++;
			s2++;
		}
		if (*s1 == *s2)
			return (1);
		return (0);
	}
	return (0);
}
