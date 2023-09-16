/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 10:23:38 by lebarbos          #+#    #+#             */
/*   Updated: 2023/08/15 21:23:58 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	evaluate_fmt(const char *fmt, int i, va_list args)
{
	if (fmt[i] == 'c')
		return (ft_convert_char(va_arg(args, int)));
	else if (fmt[i] == 's')
		return (ft_convert_string(va_arg(args, char *)));
	else if (fmt[i] == 'd' || fmt[i] == 'i')
		return (ft_convert_integer(va_arg(args, int)));
	else if (fmt[i] == 'u')
		return (ft_convert_unsigned(va_arg(args, unsigned int)));
	else if (ft_tolower(fmt[i]) == 'x')
		return (ft_convert_hex(va_arg(args, unsigned int), fmt[i]));
	else if (fmt[i] == 'p')
		return (ft_convert_pointer(va_arg(args, unsigned long long)));
	else if (fmt[i] == '%')
	{
		ft_putchar_fd ('%', 1);
		return (1);
	}
	return (0);
}

int	ft_printf(const char *fmt, ...)
{
	int		i;
	int		ret;
	va_list	args;

	ret = 0;
	i = 0;
	va_start(args, fmt);
	if (!fmt)
		return (-1);
	while (fmt[i])
	{
		if (fmt[i] == '%')
		{
			ret += evaluate_fmt(fmt, i + 1, args);
			i++;
		}
		else
		{
			ft_putchar_fd(fmt[i], 1);
			ret++;
		}
		i++;
	}
	va_end(args);
	return (ret);
}

/*#include <limits.h>
#include <stdio.h>

int	main(void)
{
	char			c;
	char			*str;
	int				integer;
	unsigned int	uns_int;
	unsigned int	hex;
	void			*ptr;
	int				x;
	int				y;

	c = '0';
	str = "String Teste$%0";
	integer = INT_MAX;
	uns_int = -2147483646;
	hex = 1;
	ptr = &str;
	ft_printf("\nft_printf:\n");
	x = ft_printf("Char: %c\nString: %s\nInteger %%d: %d\nInteger %%i: \
	%i\nUnsigned Integer: %u\nHexadecimal x: %x\nHexadecimal X: %X\nPointer: \
	%p\n", c, str, integer, integer, uns_int, hex, hex, ptr);
	ft_printf("\nReturn = %d\n", x);

	printf("\nprintf:\n");
	y = printf("Char: %c\nString: %s\nInteger %%d: %d\nInteger %%i: \
	%i\nUnsigned Integer: %u\nHexadecimal x: %x\nHexadecimal X: %X\nPointer: \
	%p\n", c, str, integer, integer, uns_int, hex, hex, ptr);
	printf("\nReturn = %d\n", y);
	return (0);
}
*/