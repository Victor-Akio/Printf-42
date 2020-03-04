/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vminomiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 14:45:53 by vminomiy          #+#    #+#             */
/*   Updated: 2020/01/27 14:24:01 by vminomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*calc(int n, int count, char *str)
{
	unsigned int	sinal;

	str[count] = 0;
	count--;
	sinal = (n > 0) ? n : -n;
	while (sinal)
	{
		str[count] = (sinal % 10) + '0';
		sinal /= 10;
		count--;
	}
	if (!count)
		str[count] = '-';
	return (str);
}

char	*ft_itoa(int n)
{
	int				count;
	unsigned int	sinal;
	char			*str;

	count = (n > 0) ? 0 : 1;
	sinal = (n > 0) ? n : -n;
	if (n == 0)
	{
		if (!(str = malloc(count + 1)))
			return (NULL);
		str[0] = '0';
		str[1] = 0;
		return (str);
	}
	while (sinal)
	{
		count++;
		sinal /= 10;
	}
	if (!(str = malloc(count + 1)))
		return (NULL);
	return (calc(n, count, str));
}
