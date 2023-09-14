/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_numbers.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalvez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 11:11:07 by vicalvez          #+#    #+#             */
/*   Updated: 2023/09/10 11:31:14 by vicalvez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_NUMBERS_H
# define PRINT_NUMBERS_H
# include "dict_structure.h"

void	print_numbers(char *value, t_dict *dict);
void	sort_dict(t_dict *dict);
int		cmp(char *s1, char *s2);

#endif
