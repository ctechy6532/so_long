/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctechy <colin.techy@student.s19.be>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 23:51:26 by ctechy            #+#    #+#             */
/*   Updated: 2022/07/30 23:51:28 by ctechy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_check_formats(const char format, va_list args)
{
	if (format == 'c')
		return (ft_putchar(va_arg(args, int)));
	if (format == 's')
		return (ft_print_string(va_arg(args, char *)));
	if (format == '%')
		return (ft_putchar('%'));
	if (format == 'd')
		return (ft_print_dec(va_arg(args, int)));
	if (format == 'i')
		return (ft_print_dec(va_arg(args, int)));
	if (format == 'u')
		return (ft_print_dec_un(va_arg(args, unsigned int)));
	if (format == 'x')
		return (ft_print_hex_min(va_arg(args, unsigned int)));
	if (format == 'X')
		return (ft_print_hex_max(va_arg(args, unsigned int)));
	if (format == 'p')
	{
		ft_print_string("0x");
		return (ft_print_ptr(va_arg(args, unsigned long)));
	}
	return (0);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		to_return;
	va_list	args;

	va_start(args, format);
	i = 0;
	to_return = 0;
	while (format[i])
	{
		if (format[i] != '%')
		{
			to_return += ft_putchar(format[i]);
			i++;
		}
		else
		{
			to_return += ft_check_formats(format[i + 1], args);
			i += 2;
		}
	}
	va_end(args);
	return (to_return);
}
