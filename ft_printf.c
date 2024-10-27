/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natallia <natallia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 12:08:40 by nkhamich          #+#    #+#             */
/*   Updated: 2024/10/27 16:24:54 by natallia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_argument(char format_spec, va_list args, t_flags *flags)
{
	int	count;

	count = 0;
	if (format_spec == 'c')
		count += ft_print_char(va_arg(args, int), flags);
	if (format_spec == 's')
		count += ft_print_string(va_arg(args, const char *), flags);
	if (format_spec == 'd' || format_spec == 'i')
		count += ft_print_int(va_arg(args, int), flags);
	if (format_spec == 'x')
		count += ft_print_hex(va_arg(args, unsigned int), flags, 0);
	if (format_spec == 'X')
		count += ft_print_hex(va_arg(args, unsigned int), flags, 1);
	if (format_spec == '%')
		count += ft_print_char('%', flags);
	if (format_spec == 'u')
		count += ft_print_unsigned(va_arg(args, unsigned int), flags);
	if (format_spec == 'p')
		count += ft_print_pointer(va_arg(args, void *), flags);
	return (count);
}

static int	ft_print_substr(const char *str, const char *ptr)
{
	int			count;
	size_t		len;
	char		*temp;

	count = 0;
	len = ptr - str;
	temp = ft_substr(str, 0, len);
	if (temp == NULL)
		return (0);
	count += ft_putstr(temp);
	free (temp);
	return (count);
}

static int	ft_parse(const char *str, va_list args)
{
	int			count;
	char		format_spec;
	const char	*ptr;
	t_flags		flags;

	count = 0;
	while (*str)
	{
		ptr = ft_strchr(str, '%');
		if (ptr && *(ptr + 1) != '\0')
		{
			count += ft_print_substr(str, ptr);
			str = ptr + 1;
			flags = ft_initialise_flags();
			format_spec = ft_parse_flags(&str, &flags);
			count += ft_print_argument(format_spec, args, &flags);
		}
		else
		{
			count += ft_putstr(str);
			break ;
		}
		str++;
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list		args;
	int			count;

	if (*format == '\0' || !format)
		return (0);
	count = 0;
	va_start(args, format);
	count = ft_parse(format, args);
	va_end(args);
	return (count);
}
