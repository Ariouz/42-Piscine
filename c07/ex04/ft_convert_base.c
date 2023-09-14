/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalvez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 13:36:13 by vicalvez          #+#    #+#             */
/*   Updated: 2023/09/14 13:36:14 by vicalvez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	check_base(char *base);
int	ft_strlen(char *str);
int	ft_atoi_base(char *nbr, char *base);

int	ft_putnbr_base_len(int nbr, char *base)
{
	int			base_len;
	long int	nbb;
	int			r_value;

	nbb = (long int) nbr;
	r_value = 1;
	if (check_base(base))
	{
		base_len = ft_strlen(base);
		if (nbb < 0)
		{
			nbb *= -1;
			r_value = 2;
		}
		if (nbb >= 0 && nbb < base_len)
		{
			return (r_value);
		}
		else
		{
			return (r_value + ft_putnbr_base_len(nbb / base_len, base));
		}
	}
	return (0);
}

void	ft_putnbr_base(int nbr, char *base, char *s)
{
	int			base_len;
	long int	nbb;

	nbb = (long int) nbr;
	if (*s == 0)
		return ;
	if (check_base(base))
	{
		base_len = ft_strlen(base);
		if (nbb < 0)
			nbb *= -1;
		if (nbb >= 0 && nbb < base_len)
		{
			*s = base[nbb];
		}
		else
		{
			ft_putnbr_base(nbb % base_len, base, s);
			ft_putnbr_base(nbb / base_len, base, s - 1);
		}
	}
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		n;
	int		n_len;
	char	*s;
	int		i;

	if (!check_base(base_from) || !check_base(base_to))
		return (NULL);
	n = ft_atoi_base(nbr, base_from);
	n_len = ft_putnbr_base_len(n, base_to);
	s = (char *) malloc(n_len + 1);
	if (!s)
		return (0);
	i = -1;
	while (++i < n_len)
		s[i] = 'x';
	if (n < 0)
		s[0] = '-';
	s[n_len] = '\0';
	ft_putnbr_base(n, base_to, s + n_len - 1);
	return (s);
}
/*#include <stdio.h>
int	main(int argc, char **argv)
{
	if (argc == 4)
	{
		char	*result = ft_convert_base(argv[1], argv[2], argv[3]);
		printf("Pointeur : %p ; '%s' en base '%s' converti en base '%s' : %s\n"
				,result, argv[1], argv[2], argv[3], result);
		free(result);
	}
	return (0);
}*/
