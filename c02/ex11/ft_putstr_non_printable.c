/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalvez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 17:49:42 by vicalvez          #+#    #+#             */
/*   Updated: 2023/08/24 13:04:02 by vicalvez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_char_is_printable(char str)
{
	if (!(str > 31) || str >= 127)
		return (0);
	return (1);
}

void	ft_int_to_hex(int decimal)
{
	int	hex[2];
	int	quotient;
	int	i;
	int	temp;

	quotient = decimal;
	i = 0;
	while (i < 2)
	{
		temp = quotient % 16;
		if (temp < 10)
			temp = temp + 48;
		else
			temp = temp + 87;
		hex[i] = temp;
		quotient = quotient / 16;
		i++;
	}
	i = 1;
	while (i >= 0)
	{
		write(1, hex + i, 1);
		i--;
	}
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_char_is_printable(str[i]) == 0)
		{
			write(1, "\\", 1);
			ft_int_to_hex(str[i]);
		}
		else
			write(1, str + i, 1);
		i++;
	}
}
