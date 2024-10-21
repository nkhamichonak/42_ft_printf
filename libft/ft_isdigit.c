/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhamich <nkhamich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 15:37:16 by nkhamich          #+#    #+#             */
/*   Updated: 2024/10/17 11:55:51 by nkhamich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

// int main(void)
// {
// 	printf("'g' | libft: %d; ctype: %d; "
// 			"expected: 0\n", ft_isdigit('g'), isdigit('g'));
// 	printf("'A' | libft: %d; ctype: %d; "
// 			"expected: 0\n", ft_isdigit('A'), isdigit('A'));
// 	printf("' ' | libft: %d; ctype: %d; "
// 			"expected: 0\n", ft_isdigit(' '), isdigit(' '));
// 	printf("'5' | libft: %d; ctype: %d; "
// 			"expected: non-zero\n", ft_isdigit('5'), isdigit('5'));
// 	printf("'0' | libft: %d; ctype: %d; "
// 			"expected: non-zero\n", ft_isdigit('0'), isdigit('0'));
// 	printf(" -1 | libft: %d; ctype: %d; "
// 			"expected: 0\n", ft_isdigit(-1), isdigit(-1));
// 	printf("200 | libft: %d; ctype: %d; "
// 			"expected: 0\n", ft_isdigit(200), isdigit(200));
// 	return (0);
// }