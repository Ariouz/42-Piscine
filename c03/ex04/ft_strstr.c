/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalvez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 15:55:24 by vicalvez          #+#    #+#             */
/*   Updated: 2023/08/28 14:50:13 by vicalvez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	c;

	if (*to_find == '\0')
		return (str);
	if (*str == '\0' && *to_find == '\0')
		return (str);
	i = 0;
	while (str[i])
	{
		c = 0;
		while (to_find[c] == str[i + c])
		{
			if (to_find[c + 1] == '\0')
				return (str + i);
			c++;
		}
		i++;
	}
	return (0);
}
