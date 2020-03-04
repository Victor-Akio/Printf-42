/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vminomiy <vminomiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 00:00:00 by vminomiy          #+#    #+#             */
/*   Updated: 2020/02/28 10:45:05 by vminomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_isconversion(int c)
{
	return (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' ||
			c == 'u' || c == 'x' || c == 'X' || c == '%');
}

int		ft_isflags(int c)
{
	return (c == '-' || c == '0' || c == '.' || c == '*' || c == ' ');
}

int		ft_handler(int c, t_flags flags, va_list args)
{
	int		count;

	count = 0;
	if (c == 'c')
		count = ft_print_c(va_arg(args, int), flags);
	else if (c == 's')
		count = ft_print_s(va_arg(args, char*), flags);
	else if (c == 'p')
		count = ft_print_p(va_arg(args, size_t), flags);
	else if (c == 'd' || c == 'i')
		count = ft_print_di(va_arg(args, int), flags);
	else if (c == 'u')
		count += ft_print_u(va_arg(args, unsigned int), flags);
	else if (c == 'x')
		count += ft_print_x(va_arg(args, unsigned int), 1, flags);
	else if (c == 'X')
		count += ft_print_x(va_arg(args, unsigned int), 0, flags);
	else if (c == '%')
		count += ft_print_percent(flags);
	return (count);
}
