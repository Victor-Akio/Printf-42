/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vminomiy <vminomiy@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 21:14:00 by vminomiy          #+#    #+#             */
/*   Updated: 2020/03/04 10:31:08 by vminomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static t_flags		ft_flaginit(void)
{
	t_flags			flags;

	flags.minus = 0;
	flags.zero = 0;
	flags.dot = -1;
	flags.star = 0;
	flags.type = 0;
	flags.width = 0;
	return (flags);
}

static int			ft_check(const char *str, int i, t_flags *flags,
	va_list args)
{
	while (str[i])
	{
		if (!ft_isconversion(str[i]) && !ft_isflags(str[i])
				&& !ft_isdigit(str[i]))
			break ;
		if (str[i] == '0' && flags->width == 0 && flags->minus == 0)
			flags->zero = 1;
		if (str[i] == '*')
			*flags = ft_width_flags(args, *flags);
		if (str[i] == '.')
			i = ft_dot_flags(str, i, args, flags);
		if (str[i] == '-')
			*flags = ft_minus_flags(*flags);
		if (ft_isdigit(str[i]))
			*flags = ft_isdigit_flags(str[i], *flags);
		if (ft_isconversion(str[i]))
		{
			flags->type = str[i];
			break ;
		}
		i++;
	}
	return (i);
}

int					ft_pick_args(const char *str, va_list args)
{
	t_flags			flags;
	int				i;
	int				count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] != '%')
			count += ft_putchar(str[i]);
		else if (str[i] == '%' && str[i + 1])
		{
			flags = ft_flaginit();
			i = ft_check(str, ++i, &flags, args);
			if (ft_isconversion(str[i]))
				count += ft_handler((char)flags.type, flags, args);
			else if (str[i])
				count += ft_putchar(str[i]);
		}
		i++;
	}
	return (count);
}

int					ft_printf(const char *format, ...)
{
	va_list			args;
	int				count;
	char			*str;

	count = 0;
	if (!(str = ft_strdup(format)))
		return (0);
	va_start(args, format);
	count += ft_pick_args(str, args);
	va_end(args);
	free((char *)str);
	return (count);
}
