/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_len_nbr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctechy <ctechy@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 04:12:58 by ctechy            #+#    #+#             */
/*   Updated: 2022/08/26 04:12:59 by ctechy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_get_len_nbr(int nb)
{
	int	len;

	len = 0;
	if (nb == 0)
		return (1);
	while (nb != 0)
	{
		len++;
		nb /= 10;
	}
	return (len);
}

int	ft_get_len_unsigned(unsigned int nb)
{
	int	len;

	len = 0;
	if (nb == 0)
		return (1);
	while (nb != 0)
	{
		len++;
		nb /= 10;
	}
	return (len);
}

int	ft_get_len_hex(unsigned int nb)
{
	int	len;

	len = 0;
	if (nb == 0)
		return (1);
	while (nb != 0)
	{
		len++;
		nb /= 16;
	}
	return (len);
}

int	ft_get_len_ptr(unsigned long ptr)
{
	int	len;

	len = 2;
	if (ptr == 0)
	{
		len = 3;
		return (len);
	}
	while (ptr != 0)
	{
		len++;
		ptr /= 16;
	}
	return (len);
}
