/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalvez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 15:55:49 by vicalvez          #+#    #+#             */
/*   Updated: 2023/08/30 16:04:20 by vicalvez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	i;

	if (nb <= 1)
		return (0);
	i = 1;
	while (i < nb)
	{
		if ((nb % i) == 0 && i != 1)
			return (0);
		i++;
	}
	return (1);
}
