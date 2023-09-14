/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalvez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 09:10:35 by vicalvez          #+#    #+#             */
/*   Updated: 2023/09/03 18:30:57 by vicalvez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "import.h"

void	show_constraints(int **constraints)
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			ft_putchar(constraints[i][j] + '0');
			ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	main(int argc, char **argv)
{
	int	**constraints;
	int	r;

	if (argc != 2 || ft_strlen(argv[1]) != 31)
	{
		ft_putstr("Error\n");
		return (0);
	}
	constraints = malloc(sizeof(int) * 16);
	r = init_constraints(constraints, argv, argc);
	if (r == 0)
	{
		ft_putstr("Error\n");
		return (0);
	}
	//show_constraints(constraints);
	rush(4, 4, constraints);
	return (0);
}
