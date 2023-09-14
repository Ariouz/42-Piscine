/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalvez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 13:36:24 by vicalvez          #+#    #+#             */
/*   Updated: 2023/09/14 13:36:25 by vicalvez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_sep(char c, char *charset)
{
	while (*charset)
	{
		if (c == *charset)
			return (1);
		charset++;
	}
	return (0);
}

int	get_nb_parts(char *str, char *charset)
{
	while (*(++str))
		if ((is_sep(*str, charset) && !is_sep(*(str - 1), charset))
			|| (!*(str + 1) && !is_sep(*str, charset)))
			return (1 + get_nb_parts(str, charset));
	return (0);
}

char	**init_parts(char *str, char *charset)
{
	char	**parts;
	int		nb_parts;

	if (!*str)
		return (0);
	nb_parts = get_nb_parts(str, charset);
	parts = (char **) malloc(sizeof(char *) * (nb_parts + 1));
	parts[nb_parts] = 0;
	return (parts);
}

void	fill_part(char *str, char *part, int part_len, int start)
{
	while (--part_len >= 0)
		part[part_len] = str[start + part_len];
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		start;
	int		current_part;
	char	**parts;

	i = 0;
	current_part = 0;
	start = 0;
	parts = init_parts(str, charset);
	while (current_part < get_nb_parts(str, charset) && parts)
	{
		if (is_sep(str[i], charset))
			start++;
		if ((!is_sep(str[i], charset) && is_sep(str[i + 1], charset))
			|| !str[i + 1])
		{
			parts[current_part] = (char *) malloc(i + 1 - start + 1);
			parts[current_part][i + 1 - start] = '\0';
			fill_part(str, parts[current_part], i + 1 - start, start);
			start = i + 1;
			current_part++;
		}
		i++;
	}
	return (parts);
}
/*#include <stdio.h>
int	main(int argc, char **argv)
{
	if (argc == 3)
	{
		char	**parts;
		int		i;

		i = 0;
		parts = ft_split(argv[1], argv[2]);	
		if (parts)
		{
			while (parts[i])
			{
				printf("Part[%d] : %s\n", i, parts[i]);
				free(parts[i]);
				if (parts[i + 1] == 0)
					free(parts[i + 1]);
				i++;
			}
			free(parts);
		}
		else
		{
			printf("Split chaine vide !\n");
		}
	}
	return (0);
}*/
