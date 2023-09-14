/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalvez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 13:35:40 by vicalvez          #+#    #+#             */
/*   Updated: 2023/09/14 13:35:41 by vicalvez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	len;
	int	i;

	if (min >= max)
	{
		*range = 0;
		return (0);
	}
	i = -1;
	len = max - min;
	*range = (int *) malloc(sizeof(int) * len);
	if (!(*range))
		return (-1);
	while (++i < len)
		(*range)[i] = min++;
	return (len);
}
