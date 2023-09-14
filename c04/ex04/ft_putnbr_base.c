/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalvez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 14:01:55 by vicalvez          #+#    #+#             */
/*   Updated: 2023/08/30 15:32:23 by vicalvez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_printlast(long nb, long m, char *base, int blen)
{
	if (nb > blen)
	{
		ft_putchar(base[m]);
	}
	else
	{
		ft_putchar(base[nb]);
	}
	return (1);
}

int	ft_nb_neg(long *nb, long blen, char *base)
{
	int	i;

	i = 0;
	while (i < blen)
	{
		if (base[i] == '\0' || (base[i] >= 9 && base[i] <= 32)
			|| base[i] == '-' || base[i] == '+')
			return (0);
		i++;
	}
	if (*nb < 0)
	{
		*nb = -*nb;
		ft_putchar('-');
	}
	return (1);
}

int	ft_check_base(char *base, long nb, int blen)
{
	int	i;
	int	j;

	i = 0;
	while (base[i++])
	{
		j = i + 1;
		while (base[j++])
		{
			if (base[j] == base[i])
				return (0);
			j++;
		}
		i++;
	}
	if (nb < blen && nb >= 0)
	{
		ft_putchar(base[nb]);
		return (0);
	}
	return (1);
}

void	ft_putnbr_base(int nb, char *base)
{
	long	nl;
	long	m;
	long	blen;

	blen = 0;
	m = 0;
	nl = nb;
	while (base[blen])
		blen++;
	if (blen < 2)
		return ;
	if (ft_check_base(base, nl, blen) == 0 || ft_nb_neg(&nl, blen, base) == 0)
		return ;
	if (nl >= blen)
	{
		m = nl % blen;
		ft_putnbr_base((nl / blen), base);
	}
	ft_printlast(nl, m, base, blen);
}
