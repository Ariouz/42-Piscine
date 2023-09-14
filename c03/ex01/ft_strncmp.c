/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalvez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 10:20:37 by vicalvez          #+#    #+#             */
/*   Updated: 2023/08/24 18:07:21 by vicalvez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n)
	{
		if (s2[i])
		{
			if (s1[i] > s2[i])
				return (s1[i]);
			else if (s1[i] < s2[i])
			{
				if (s1[i])
					return (-1);
				else if (s2[i])
					return (-s2[i]);
			}
		}
		else
			return (s1[i]);
		i++;
	}
	if (s2[i] && i < n)
		return (-s2[i]);
	return (0);
}
