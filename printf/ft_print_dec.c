/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_dec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctechy <ctechy@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 04:07:58 by ctechy            #+#    #+#             */
/*   Updated: 2022/08/26 04:08:00 by ctechy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_print_dec(int nb)
{
	unsigned int	nbr;
	int				to_ret;

	to_ret = ft_get_len_nbr(nb);
	nbr = nb;
	if (nb < 0)
	{
		ft_putchar('-');
		nbr = nbr * -1;
		to_ret++;
	}
	if (nbr > 9)
	{
		ft_print_dec(nbr / 10);
		ft_putchar((nbr % 10) + '0');
	}
	else
		ft_putchar(nbr + '0');
	return (to_ret);
}
