/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalvez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 11:10:55 by vicalvez          #+#    #+#             */
/*   Updated: 2023/09/10 18:03:36 by vicalvez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/print_numbers.h"
#include "../includes/fonction01.h"
#include <stdio.h>
#include "../includes/decomposer.h"
#include <stdlib.h>

void	print_numbers(char *value, t_dict *dict)
{
	int	i;
	char	*dup;

	//sort_dict(dict);
	i = 0;
	while (dict[i].content[0] != '\0')
	{
		if (cmp(value, dict[i].long_val) == 0)
		{
			ft_putstr(dict[i].str_val);
			return ;
		}
		else 
		{
			if (ft_strlen(value) >= ft_strlen(dict[i].long_val) &&
				ft_strlen(value) < ft_strlen(dict[i + 1].long_val))
			{
				if (cmp(value, dict[i].long_val) > 0)
				{
					print_numbers(char_to_str(value[0]), dict);
					ft_putstr(" ");
					print_numbers(char_to_xzero('1', ft_strlen(value)), dict);
					ft_putstr(" ");
					dup = ft_strdup(value+1);
					print_numbers(dup, dict);
					return ;
				}
			}
			else if(ft_strlen(value) == ft_strlen(dict[i].long_val))
			{
				if (cmp(value, dict[i].long_val) > 0 && cmp(value, dict[i+1].long_val) < 0)
				{
					dup = ft_strdup(value+1);
					print_numbers(char_to_xzero(value[0], ft_strlen(value)), dict);
					ft_putstr(" ");
					print_numbers(dup, dict);
					return ;
				}	
			}
		}
		i++;
	}
}

void	sort_dict(t_dict *dict)
{
	t_dict	tmp;
	int		i;
	int		j;

	i = 0;
	while (dict[i].content[0] != '\0')
	{
		j = 0;
		while (dict[j + 1].content[0] != '\0')
		{
			if (ft_strcmp(dict[j].long_val, dict[j + 1].long_val) >= 1)
			{
				tmp = dict[j];
				dict[j] = dict[j + 1];
				dict[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

int     cmp(char *s1, char *s2)
{
        int     i;

        i = 0;
        while (s1[i])
        {
                if (s2[i])
                {
                        if (s1[i] > s2[i])
                                return (s1[i]);
                        else if (s1[i] < s2[i])
                                return (-s2[i]);
                }
                else
                        return (s1[i]);
                i++;
        }
        if (s2[i])
        {
                return (-s2[i]);
        }
        return (0);
}
