/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalvez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 11:32:02 by vicalvez          #+#    #+#             */
/*   Updated: 2023/09/12 18:57:21 by vicalvez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, str + i, 1);
		i++;
	}
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ftlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*str_cpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup(char *src)
{
	char	*dup;

	dup = malloc(ftlen(src));
	str_cpy(dup, src);
	return (dup);
}

int	ft_atoi(char *str)
{
	int	sign;
	int	i;
	int	nb;

	sign = 1;
	nb = 0;
	i = 0;
	if (*str == '\0')
		return (0);
	while (*str >= '0' && *str <= '9')
	{
		nb = nb * 10 + (str[i] - '0');
		str++;
	}
	return (nb * sign);
}
