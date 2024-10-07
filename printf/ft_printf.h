/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctechy <colin.techy@student.s19.be>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 23:50:32 by ctechy            #+#    #+#             */
/*   Updated: 2022/07/30 23:50:40 by ctechy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int	ft_printf(const char *format, ...);
int	ft_print_string(char *str);
int	ft_putchar(char c);
int	ft_print_dec(int nb);
int	ft_get_len_nbr(int nb);
int	ft_print_dec_un(unsigned int nb);
int	ft_get_len_unsigned(unsigned int nb);
int	ft_print_hex_min(unsigned int nb);
int	ft_get_len_hex(unsigned int nb);
int	ft_print_hex_max(unsigned int nb);
int	ft_print_ptr(unsigned long ptr);
int	ft_get_len_ptr(unsigned long ptr);

#endif
