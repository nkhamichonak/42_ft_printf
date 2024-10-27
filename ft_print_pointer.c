/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natallia <natallia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 10:59:07 by natallia          #+#    #+#             */
/*   Updated: 2024/10/27 13:13:31 by natallia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_pointer(void *ptr, t_flags *flags)
{
	int					count;
	int					len;
	char				*ptr_str;
	unsigned long int	address;

	count = 0;
	address = (unsigned long int) ptr;
	if (address == 0)
		return (ft_putstr("(nil)"));
	len = 2 + ft_hex_len(address);
	if (!flags->left_align)
		count += ft_fill_width(flags->min_width, flags->zero_pad, len);
	ptr_str = ft_hextoa(address);
	if (ptr_str == NULL)
		return (0);
	count += ft_putstr("0x") + ft_putstr(ptr_str);
	if (flags->left_align)
		count += ft_fill_width(flags->min_width, 0, len);
	free (ptr_str);
	return (count);
}
