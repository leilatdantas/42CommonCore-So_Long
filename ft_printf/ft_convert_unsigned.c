/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_unsigned.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 16:59:57 by lebarbos          #+#    #+#             */
/*   Updated: 2023/08/15 21:23:49 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_convert_unsigned(unsigned int nbr)
{
	int	size_nbr;

	size_nbr = 0;
	ft_putnbr_base(nbr, "0123456789", &size_nbr);
	return (size_nbr);
}
