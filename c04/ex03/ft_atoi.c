/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalvez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 10:29:05 by vicalvez          #+#    #+#             */
/*   Updated: 2023/08/30 13:17:48 by vicalvez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_space(char str)
{
	if (str == ' ' || str == '\t' || str == '\n')
		return (1);
	else if (str == '\v' || str == '\f' || str == '\r')
		return (1);
	return (0);
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
	while (is_space(*str) == 1)
		str++;
	while ((*str == '-' || *str == '+'))
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		nb = nb * 10 + (str[i] - '0');
		str++;
	}
	return (nb * sign);
}
