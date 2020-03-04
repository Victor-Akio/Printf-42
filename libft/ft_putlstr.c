/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vminomiy <vminomiy@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 15:06:33 by vminomiy          #+#    #+#             */
/*   Updated: 2020/03/04 06:48:33 by vminomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_putlstr(char *str, int len)
{
	int i;

	i = 0;
	while (str[i] != '\0' && i < len)
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}
