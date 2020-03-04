/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vminomiy <vminomiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 17:20:33 by vminomiy          #+#    #+#             */
/*   Updated: 2020/02/12 13:35:04 by vminomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_atoi(const char *str)
{
	int			x;
	int			sinal;
	int			aux;

	x = 0;
	sinal = -1;
	aux = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '+' || *str == '-')
		if (*str++ == '-')
			sinal = 1;
	while (ft_isdigit(*str))
	{
		x = x * 10 - (*str++ - 48);
		if (aux < x)
		{
			if (sinal < 0)
				return (-1);
			return (0);
		}
		aux = x;
	}
	return (x * sinal);
}
