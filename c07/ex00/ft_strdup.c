/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalvez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 13:35:17 by vicalvez          #+#    #+#             */
/*   Updated: 2023/09/14 13:35:19 by vicalvez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	if (!*str)
		return (0);
	return (1 + ft_strlen(++str));
}

char	*ft_strdup(char *src)
{
	char	*r;
	int		src_len;

	src_len = ft_strlen(src);
	r = (char *) malloc(src_len + 1);
	r[src_len] = '\0';
	while (--src_len >= 0)
		r[src_len] = src[src_len];
	return (r);
}
