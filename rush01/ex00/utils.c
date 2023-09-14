/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalvez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 16:37:29 by vicalvez          #+#    #+#             */
/*   Updated: 2023/09/03 10:05:54 by vicalvez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	is_space(char str)
{
	if (str == ' ' || str == '\t' || str == '\n')
		return (1);
	else if (str == '\v' || str == '\f' || str == '\r')
		return (1);
	return (0);
}

int	ft_atoi(char str)
{
	int	sign;
	int	i;
	int	nb;

	nb = 0;
	i = 0;
	if (str == '\0')
		return (0);
	if (str >= '0' && str <= '9')
	{
		nb = nb * 10 + (str - '0');
	}
	else
		return (-1);
	return (nb);
}

void	ft_putchar(char c);

int	init_constraints(int **constraints, char **argv, int argc)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (argv[1][i])
	{
		if (i % 4 == 0)
			constraints[i/4] = malloc(sizeof(int) * 4);
		if (i % 2 == 0)
		{
			if (argv[1][i] >= '1' && argv[1][i] <= '4')
			{
				if (ft_atoi(argv[1][i]) == -1)
					return (0);
				constraints[j/4][j%4] = ft_atoi(argv[1][i]);
				j++;
			}
			else
				return (0);
		
		}
		i++;
	}
	return (1);
}
