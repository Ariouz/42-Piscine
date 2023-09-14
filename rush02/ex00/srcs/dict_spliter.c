/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_spliter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalvez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 10:10:26 by vicalvez          #+#    #+#             */
/*   Updated: 2023/09/10 11:10:08 by vicalvez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/fonction01.h"
#include "../includes/dict_spliter.h"
#include <stdio.h>

int	is_space_or_dd(char c)
{
	if ((c >= 9 && c <= 13) || c == 32 || c == ':')
		return (1);
	return (0);
}

int	cp_len(char *str)
{
	int	i;

	i = 0;
	while (str[i] && !is_space_or_dd(str[i]))
		i++;
	return (i);
}

void	set_cp(char *str, char *dest)
{
	int	i;

	i = 0;
	while (i < cp_len(str))
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
}

char	**split_dict(char *content)
{
	char	**split;
	int		i;
	int		j;

	split = malloc(sizeof(char *) * 2);
	i = 0;
	j = 0;
	while (i < 2 && content[j])
	{
		while (content[j] && is_space_or_dd(content[j]))
			j++;
		split[i] = malloc(sizeof(char) * cp_len(content + j) + 1);
		set_cp(content + j, split[i]);
		while (content[j] && !is_space_or_dd(content[j]))
			j++;
		i++;
	}
	return (split);
}
