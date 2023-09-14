/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalvez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 10:22:40 by vicalvez          #+#    #+#             */
/*   Updated: 2023/09/10 18:04:00 by vicalvez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/dict_structure.h"
#include "../includes/files.h"
#include <stdlib.h>
#include <stdio.h>
#include "../includes/errors.h"
#include "../includes/fonction01.h"
#include "../includes/print_numbers.h"

int	main(int argc, char **argv)
{
	t_dict	*dictionary;
	int		i;

	(void) argv;
	(void) argc;
	dictionary = init_dictionaries("resources/numbers.dict");
	/*if (error_args(argc, argv) || argc < 2)
		return (0);*/
	if (argc == 3)
		dictionary = init_dictionaries(argv[2]);
	i = 0;
	/*while (dictionary[i].content[0] != '\0')
	{
		printf("%s, %s \n", dictionary[i].long_val, dictionary[i].str_val);
		i++;
	}*/
	printf("\n\n");
	print_numbers("9547", dictionary);
	free(dictionary);
	return (0);
}
