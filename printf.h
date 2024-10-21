/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhamich <nkhamich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 13:29:14 by nkhamich          #+#    #+#             */
/*   Updated: 2024/10/21 14:38:03 by nkhamich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

#include <stdarg.h>
#include <stdio.h>

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

#endif
