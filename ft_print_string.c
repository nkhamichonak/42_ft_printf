/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natallia <natallia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:10:57 by natallia          #+#    #+#             */
/*   Updated: 2024/10/27 13:13:36 by natallia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_printable_len(const char *s, int precision)
{
	int	len;

	len = 0;
	if (precision > 0)
	{
		while (s[len] && len < precision)
			len++;
	}
	else if (precision == -1)
	{
		while (s[len])
			len++;
	}
	return (len);
}

int	ft_print_string(const char *str, t_flags *flags)
{
	int	count;
	int	len;

	count = 0;
	if (str == NULL)
	{
		str = "(null)";
		len = 6;
	}
	else
		len = ft_printable_len(str, flags->precision);
	if (flags->left_align == 1)
	{
		write (1, str, len);
		count += len;
	}
	count += ft_fill_width(flags->min_width, flags->zero_pad, len);
	if (flags->left_align == 0)
	{
		write (1, str, len);
		count += len;
	}
	return (count);
}
