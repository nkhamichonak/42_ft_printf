/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natallia <natallia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 13:27:20 by natallia          #+#    #+#             */
/*   Updated: 2024/10/27 14:02:15 by natallia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags	ft_initialise_flags(void)
{
	t_flags	flags;

	flags.left_align = 0;
	flags.zero_pad = 0;
	flags.precision = 0;
	flags.min_width = 0;
	flags.alt_form = 0;
	flags.space = 0;
	flags.force_sign = 0;
	flags.precision = -1;
	return (flags);
}

int	ft_is_flag(int c)
{
	if (c == '%' || ft_is_specifier(c) || ft_is_type(c) || ft_isdigit(c))
		return (1);
	return (0);
}

int	ft_is_specifier(int c)
{
	if (c == '-' || c == '0' || c == '.' || c == '*'
		|| c == '#' || c == ' ' || c == '+')
		return (1);
	return (0);
}

int	ft_is_type(int c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i'
		|| c == 'u' || c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}
