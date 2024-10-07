/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_dec_un.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctechy <ctechy@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 12:23:16 by ctechy            #+#    #+#             */
/*   Updated: 2022/08/26 12:23:19 by ctechy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_print_dec_un(unsigned int nb)
{
	unsigned int	nbr;
	int				to_ret;

	to_ret = ft_get_len_unsigned(nb);
	nbr = nb;
	if (nbr > 9)
	{
		ft_print_dec_un(nbr / 10);
		ft_putchar((nbr % 10) + '0');
	}
	else
	{
		ft_putchar(nbr + '0');
	}
	return (to_ret);
}
