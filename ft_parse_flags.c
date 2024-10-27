/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natallia <natallia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 13:59:40 by nkhamich          #+#    #+#             */
/*   Updated: 2024/10/27 16:18:00 by natallia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_left_align(t_flags *flags)
{
	flags->left_align = 1;
	flags->zero_pad = 0;
}

static void	ft_get_precision(const char **ptr, t_flags *flags)
{
	(*ptr)++;
	flags->precision = 0;
	while (ft_isdigit(**ptr))
	{
		flags->precision = (flags->precision * 10) + (**ptr - '0');
		(*ptr)++;
	}
}

static void	ft_get_width(const char **ptr, t_flags *flags)
{
	while (ft_isdigit(**ptr))
	{
		flags->min_width = (flags->min_width * 10) + (**ptr - '0');
		(*ptr)++;
	}
}

char	ft_parse_flags(const char **ptr, t_flags *flags)
{
	while (**ptr && ft_is_flag(**ptr))
	{
		if (**ptr == '#')
			flags->alt_form = 1;
		else if (**ptr == ' ')
			flags->space = 1;
		else if (**ptr == '+')
			flags->force_sign = 1;
		else if (**ptr == '0' && !flags->left_align && !flags->min_width)
			flags->zero_pad = 1;
		else if (**ptr == '-')
			ft_left_align(flags);
		else if (**ptr == '.')
			ft_get_precision(ptr, flags);
		else if (ft_isdigit(**ptr))
			ft_get_width(ptr, flags);
		else if (ft_is_type(**ptr))
			break ;
	}
	return (**ptr);
}
