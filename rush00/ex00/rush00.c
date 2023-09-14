/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalvez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 09:05:46 by vicalvez          #+#    #+#             */
/*   Updated: 2023/08/26 14:25:14 by vicalvez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	print_chars(int x, int ix, int y, int iy)
{
	if (iy != 0 && iy != y - 1)
	{
		if (ix != 0 && ix != x - 1)
			ft_putchar(' ');
		else
			ft_putchar('|');
	}
	else
	{
		if (ix != 0 && ix != x - 1)
			ft_putchar('-');
		else
			ft_putchar('o');
	}
}

void	rush(int x, int y)
{
	int	iy;
	int	ix;

	if (x < 1 || y < 1)
		return ;
	iy = 0;
	while (iy < y)
	{
		ix = 0;
		while (ix < x)
		{
			print_chars(x, ix, y, iy);
			ix++;
		}
		ft_putchar('\n');
		iy++;
	}
}
