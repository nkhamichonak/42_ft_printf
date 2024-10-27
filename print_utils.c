/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natallia <natallia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 13:14:47 by natallia          #+#    #+#             */
/*   Updated: 2024/10/27 13:13:56 by natallia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(unsigned char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(const char *s)
{
	int	len;

	len = ft_strlen(s);
	write(1, s, len);
	return (len);
}

int	ft_fill_width(int min_width, int zero_pad, int size)
{
	int	count;

	count = 0;
	while (min_width - size > 0)
	{
		if (!zero_pad)
			count += ft_putchar(' ');
		else
			count += ft_putchar('0');
		min_width--;
	}
	return (count);
}
