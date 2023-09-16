/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 17:08:10 by lebarbos          #+#    #+#             */
/*   Updated: 2023/08/15 21:24:02 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_putnbr_base(unsigned long long nbr, char *base, int *i)
{
	size_t	base_len;

	base_len = ft_strlen(base);
	if (nbr >= base_len)
	{
		ft_putnbr_base(nbr / base_len, base, i);
		nbr = nbr % base_len;
	}
	*i = *i + 1;
	write(1, &base[nbr], 1);
}
