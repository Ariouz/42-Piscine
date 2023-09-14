/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalvez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 09:47:45 by vicalvez          #+#    #+#             */
/*   Updated: 2023/08/31 15:18:24 by vicalvez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	ft_sort_params(int argc, char **argv)
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	while (i < argc)
	{
		j = 0;
		while (j + 1 < argc)
		{
			if (ft_strcmp(argv[j], argv[j + 1]) >= 1)
			{
				tmp = argv[j];
				argv[j] = argv[j + 1];
				argv[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	i;
	int	j;

	ft_sort_params(argc, argv);
	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			write(1, argv[i] + j, 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
	return (0);
}
