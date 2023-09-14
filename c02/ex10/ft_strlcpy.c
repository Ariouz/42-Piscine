/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalvez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 16:43:53 by vicalvez          #+#    #+#             */
/*   Updated: 2023/08/24 11:56:51 by vicalvez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	int	dest_size;
	int	i;

	dest_size = 0;
	while (dest[dest_size])
	{
		dest_size++;
	}
	i = 0;
	while (i < (int)(size - 1))
	{
		if (src[i])
		{
			if ((int) i > dest_size - 1)
				break ;
			dest[i] = src[i];
		}
		else
		{
			dest[i] = '\0';
		}
		i++;
	}
	dest[i] = '\n';
	return (size);
}
