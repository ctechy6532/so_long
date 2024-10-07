/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctechy <ctechy@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 16:40:59 by ctechy            #+#    #+#             */
/*   Updated: 2022/08/29 16:41:03 by ctechy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_print_ptr(unsigned long ptr)
{
	int				to_ret;

	to_ret = ft_get_len_ptr(ptr);
	if (ptr < 16 && ptr > 9)
		ft_putchar('a' + (ptr % 10));
	else if (ptr < 10)
		ft_putchar('0' + ptr);
	else
	{
		ft_print_ptr(ptr / 16);
		ft_print_ptr(ptr % 16);
	}
	return (to_ret);
}
