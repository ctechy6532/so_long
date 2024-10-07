/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctechy <ctechy@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 13:07:07 by ctechy            #+#    #+#             */
/*   Updated: 2022/08/26 13:07:08 by ctechy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_print_hex_min(unsigned int nb)
{
	unsigned int	nbr;
	int				to_ret;

	to_ret = ft_get_len_hex(nb);
	nbr = nb;
	if (nbr < 16 && nbr > 9)
		ft_putchar('a' + (nbr % 10));
	else if (nbr < 10)
		ft_putchar('0' + nbr);
	else
	{
		ft_print_hex_min(nbr / 16);
		ft_print_hex_min(nbr % 16);
	}
	return (to_ret);
}

int	ft_print_hex_max(unsigned int nb)
{
	unsigned int	nbr;
	int				to_ret;

	to_ret = ft_get_len_hex(nb);
	nbr = nb;
	if (nbr < 16 && nbr > 9)
		ft_putchar('A' + (nbr % 10));
	else if (nbr < 10)
		ft_putchar('0' + nbr);
	else
	{
		ft_print_hex_max(nbr / 16);
		ft_print_hex_max(nbr % 16);
	}
	return (to_ret);
}
