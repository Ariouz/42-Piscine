/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalvez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 09:11:52 by vicalvez          #+#    #+#             */
/*   Updated: 2023/09/03 18:44:57 by vicalvez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void	ft_putchar(char c);

void	ft_putstr(char *str);

void	prefill_map(int **map, int **constraints);

int	respect_rules(int k, int pos, int **map, int **constraints);

int	is_on_col(int value, int **map, int col)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (map[i][col] == value)
			return (1);
		i++;
	}
	return (0);
}

int	is_on_row(int value, int **map, int row)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (map[row][i] == value)
			return (1);
		i++;
	}
	return (0);
}

int	is_valid(int **map, int pos, int **constraints)
{
	int	pos_x;
	int	pos_y;
	int	k;

	if (pos == 4*4)
		return (1);
	pos_x = pos % 4;
	pos_y = pos / 4;
	if (map[pos_y][pos_x] != 0)
	{
		return (is_valid(map, pos+1, constraints));
	}
	k = 1;
	while (k <= 4)
	{
		if (is_on_row(k, map, pos_y) == 0 && is_on_col(k, map, pos_x) == 0)
		{
			map[pos_y][pos_x] = k;
			if (respect_rules(k, pos, map, constraints) == 1)
			{
				if (is_valid(map, pos+1, constraints) == 1)
				{
					return (1);
				}
			}
		}
		k++;
	}
	map[pos_y][pos_x] = 0;
	return (0);
}

void	rush(int x, int y, int **constraints)
{
	int	ix;
	int	iy;
	int	**map;
	
	map = malloc(sizeof(int) * y);
	ix = 0;
	iy = 0;
	while (iy < y)
	{
		map[iy] = malloc(sizeof(int) * x);
		iy++;
	}
	prefill_map(map, constraints);
	if (is_valid(map, 0, constraints) == 0)
	{
		ft_putstr("Error\n");
		return ;
	}
	ix = 0;
	iy = 0;
	while (iy < y)
	{
		ix = 0;
		while (ix < x)
		{
			ft_putchar(map[iy][ix]+'0');
			if (!(ix == 3))
				ft_putchar(' ');
			ix++;
		}
		ft_putchar('\n');
		iy++;
	}
	free(constraints);
	free(map);
}
