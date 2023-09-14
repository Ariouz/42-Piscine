/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalvez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 11:03:32 by vicalvez          #+#    #+#             */
/*   Updated: 2023/08/22 18:04:11 by vicalvez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbrs(int a, int b, int c, int d)
{
	write(1, &a, 1);
	write(1, &b, 1);
	write(1, " ", 1);
	write(1, &c, 1);
	write(1, &d, 1);
	if (!(a == '9' && b == '8' && c == '9' && d == '9'))
	{
		write(1, ",", 1);
	}
}

void	ft_print_comb2(void)
{
	int	a;
	int	b;
	int	c;
	int	d;

	a = 0;
	while (a <= 98)
	{
		b = a;
		while (b <= 99)
		{
			if (a != b)
			{
				c = b / 10 + '0';
				d = b % 10 + '0';
				ft_putnbrs(a / 10 + '0', a % 10 + '0', c, d);
			}
			b++;
		}
		a++;
	}
}
