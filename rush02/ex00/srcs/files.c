/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalvez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 10:29:48 by vicalvez          #+#    #+#             */
/*   Updated: 2023/09/10 11:09:55 by vicalvez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "../includes/dict_structure.h"
#include "../includes/utils.h"
#include <stdio.h>
#include "../includes/dict_spliter.h"
#include "../includes/fonction01.h"

t_dict	*set_contents(char *filename, int lcount)
{
	int		i;
	int		j;
	char	*buffer;
	t_dict	*dictionary;
	int		fd;
	t_dict	dict;
	char	*content;

	i = 0;
	j = 0;
	fd = open(filename, O_RDONLY);
	buffer = malloc(sizeof(char) * BUFFER_SIZE);
	dictionary = malloc(sizeof(t_dict) * lcount + 1);
	dict.long_val = 0;
	dictionary[i] = dict;
	content = malloc(sizeof(char) * BUFFER_SIZE);
	while (read(fd, buffer, 1) > 0 && i < lcount - 1)
	{
		if (buffer[0] == '\n')
		{
			content[j] = '\0';
			dictionary[i].long_val = split_dict(content)[0];
			dictionary[i].str_val = split_dict(content)[1];
			dictionary[i].content = content;
			i++;
			dictionary[i] = dict;
			content = malloc(sizeof(char) * BUFFER_SIZE);
			j = 0;
		}
		else
		{
			content[j] = buffer[0];
			j++;
		}
	}
	dictionary[i].content = malloc(sizeof(char *));
	dictionary[i].content[j] = '\0';
	close(fd);
	return (dictionary);
}

t_dict	*init_dictionaries(char *filename)
{
	t_dict	*dictionary;
	int		dict_fd;
	int		j;
	char	*buffer;

	buffer = malloc(sizeof(char) * BUFFER_SIZE);
	dict_fd = open(filename, O_RDONLY);
	j = 1;
	while (read(dict_fd, buffer, 1) > 0)
	{
		if (buffer[0] == '\n')
		{
			j++;
		}
	}
	close(dict_fd);
	dictionary = set_contents(filename, j);
	free(buffer);
	return (dictionary);
}
