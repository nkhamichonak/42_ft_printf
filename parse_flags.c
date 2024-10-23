/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhamich <nkhamich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 13:59:40 by nkhamich          #+#    #+#             */
/*   Updated: 2024/10/23 17:50:20 by nkhamich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "libft.h"

int	is_flag(int c)
{
	if (is_specifier(c) || is_type(c) || is_digit(c))
		return (1);
	return (0);

}

int	is_specifier(int c)
{
	if (c == '-' || c == '0' || c == '.' || c == '*'
		|| c == '#' || c == ' ' || c == '+')
		return (1);
	return (0);
}

int	is_type(int c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i'
		|| c == 'u' || c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}

void	left_align_n_override(t_flags *flags)
{
	flags->left_align = 1;
	flags->zero_pad = 0;
}

void	get_precision(char **ptr, t_flags *flags)
{
	(*ptr)++;
	flags->precision = 0;
	while (is_digit(**ptr))
	{
		flags->precision = (flags->precision * 10) + (**ptr - '0');
		(*ptr)++;
	}
}

void	parse_flags(char **ptr, t_flags *flags)
{
	ft_memset(flags, 0, sizeof(flags));
	flags->precision = -1;
	while (**ptr && is_flag(**ptr))
	{
		if (**ptr == '#')
			flags->alt_form = 1;
		if (**ptr == '0')
			flags->zero_pad = 1;
		if (**ptr == '-')
			left_align_n_override(flags);
		if (**ptr == ' ')
			flags->space = 1;
		if (**ptr == '+')
			flags->force_sign = 1;
		if (**ptr == '.')
			get_precision(ptr, flags);
		(*ptr)++;
	}
	// while (**ptr >= '0' && **ptr <= '9')
	// {
	// 	flags->min_width = (flags->min_width * 10) + (**ptr - '0');
	// 	(*ptr)++;
	// }
}
