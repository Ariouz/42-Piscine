/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalvez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 13:35:28 by vicalvez          #+#    #+#             */
/*   Updated: 2023/09/14 13:35:29 by vicalvez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*r;
	int	len;
	int	i;

	i = 0;
	if (min >= max)
		return (0);
	len = max - min;
	r = (int *) malloc(sizeof(int) * len);
	while (i < len)
	{
		r[i] = min++;
		i++;
	}
	return (r);
}
