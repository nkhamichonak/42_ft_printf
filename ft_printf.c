/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhamich <nkhamich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 12:08:40 by nkhamich          #+#    #+#             */
/*   Updated: 2024/10/23 13:16:29 by nkhamich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "libft.h"

void	print_substr(const char *str, const char *ptr)
{
	char		*temp;

	temp = ft_substr(str, 0, (ptr - str));
	if (temp == NULL)
	{
		ft_putstr_fd("Allocation error in print_substr\n", 2);
		return ;
	}
	ft_putstr_fd(temp, 1);
	free (temp);
}

void	parse(const char *str, va_list args, int *count)
{
	t_flags		*flags;
	char		*ptr;

	ptr = str;

	while (*str)
	{
		ptr = ft_strchr(str, '%');
		if (ptr && *(ptr + 1) != '\0')
		{
			print_substr(str, ptr);
			parse_flags(&ptr + 1, flags);
			// function to establish conversion specifier & print the arg
		}
		else
		{
			ft_putchar_fd(*str, 1);
			(*count)++;
			str++;
		}
		// p++
	}
}

int	ft_printf(const char *format, ...)
{
	va_list		args;
	int			count;

	if (*format == '\0' || !format)
		return (0);
	count = 0;
	va_start(args, format);
	ft_parse(format, args, &count);
	va_end(args);
	return (count);
}
