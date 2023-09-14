/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decomposer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalvez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 14:15:24 by vicalvez          #+#    #+#             */
/*   Updated: 2023/09/10 15:28:09 by vicalvez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "../includes/fonction01.h"
#include "../includes/errors.h"
#include "../includes/decomposer.h"

char	*cpy_after_three(char *src, int len)
{
	int		i;
	char	*dest;

	i = 0;
	dest = malloc(sizeof(char) * len - 2);
	dest = str_cpy(dest, src + 3);
	return (dest);
}

char	*char_to_str(char c)
{
	char	*dest;

	dest = malloc(2);
	dest[0] = c;
	dest[1] = '\0';
	return (dest);
}

char	*str_cpy(char *dest, char *src)
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

char	*char_to_xzero(char c, int len)
{
<<<<<<< HEAD
	char *d;
	int	i;
=======
	char	*d;
>>>>>>> 1c92eba6b4d7b60b6340b79a06425d98285045d3

	i = 1;
	len--;
	d = malloc(len + 1);
	d[0] = c;
	while (i <= len)
	{
		d[i] = '0';
		i++;
	}	
	d[i] = '\0';
	return (d);
}

char	*ft_strdup(char *src)
{
	char	*dup;

	dup = malloc(ft_strlen(src));
	str_cpy(dup, src);
	return (dup);
}
