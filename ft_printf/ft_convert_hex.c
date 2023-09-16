/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_hex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 17:27:24 by lebarbos          #+#    #+#             */
/*   Updated: 2023/08/15 21:23:27 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_convert_hex(unsigned int nbr, char c)
{
	int				size_nbr;
	long long int	n;

	size_nbr = 0;
	n = nbr;
	if (n < 0)
		n = 4294967296 + n;
	if (c == 'x')
		ft_putnbr_base(n, "0123456789abcdef", &size_nbr);
	else if (c == 'X')
		ft_putnbr_base(n, "0123456789ABCDEF", &size_nbr);
	return (size_nbr);
}
