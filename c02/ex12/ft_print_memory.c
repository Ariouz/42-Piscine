/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalvez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 09:34:14 by vicalvez          #+#    #+#             */
/*   Updated: 2023/08/24 10:02:04 by vicalvez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while(str[i])
	{
		i++;
	}
	return (i);
}

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_print_hex(char c, int index)
{
	if (index < 2)
	{
		ft_print_hex(c / 16, index + 1);
        if (c % 16 >= 10)
		ft_putchar('a' + c % 16 % 10);
        else
		ft_putchar('0' + c % 16);
    	}

}

void	*ft_print_memory(void *addr, unsigned int size)
{
	int	i;
	char	*c;

	i = 0;
	c = (char *) addr;
	while (i < size)
	{
		ft_print_hex(*(c + i), 0);

		ft_putchar('\n');
		i++;
	}
}

int main()
{
	char *addr = "Bonjour les aminches\n\r\nc'est fou tout ce au'on peut faire avec \n print memory.\r\rlol.\rlol";
	int size = ft_strlen(addr);
	ft_print_memory(addr, size % 32);
	return (0);
}
