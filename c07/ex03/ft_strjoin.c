/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalvez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 13:35:48 by vicalvez          #+#    #+#             */
/*   Updated: 2023/09/14 13:35:49 by vicalvez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	if (!(*str))
		return (0);
	return (1 + ft_strlen(++str));
}

int	get_s_len(int size, char **strs, char *sep)
{
	int	r;
	int	i;

	i = -1;
	r = 0;
	while (++i < size)
		r += ft_strlen(strs[i]);
	r += (size - 1) * ft_strlen(sep);
	return (r);
}

void	ft_put_str_in_s(char *s, char *str, int *i)
{
	while (*str)
	{
		*(s++) = *(str++);
		(*i)++;
	}
}

void	ft_put_sep_in_s(char *s, char *sep, int *i)
{
	while (*sep)
	{
		*(s++) = *(sep++);
		(*i)++;
	}
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*r;
	int		i;
	int		j;
	int		s_len;

	if (size == 0)
	{
		r = (char *) malloc(1);
		r[0] = 0;
	}
	else
	{
		s_len = get_s_len(size, strs, sep);
		r = (char *) malloc(s_len);
		i = 0;
		j = -1;
		while (++j < size)
		{
			ft_put_str_in_s(&r[i], strs[j], &i);
			if (j + 1 < size)
				ft_put_sep_in_s(&r[i], sep, &i);
		}
		r[i] = 0;
	}
	return (r);
}
/*#include <stdio.h>
int	main(int argc, char **argv)
{
	if (argc > 2)
	{
		int strs_count = argc - 2;
		char *s = ft_strjoin(strs_count, argv + 2, argv[1]);
		printf("Result : %s\n", s);
		free(s);
	}
	return (0);
}*/
