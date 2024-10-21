/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhamich <nkhamich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 12:08:40 by nkhamich          #+#    #+#             */
/*   Updated: 2024/10/21 15:56:30 by nkhamich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "libft.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			// function to establish format
			// function to parse flags
			// function to print the arg
		}
		else
			ft_putchar(*format);
		format++;
	}
	va_end(args);
	return (count);
}
