/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vminomiy <vminomiy@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 10:56:57 by vminomiy          #+#    #+#             */
/*   Updated: 2020/03/04 07:28:10 by vminomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			ft_print_c(char c, t_flags flags)
{
	int		count;

	count = 0;
	if (flags.width == 1)
		ft_putchar(c);
	else if (flags.minus == 1)
	{
		ft_putchar(c);
		count = ft_print_width(flags.width, 1, 0);
	}
	else if (flags.minus == 0)
	{
		count = ft_print_width(flags.width, 1, 0);
		ft_putchar(c);
	}
	count++;
	return (count);
}
