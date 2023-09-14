/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalvez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 09:51:11 by vicalvez          #+#    #+#             */
/*   Updated: 2023/08/22 11:01:00 by vicalvez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnumbers(int a, int b, int c)
{
	if (a != b && b != c && c != a)
	{
		write(1, &a, 1);
		write(1, &b, 1);
		write(1, &c, 1);
		if (!(a == '7' && b == '8' && c == '9'))
		{
			write(1, ", ", 2);
		}
	}
}

void	ft_print_comb(void)
{
	int	a;
	int	b;
	int	c;

	a = '0';
	while (a <= '7')
	{
		b = a + 1;
		while (b <= '8')
		{
			c = b + 1;
			while (c <= '9')
			{
				ft_putnumbers(a, b, c);
				c++;
			}
			b++;
		}
		a++;
	}
}
