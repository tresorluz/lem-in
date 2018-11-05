/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluzing <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 09:50:47 by tluzing           #+#    #+#             */
/*   Updated: 2018/09/04 09:51:19 by tluzing          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_sqrt(int nb)
{
	int r;

	r = 1;
	if (nb < 0 || nb == 0)
	{
		return (0);
	}
	while (r < 46341)
	{
		if ((r * r) == nb)
		{
			return (r);
		}
		r = (r + 1);
	}
	return (0);
}
