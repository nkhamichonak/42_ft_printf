/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhamich <nkhamich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:28:18 by nkhamich          #+#    #+#             */
/*   Updated: 2024/10/22 16:43:22 by nkhamich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "libft.h"

void	get_conv_specifier(char **ptr, t_flags *flags)
{
	char	p;

	p = **ptr;
	if (p == 'c' || p == 's' || p == 'p' || p == 'd' || p == 'i' || p == 'u'
		|| p == 'x' || p == 'X' || p == '%')
	{
		if (p == 'c')
			//print character
		if (p == 's')
			//print string
		if (p == 'p')
			//print pointer
		if (p == 'd')
			//print decimal
		if (p == 'i')
			//print int in base 10
		if (p == 'u')
			//print unsigned decimal base 10
		if (p == 'x')
			//print in lowercase hexadecimal
		if (p == 'X')
			//print in uppercase hexadecimal
		if (p == '%')
			ft_putchar_fd('%', 1);
		*ptr++;
	}
	else 
}

• %c Prints a single character.
• %s Prints a string (as defined by the common C convention).
• %p The void * pointer argument has to be printed in hexadecimal format.
• %d Prints a decimal (base 10) number.
• %i Prints an integer in base 10.
• %u Prints an unsigned decimal (base 10) number.
• %x Prints a number in hexadecimal (base 16) lowercase format.
• %X Prints a number in hexadecimal (base 16) uppercase format.
• %% Prints a percent sign.