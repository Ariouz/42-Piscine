#include <stdio.h>

void	prefill_map(int **map, int **constraints)
{
	int	y;
	int	x;

	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			if ((constraints[0][x] == 1 & y == 0) || (constraints[1][x] == 1 && y == 3))
				map[y][x] = 4;
			else if((constraints[2][y] == 1 && x == 0) || (constraints[3][y] == 1 && x == 3))
				map[y][x] = 4;
			else if (constraints[0][x] == 3 && constraints[1][x] == 2)
				map[constraints[1][x]][x] = 4;
			else if (constraints[0][x] == 2 && constraints[1][x] == 3)
				map[4-constraints[1][x]][x] = 4;
			else if (constraints[2][y] == 3 && constraints[3][y] == 2)	
				map[y][constraints[2][y]-1] = 4;
			else if (constraints[2][y] == 2 && constraints[3][y] == 3)
				map[y][4-constraints[3][y]] = 4;
			else if ((constraints[0][x] == 4 & y == 0) || (constraints[1][x] == 4 && y == 3))
                                map[y][x] = 1;
                        else if((constraints[2][y] == 4 && x == 0) || (constraints[3][y] == 4 && x == 3))
                                map[y][x] = 1;
			x++;
		}
		y++;
	}
}

int	respect_left(int k, int pos, int **map, int **constraints)
{
	int	j;
	int	y;
	int	max;
	int	visibles;
	
	y = pos / 4;
        max = 0;
        visibles = 0;
        j = 0;	
   
	while (j < 4)
	{
		if (map[y][j] > max)
		{
			max = map[y][j];
		        visibles++;
		}
		j++;
	}
	if (pos % 4 < 3)
	{
		if (constraints[2][y] - visibles == 0)
				return (1);
			return (1);
	}
	return (1);
}

int	respect_right(int k, int pos, int **map, int **constraints)
{
	int	j;
	int	y;
	int	max;
	int	visibles;

	y = pos / 4;
	max = 0;
	visibles = 0;
	j = 0;

	while (j < 4)
	{
		if (map[y][3-j] > max)
		{
		        max = map[y][3-j];
		        visibles++;
		}
	j++;
	}
	if (pos % 4 < 3)
	{
		if (constraints[3][y] - visibles == 0)
			return (1);
		return (1);
	}	
	return (1);
}

int	respect_top(int k, int pos, int **map, int **constraints)
{
	int	j;
	int	x;
	int	max;
	int	visibles;

	x = pos % 4;
	max = 0;
	visibles = 0;
	j = 0;
	

		while (j < 4)
		{
		        if (map[j][x] > max)
		        {
		                max = map[j][x];
		                visibles++;
		        }
			j++;
		}
	if (pos / 4 < 3)
	{
		if (constraints[0][x] - visibles == 0)
			return (1);
		return (1);
	}
	return (1);
}

int	respect_bottom(int k, int pos, int **map, int **constraints)
{
	int	j;
	int	x;
	int	max;
	int	visibles;

	x = pos % 4;
	max = 0;
	visibles = 0;
	j = 0;
	
	while (j < 4)
	{
		if (map[3-j][x] > max)
		{
			max = map[3-j][x];
			visibles++;
		}
		j++;
	}
	if (pos / 4 < 3)
	{
		if (constraints[1][x] - visibles == 0)
			return (1);
		else
			return (1);
	}
	return (1);
}

int     respect_rules(int k, int pos, int **map, int **constraints)
{

        	
        if (respect_left(k, pos, map, constraints) == 1)
        	return (1);
        
        return (0);
}
