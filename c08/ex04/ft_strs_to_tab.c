/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalvez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 11:25:12 by vicalvez          #+#    #+#             */
/*   Updated: 2023/09/05 10:30:14 by vicalvez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	ft_strlen(char *str)
{
	if (!*str)
		return (0);
	return (1 + ft_strlen(++str));
}

char	*ft_strdup(char *src)
{
	char	*dup;

	dup = malloc(ft_strlen(src));
	ft_strcpy(dup, src);
	return (dup);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*r;
	int			i;

	r = malloc(sizeof(t_stock_str) * (ac + 1));
	if (r == 0)
		return (0);
	i = 0;
	while (i < ac)
	{
		r[i].size = ft_strlen(av[i]);
		r[i].str = av[i];
		r[i].copy = malloc(sizeof(char) * (r[i].size + 1));
		if (r[i].copy == 0)
			return (0);
		ft_strcpy(r[i].copy, av[i]);
		i++;
	}
	r[i].str = 0;
	return (r);
}
