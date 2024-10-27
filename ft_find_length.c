/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_length.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natallia <natallia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 11:08:47 by natallia          #+#    #+#             */
/*   Updated: 2024/10/27 13:12:52 by natallia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hex_len(unsigned long int n)
{
	int	digit_count;

	digit_count = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 16;
		digit_count++;
	}
	return (digit_count);
}
