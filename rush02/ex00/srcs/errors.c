/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acabarba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 16:22:34 by acabarba          #+#    #+#             */
/*   Updated: 2023/09/10 17:46:50 by bponthus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include "../includes/dict_structure.h"
#include "../includes/utils.h"
#include "../includes/errors.h" 
#include "../includes/fonction01.h"

int	error_nb(int argc)
{
	if (argc != 2)
	{
		return (1);
	}
	return (0);
}

int	is_numeric(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

int	error_args(int argc, char **argv)
{
	if (error_nb(argc) || !is_numeric(argv[1]))
	{
		ft_putstr("Error\n");
		return (1);
	}
	return (0);
}

int	error_malloc(char *src)
{
	if (src == 0)
	{
		write(1, "Error_MALLOC\n", 13);
		return (1);
	}
	return (0);
}

int	error_toohigh(char *argv[])
{
	int	i;

	i = 1;
	if (ft_strlen(argv[1]) > 37)
	{
		write(1, "Error_nb_is_too_high\n", 21);
		return (1);
	}
	if (ft_strlen(argv[1]) == 37)
	{
		if (argv[1][0] != '1')
		{
			write(1, "Error_nb_is_too_high\n", 21);
			return (1);
		}
		while (argv[1][i])
		{
			if (argv[1][i] != '0')
			{
				write(1, "Error_nb_is_too_high\n", 21);
				return (1);
			}
			i++;
		}
		return (0);
	}
}

