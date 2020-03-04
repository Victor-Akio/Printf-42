/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_percent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vminomiy <vminomiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 10:24:49 by vminomiy          #+#    #+#             */
/*   Updated: 2020/02/28 10:28:17 by vminomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			ft_print_percent(t_flags flags)
{
	int		count;

	count = 0;
	if (flags.minus == 1)
		count += ft_putlstr("%", 1);
	count += ft_print_width(flags.width, 1, flags.zero);
	if (flags.minus == 0)
		count += ft_putlstr("%", 1);
	return (count);
}
