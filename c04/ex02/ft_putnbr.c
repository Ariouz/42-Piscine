/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalvez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 11:42:33 by vicalvez          #+#    #+#             */
/*   Updated: 2023/08/30 09:50:10 by vicalvez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_printlast(int nb, int m)
{
	if (nb > 9)
	{
		ft_putchar(m + '0');
	}
	else
	{
		ft_putchar(nb + '0');
	}
}

int	ft_nb_neg(int nb)
{
	if (nb < 0)
	{
		ft_putchar('-');
		return (-nb);
	}
	return (nb);
}

void	ft_putnbr(int nb)
{
	int	m;

	m = 0;
	if (nb < 10 && nb >= 0)
	{
		ft_putchar(nb + '0');
		return ;
	}
	if (nb == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		ft_putnbr(147483648);
		return ;
	}
	nb = ft_nb_neg(nb);
	if (nb > 9)
	{
		m = nb % 10;
		ft_putnbr(nb / 10);
	}
	ft_printlast(nb, m);
}
