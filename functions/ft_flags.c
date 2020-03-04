/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vminomiy <vminomiy@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 11:56:55 by vminomiy          #+#    #+#             */
/*   Updated: 2020/03/04 07:13:09 by vminomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_flags			ft_width_flags(va_list args, t_flags flags)
{
	flags.star = 1;
	flags.width = va_arg(args, int);
	while (flags.width < 0)
	{
		flags.minus = 1;
		flags.width *= -1;
		flags.zero = 0;
	}
	return (flags);
}

int				ft_dot_flags(const char *str, int start, va_list args,
								t_flags *flags)
{
	int		i;

	i = start;
	i++;
	if (str[i] == '*')
	{
		flags->dot = va_arg(args, int);
		i++;
	}
	else
	{
		flags->dot = 0;
		while (ft_isdigit(str[i]))
		{
			flags->dot = ((flags->dot * 10) + (str[i] - '0'));
			i++;
		}
	}
	return (i);
}

t_flags			ft_minus_flags(t_flags flags)
{
	flags.minus = 1;
	flags.zero = 0;
	return (flags);
}

t_flags			ft_isdigit_flags(char c, t_flags flags)
{
	if (flags.star == 1)
		flags.width = 0;
	flags.width = ((flags.width * 10) + (c - '0'));
	return (flags);
}
