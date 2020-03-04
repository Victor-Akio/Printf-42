/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vminomiy <vminomiy@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 21:15:09 by vminomiy          #+#    #+#             */
/*   Updated: 2020/02/28 13:56:25 by vminomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "../libft/libft.h"

typedef struct	s_flags
{
	int			minus;
	int			zero;
	int			dot;
	int			star;
	int			type;
	int			width;
}				t_flags;

int				ft_printf(const char *format, ...);
int				ft_handler(int c, t_flags flags, va_list args);
int				ft_print_c(char c, t_flags flags);
int				ft_print_di(int c, t_flags flags);
int				ft_print_s(char *c, t_flags flags);
int				ft_print_p(size_t num, t_flags flags);
int				ft_print_u(unsigned int num, t_flags flags);
int				ft_print_x(unsigned int num, int lowcase, t_flags flags);
int				ft_print_percent(t_flags flags);
int				ft_print_width(int width, int minus, int zero);
int				ft_isconversion(int c);
int				ft_isflags(int c);
t_flags			ft_width_flags(va_list args, t_flags flags);
int				ft_dot_flags(const char *str, int start, va_list args,
						t_flags *flags);
t_flags			ft_minus_flags(t_flags flags);
t_flags			ft_isdigit_flags(char c, t_flags flags);

#endif
