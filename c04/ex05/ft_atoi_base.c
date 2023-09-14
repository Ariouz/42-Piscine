/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalvez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 16:37:48 by vicalvez          #+#    #+#             */
/*   Updated: 2023/08/30 10:31:14 by vicalvez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>

int	is_space_or_inbase(char str, char *base, int ib)
{
	int	i;

	i = 0;
	if (ib == 1)
	{
		while (base[i])
		{
			if (base[i] == str)
				return (1);
			i++;
		}
		return (0);
	}
	else
	{
		if (str == ' ' || str == '\t' || str == '\n')
			return (1);
		else if (str == '\v' || str == '\f' || str == '\r')
			return (1);
	}
	return (0);
}

int	ft_index_blen(char *str, char *base, int *blen)
{
	int	index;
	int	j;

	index = 0;
	j = 0;
	while (base[*blen])
		*blen = *blen + 1;
	while (str[j])
	{
		if ((str[j] >= 9 && str[j] <= 13) || str[j] == 32)
			index++;
		else
			break ;
		j++;
	}
	return (index);
}

int	check(char *base)
{
	int	j;
	int	i;

	i = 0;
	while (base[i])
	{
		if (is_space_or_inbase(base[i], base, 0) == 1
			|| base[i] == '-' || base[i] == '+')
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[j] == base[i])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	get_value_or_sign(char c, char *str, int *sign, int *ci)
{
	int	i;

	i = 0;
	if (c == 0)
	{
		while (str[i])
		{
			if (str[i] == '-')
				*sign = -*sign;
			if (str[i] == '-' || str[i] == '+')
				*ci = *ci + 1;
			i++;
		}
	}
	else
	{
		while (str[i])
		{
			if (str[i] == c)
				return (i);
			i++;
		}
		return (0);
	}
	return (0);
}

int	ft_atoi_base(char *str, char *base)
{
	int	blen;
	int	char_index;
	int	res;
	int	sign;

	blen = 0;
	res = 0;
	sign = 1;
	char_index = ft_index_blen(str, base, &blen);
	get_value_or_sign('\0', str, &sign, &char_index);
	if (check(base) == 0)
		return (0);
	while (str[char_index] && is_space_or_inbase(str[char_index], base, 1) == 1)
	{
		res = res * blen + get_value_or_sign(str[char_index],
				base, &sign, &char_index);
		char_index++;
	}
	return (res * sign);
}
