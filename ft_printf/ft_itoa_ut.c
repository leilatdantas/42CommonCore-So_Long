/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_ut.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 14:16:16 by lebarbos          #+#    #+#             */
/*   Updated: 2023/08/15 21:23:52 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_countsize(long int nbr)
{
	int	size;

	size = 1;
	if (nbr < 0)
	{
		size++;
		nbr = -nbr;
	}
	while (nbr >= 10)
	{
		size++;
		nbr = nbr / 10;
	}
	return (size);
}

void	ft_putnstr(long int n, char *str, int size)
{
	int	check;

	check = 0;
	str[size] = '\0';
	while (size > check)
	{
		if (n < 0)
		{
			str[0] = '-';
			n = -n;
			check++;
		}
		else
		{
			str[size - 1] = (n % 10) + '0';
			n = n / 10;
			size--;
		}
	}
}

char	*ft_itoa_ut(long int n)
{
	char	*str;
	int		size;

	size = ft_countsize(n);
	str = malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	ft_putnstr(n, str, size);
	return (str);
}
