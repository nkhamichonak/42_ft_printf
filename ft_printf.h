/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natallia <natallia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 13:29:14 by nkhamich          #+#    #+#             */
/*   Updated: 2024/10/27 13:28:29 by natallia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <limits.h>
# include <stdio.h>
# include "libft/libft.h"

typedef struct s_flags
{
	int	left_align;
	int	zero_pad;
	int	precision;
	int	min_width;
	int	alt_form;
	int	space;
	int	force_sign;
}	t_flags;

// FLAGS
t_flags	ft_initialise_flags(void);
char	ft_parse_flags(const char **ptr, t_flags *flags);
int		ft_is_flag(int c);
int		ft_is_specifier(int c);
int		ft_is_type(int c);

// PRINT SPECIFIERS
int		ft_print_char(int c, t_flags *flags);
int		ft_print_hex(unsigned int num, t_flags *flags, int upper_case);
int		ft_print_int(int num, t_flags *flags);
int		ft_print_pointer(void *ptr, t_flags *flags);
int		ft_print_string(const char *str, t_flags *flags);
int		ft_print_unsigned(unsigned int num, t_flags *flags);

// HELPER FUNCTIONS
int		ft_putchar(unsigned char c);
int		ft_putstr(const char *s);
int		ft_fill_width(int min_width, int zero_pad, int size);
int		ft_hex_len(unsigned long int n);
char	*ft_hextoa(unsigned long int num);
int		ft_printf(const char *format, ...);

#endif
