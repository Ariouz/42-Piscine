/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalvez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 14:07:57 by vicalvez          #+#    #+#             */
/*   Updated: 2023/08/22 16:40:22 by vicalvez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int c)
{
	write(1, &c, 1);
}

void ft_combn2(int n, int i, int sn)
{
	char	j;

	if (n <= 0 || n >= 10)
	{
		return ;
	}

	j = i + 1;
	while (j <= '9')
	{
		if (j != i)
		{
			if (!(n == sn-1 && i == '0' && j == '1'))
			{
				write(1, ", ", 2);
			}
			write(1, &i, 1);
			write(1, &j, 1);
			ft_combn2(n - 1, j, sn);
		}
		j++;
	}
}

void	ft_print_combn(int n)
{
	int	i;
	int	j;

	if (n <= 0 || n >= 10)
	{
		return ;
	}

	i = '0';
	while (i <= '9')
	{
		ft_combn2(n, i, n);
		i++;
	}
}

int main(void)
{
	ft_print_combn(1);
	return (0);
}
