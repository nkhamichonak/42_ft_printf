/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhamich <nkhamich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 12:02:21 by nkhamich          #+#    #+#             */
/*   Updated: 2024/10/30 16:23:49 by nkhamich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// int	main(void)
// {
// 	int res_orig = printf("Printf: %190.*x%0.*d%016.d%161p\n" ,5,152679666u,181,1696359958,851636824,(void*)15444398714638691551lu);
// 	fflush(stdout);
// 	int res_custom = ft_printf("Custommm: %190.*x%0.*d%016.d%161p\n" ,5,152679666u,181,1696359958,851636824,(void*)15444398714638691551lu);
// 	printf("Printf return: %d; Custom return: %d\n", res_orig, res_custom);

// 	return (0);
// }

void	test_percent(void);
void	test_c(void);
void	test_s(void);
void	test_d(void);
void	test_i(void);
void	test_x(void);
void	test_X(void);
void	test_u(void);
void	test_p(void);
void	test_all(void);
void	test_bonus_char(void);
void	test_bonus_str(void);
void	test_bonus_hex(void);
void	test_bonus_unsigned(void);
void	test_bonus_int(void);
void	test_bonus_ptr(void);
void	test_bonus_precision(void);
// void	test_invalid_spec(void);

int	main(void)
{
	printf("\n\n========== MANDATORY TESTS ========\n\n");
	test_percent();
	test_c();
	test_s();
	test_d();
	test_i();
	test_x();
	test_X();
	test_u();
	test_p();
	test_all();

	printf("\n\n========== BONUS TESTS ============\n\n");
	test_bonus_char();
	test_bonus_str();
	test_bonus_hex();
	test_bonus_unsigned();
	test_bonus_int();
	test_bonus_ptr();
	test_bonus_precision();
	// test_invalid_spec();

	return (0);
}

void	test_percent(void)
{
	int	x;
	int	y;
	x = 0;
	y = 0;
	printf("\nTEST: percent\n\n");
	x += printf("Printf: %%%%\n");
	fflush(stdout);
	y += ft_printf("Custom: %%%%\n");
	printf("Printf = %d, ft_printf = %d\n\n", x, y);
	fflush(stdout);
}

void	test_c(void)
{
	int	x, y;
	x = 0;
	y = 0;
	printf("\nTEST: c\n\n");
	x += printf("Printf: %c\n", 'a');
	fflush(stdout);
	y += ft_printf("Custom: %c\n", 'a');
	printf("Printf = %d, ft_printf = %d\n\n", x, y);
	x = 0;
	y = 0;
	x += printf("Printf: The character %c is visible.\n", 'X');
	fflush(stdout);
	y += ft_printf("Custom: The character %c is visible.\n", 'X');
	printf("Printf = %d, ft_printf = %d\n\n", x, y);
}

void	test_s(void)
{
	int	x, y;
	x = 0;
	y = 0;
	printf("\nTEST: s\n\n");
	x += printf("Printf: %s\n", "Alpacas are awesome");
	fflush(stdout);
	y += ft_printf("Custom: %s\n", "Alpacas are awesome");
	printf("Printf = %d, ft_printf = %d\n\n", x, y);
	x = 0;
	y = 0;
	x += printf("Printf: The string \"%s\" is visible.\n", "DoNuTs");
	fflush(stdout);
	y += ft_printf("Custom: The string \"%s\" is visible.\n", "DoNuTs");
	printf("Printf = %d, ft_printf = %d\n\n", x, y);
}

void	test_d(void)
{
	int x, y;
	x = 0;
	y = 0;
	printf("\nTEST: d\n\n");
	x += printf("Printf: %d\n", 42);
	fflush(stdout);
	y += ft_printf("Custom: %d\n", 42);
	printf("Printf = %d, ft_printf = %d\n\n", x, y);
	x = 0;
	y = 0;
	x += printf("Printf: The number %d is visible.\n", 5671);
	fflush(stdout);
	y += ft_printf("Custom: The number %d is visible.\n", 5671);
	printf("Printf = %d, ft_printf = %d\n\n", x, y);
	x = 0;
	y = 0;
	x += printf("Printf: INT_MAX is %d\n", INT_MAX);
	fflush(stdout);
	y += ft_printf("Custom: INT_MAX is %d\n", INT_MAX);
	printf("Printf = %d, ft_printf = %d\n\n", x, y);
	x = 0;
	y = 0;
	x += printf("Printf: INT_MIN is %d\n", INT_MIN);
	fflush(stdout);
	y += ft_printf("Custom: INT_MIN is %d\n", INT_MIN);
	printf("Printf = %d, ft_printf = %d\n\n", x, y);
}

void	test_i(void)
{
	int x, y;
	printf("\nTEST: i\n\n");
	x = 0;
	y = 0;
	x += printf("Printf: %i\n", -424242);
	fflush(stdout);
	y += ft_printf("Custom: %i\n", -424242);
	printf("Printf = %d, ft_printf = %d\n\n", x, y);
	x = 0;
	y = 0;
	x += printf("Printf: Number %i is visible.\n", 0);
	fflush(stdout);
	y += ft_printf("Custom: Number %i is visible.\n", 0);
	printf("Printf = %d, ft_printf = %d\n\n", x, y);
}

void	test_x(void)
{
	int	x, y;
	x = 0;
	y = 0;
	printf("\nTEST: x\n\n");
	x += printf("Printf: %x\n", 42);
	fflush(stdout);
	y += ft_printf("Custom: %x\n", 42);
	printf("Printf = %d, ft_printf = %d\n\n", x, y);
	x = 0;
	y = 0;
	x += printf("Printf: The hex number %x is visible.\n", 67892);
	fflush(stdout);
	y += ft_printf("Custom: The hex number %x is visible.\n", 67892);
	printf("Printf = %d, ft_printf = %d\n\n", x, y);
	x = 0;
	y = 0;
	x += printf("Printf: INT_MAX is %x\n", INT_MAX);
	fflush(stdout);
	y += ft_printf("Custom: INT_MAX is %x\n", INT_MAX);
	printf("Printf = %d, ft_printf = %d\n\n", x, y);
	x = 0;
	y = 0;
	x += printf("Printf: INT_MIN is %x\n", INT_MIN);
	fflush(stdout);
	y += ft_printf("Custom: INT_MIN is %x\n", INT_MIN);
	printf("Printf = %d, ft_printf = %d\n\n", x, y);
}

void	test_X(void)
{
	int	x, y;
	x = 0;
	y = 0;
	printf("\nTEST: X\n\n");
	x += printf("Printf: %X\n", 42);
	fflush(stdout);
	y += ft_printf("Custom: %X\n", 42);
	printf("Printf = %d, ft_printf = %d\n\n", x, y);
	x = 0;
	y = 0;
	x += printf("Printf: The hex number %X is visible.\n", 67892);
	fflush(stdout);
	y += ft_printf("Custom: The hex number %X is visible.\n", 67892);
	printf("Printf = %d, ft_printf = %d\n\n", x, y);
	x = 0;
	y = 0;
	x += printf("Printf: INT_MAX is %X\n", INT_MAX);
	fflush(stdout);
	y += ft_printf("Custom: INT_MAX is %X\n", INT_MAX);
	printf("Printf = %d, ft_printf = %d\n\n", x, y);
	x = 0;
	y = 0;
	x += printf("Printf: INT_MIN is %X\n", INT_MIN);
	fflush(stdout);
	y += ft_printf("Custom: INT_MIN is %X\n", INT_MIN);
	printf("Printf = %d, ft_printf = %d\n\n", x, y);
}

void	test_u(void)
{
	int	x, y;
	x = 0;
	y = 0;
	printf("\nTEST: u\n\n");
	x += printf("Printf: %u\n", 42);
	fflush(stdout);
	y += ft_printf("Custom: %u\n", 42);
	printf("Printf = %d, ft_printf = %d\n\n", x, y);
	x = 0;
	y = 0;
	x += printf("Printf: The number %u is visible.\n", 56871);
	fflush(stdout);
	y += ft_printf("Custom: The number %u is visible.\n", 56871);
	printf("Printf = %d, ft_printf = %d\n\n", x, y);
	x = 0;
	y = 0;
	x += printf("Printf: INT_MAX is %u\n", INT_MAX);
	fflush(stdout);
	y += ft_printf("Custom: INT_MAX is %u\n", INT_MAX);
	printf("Printf = %d, ft_printf = %d\n\n", x, y);
	x = 0;
	y = 0;
	x += printf("Printf: INT_MIN is %u\n", INT_MIN);
	fflush(stdout);
	y += ft_printf("Custom: INT_MIN is %u\n", INT_MIN);
	printf("Printf = %d, ft_printf = %d\n\n", x, y);
	x = 0;
	y = 0;
	x += printf("Printf: -42 is %u\n", -42);
	fflush(stdout);
	y += ft_printf("Custom: -42 is %u\n", -42);
	printf("Printf = %d, ft_printf = %d\n\n", x, y);
	x = 0;
	y = 0;
	x += printf("Printf: UINT_MAX is %u\n", UINT_MAX);
	fflush(stdout);
	y += ft_printf("Custom: UINT_MAX is %u\n", UINT_MAX);
	printf("Printf = %d, ft_printf = %d\n\n", x, y);
}

void	test_p(void)
{
	int	x, y;
	printf("\nTEST: p\n\n");
	x = 0;
	y = 0;
	int		n;
	char	c;
	void	*p;

	n = 50;
	c = 'a';
	p = NULL;
	x += printf("Printf: %p\n", (void *)&n);
	fflush(stdout);
	y += ft_printf("Custom: %p\n", (void *)&n);
	printf("Printf = %d, ft_printf = %d\n\n", x, y);
	x = 0;
	y = 0;
	x += printf("Printf: %p\n", (void *)&c);
	fflush(stdout);
	y += ft_printf("Custom: %p\n", (void *)&c);
	printf("Printf = %d, ft_printf = %d\n\n", x, y);
	x = 0;
	y = 0;
	x += printf("Printf: %p\n", p);
	fflush(stdout);
	y += ft_printf("Custom: %p\n", p);
	printf("Printf = %d, ft_printf = %d\n\n", x, y);
}

void	test_all(void)
{
	int	x, y;
	x = 0;
	y = 0;
	printf("\nTEST: ALL\n\n");
	x += printf("Printf: The int is %i or %d, the char is %c, the string is \"%s\", the hex is %x or %X, the unsigned is %u and the percent is %%.\n", 42, -42, 'P', "Alpaca", 42, 42, 242);
	fflush(stdout);
	y += ft_printf("Printf: The int is %i or %d, the char is %c, the string is \"%s\", the hex is %x or %X, the unsigned is %u and the percent is %%.\n", 42, -42, 'P', "Alpaca", 42, 42, 242);
	printf("Printf = %d, ft_printf = %d\n\n", x, y);
}

void	test_bonus_char(void)
{
	int	x, y;
	x = 0;
	y = 0;
	printf("\nTEST: WIDTH CHAR\n\n");
	x = printf("Printf: Char [%20c]\n", 'x');
	fflush(stdout);
	y = ft_printf("Custom: Char [%20c]\n", 'x');
	printf("Printf = %d, ft_printf = %d\n\n", x, y);
	
	x = printf("Printf: Char [%-20c]\n", 'x');
	fflush(stdout);
	y = ft_printf("Custom: Char [%-20c]\n", 'x');
	printf("Printf = %d, ft_printf = %d\n\n", x, y);

	x = printf("Printf: Char [%*c]\n", 8, 'x');
	fflush(stdout);
	y = ft_printf("Custom: Char [%*c]\n", 8, 'x');
	printf("Printf = %d, ft_printf = %d\n\n", x, y);

	printf("\nTEST: WIDTH %%\n\n");
	x = printf("Printf: Char [%20%]\n");
	fflush(stdout);
	y = ft_printf("Custom: Char [%20%]\n");
	printf("Printf = %d, ft_printf = %d\n\n", x, y);

	x = printf("Printf: Char [%0*%]\n", 8);
	fflush(stdout);
	y = ft_printf("Custom: Char [%0*%]\n", 8);
	printf("Printf = %d, ft_printf = %d\n\n", x, y);
}

void	test_bonus_str(void)
{
	int x, y;

	printf("\nTEST: WIDTH STR\n\n");
	x = printf("Printf: String [%-25s]\n", "Hello!");
	fflush(stdout);
	y = ft_printf("Custom: String [%-25s]\n", "Hello!");
	printf("Printf = %d, ft_printf = %d\n\n", x, y);

	x = printf("Printf: String [%*s]\n", 20, "Hello!");
	fflush(stdout);
	y = ft_printf("Custom: String [%*s]\n", 20, "Hello!");
	printf("Printf = %d, ft_printf = %d\n\n", x, y);

	x = printf("Printf: String [%1s]\n", "Hello World!");
	fflush(stdout);
	y = ft_printf("Custom: String [%1s]\n", "Hello World!");
	printf("Printf = %d, ft_printf = %d\n\n", x, y);
}

void	test_bonus_hex(void)
{
	int x, y;

	printf("\nTEST: SHARP HEX\n\n");
	x = printf("Printf: Number [%#x]\n", 0);
	fflush(stdout);
	y = ft_printf("Custom: Number [%#x]\n", 0);
	printf("Printf = %d, ft_printf = %d\n\n", x, y);

	x = printf("Printf: Number [%#x]\n", 42);
	fflush(stdout);
	y = ft_printf("Custom: Number [%#x]\n", 42);
	printf("Printf = %d, ft_printf = %d\n\n", x, y);

	printf("\nTEST: WIDTH HEX\n\n");
	x = printf("Printf: Number [%*x]\n", 10, 42);
	fflush(stdout);
	y = ft_printf("Custom: Number [%*x]\n",10, 42);
	printf("Printf = %d, ft_printf = %d\n\n", x, y);

	x = printf("Printf: Number [%20X]\n", 42);
	fflush(stdout);
	y = ft_printf("Custom: Number [%20X]\n", 42);
	printf("Printf = %d, ft_printf = %d\n\n", x, y);

	x = printf("Printf: Number [%0*X]\n", 20, 42);
	fflush(stdout);
	y = ft_printf("Custom: Number [%0*X]\n", 20, 42);
	printf("Printf = %d, ft_printf = %d\n\n", x, y);

	printf("\nTEST: WIDTH SHARP HEX\n\n");
	x = printf("Printf: Number [%#*x]\n", 10, 42);
	fflush(stdout);
	y = ft_printf("Custom: Number [%#*x]\n", 10, 42);
	printf("Printf = %d, ft_printf = %d\n\n", x, y);

	x = printf("Printf: Number [%#0*x]\n", 10, 42);
	fflush(stdout);
	y = ft_printf("Custom: Number [%#0*x]\n",10, 42);
	printf("Printf = %d, ft_printf = %d\n\n", x, y);
}

void	test_bonus_unsigned(void)
{
	int x, y;

	printf("\nTEST: WIDTH UNSIGNED\n\n");
	x = printf("Printf: Number [%20u]\n", 42);
	fflush(stdout);
	y = ft_printf("Custom: Number [%20u]\n", 42);
	printf("Printf = %d, ft_printf = %d\n\n", x, y);

	x = printf("Printf: Number [%-15u]\n", 42);
	fflush(stdout);
	y = ft_printf("Custom: Number [%-15u]\n", 42);
	printf("Printf = %d, ft_printf = %d\n\n", x, y);

	x = printf("Printf: Number [%0*u]\n", 10, 42);
	fflush(stdout);
	y = ft_printf("Custom: Number [%0*u]\n", 10, 42);
	printf("Printf = %d, ft_printf = %d\n\n", x, y);
}

void	test_bonus_int(void)
{
	int x, y;

	printf("\nTEST: WIDTH INT\n\n");
	x = printf("Printf: Number [%20i]\n", 42);
	fflush(stdout);
	y = ft_printf("Custom: Number [%20i]\n", 42);
	printf("Printf = %d, ft_printf = %d\n\n", x, y);

	x = printf("Printf: Number [%0*i]\n", 8, 42);
	fflush(stdout);
	y = ft_printf("Custom: Number [%0*i]\n", 8, 42);
	printf("Printf = %d, ft_printf = %d\n\n", x, y);

	x = printf("Printf: Number [%0*i]\n", 8, -42);
	fflush(stdout);
	y = ft_printf("Custom: Number [%0*i]\n", 8, -42);
	printf("Printf = %d, ft_printf = %d\n\n", x, y);

	x = printf("Printf: Number [%*i]\n", 8, -42);
	fflush(stdout);
	y = ft_printf("Custom: Number [%*i]\n", 8, -42);
	printf("Printf = %d, ft_printf = %d\n\n", x, y);

	printf("\nTEST: ZERO INT\n\n");
	x = printf("Printf: Number [%011i]\n", (int)LONG_MAX);
	fflush(stdout);
	y = ft_printf("Custom: Number [%011i]\n", LONG_MAX);
	printf("Printf = %d, ft_printf = %d\n\n", x, y);

	x = printf("Printf: Number [%010d]\n", INT_MIN);
	fflush(stdout);
	y = ft_printf("Custom: Number [%010d]\n", INT_MIN);
	printf("Printf = %d, ft_printf = %d\n\n", x, y);

	printf("\nTEST: SPACE INT\n\n");
	x = printf("Printf: Number [% 0*i]\n", 8, 42);
	fflush(stdout);
	y = ft_printf("Custom: Number [% 0*i]\n", 8, 42);
	printf("Printf = %d, ft_printf = %d\n\n", x, y);
	
	x = printf("Printf: Number [% 0*i]\n", 8, -42);
	fflush(stdout);
	y = ft_printf("Custom: Number [% 0*i]\n", 8, -42);
	printf("Printf = %d, ft_printf = %d\n\n", x, y);

	x = printf("Printf: Number [%- *i]\n", 8, 42);
	fflush(stdout);
	y = ft_printf("Custom: Number [%- *i]\n", 8, 42);
	printf("Printf = %d, ft_printf = %d\n\n", x, y);

	printf("\nTEST: PLUS INT\n\n");
	x = printf("Printf: Number [%+0*i]\n", 8, 42);
	fflush(stdout);
	y = ft_printf("Custom: Number [%+0*i]\n", 8, 42);
	printf("Printf = %d, ft_printf = %d\n\n", x, y);

	x = printf("Printf: Number [%+*i]\n", 8, 42);
	fflush(stdout);
	y = ft_printf("Custom: Number [%+*i]\n", 8, 42);
	printf("Printf = %d, ft_printf = %d\n\n", x, y);
}

void	test_bonus_ptr(void)
{
	int x, y;

	printf("\nTEST: LEFT ALIGN PTR\n\n");
	x = printf("Printf: Pointer [%-15p]\n", &x);
	fflush(stdout);
	y = ft_printf("Custom: Pointer [%-15p]\n", &x);
	printf("Printf = %d, ft_printf = %d\n\n", x, y);

	x = printf("Printf: Pointer [%-20p]\n", &y);
	fflush(stdout);
	y = ft_printf("Custom: Pointer [%-20p]\n", &y);
	printf("Printf = %d, ft_printf = %d\n\n", x, y);

	x = printf("Printf: Pointer [%-15p]\n", (void *)0);
	fflush(stdout);
	y = ft_printf("Custom: Pointer [%-15p]\n", (void *)0);
	printf("Printf = %d, ft_printf = %d\n\n", x, y);
}

void	test_bonus_precision(void)
{
	int x, y;

	printf("\nTEST: PRECISION STRING\n\n");
	x = printf("Printf: String, no prec: [%s]\n", "0123456789");
	fflush(stdout);
	y = ft_printf("Custom: String, no prec: [%s]\n", "0123456789");
	printf("Printf = %d, ft_printf = %d\n\n", x, y);

	x = printf("Printf: String, prec 6: [%.6s]\n", "0123456789");
	fflush(stdout);
	y = ft_printf("Custom: String, prec 6: [%.6s]\n", "0123456789");
	printf("Printf = %d, ft_printf = %d\n\n", x, y);

	x = printf("Printf: String, prec 15: [%.15s]\n", "0123456789");
	fflush(stdout);
	y = ft_printf("Custom: String, prec 15: [%.15s]\n", "0123456789");
	printf("Printf = %d, ft_printf = %d\n\n", x, y);

	x = printf("Printf: String, prec 0: [%.0s]\n", "0123456789");
	fflush(stdout);
	y = ft_printf("Custom: String, prec 0: [%.0s]\n", "0123456789");
	printf("Printf = %d, ft_printf = %d\n\n", x, y);

	printf("\nTEST: PRECISION INT\n\n");
	x = printf("Printf: Int, no prec: [%d]\n", 42424242);
	fflush(stdout);
	y = ft_printf("Custom: Int, no prec: [%d]\n", 42424242);
	printf("Printf = %d, ft_printf = %d\n\n", x, y);

	x = printf("Printf: Int, prec 2: [%.2d]\n", 42424242);
	fflush(stdout);
	y = ft_printf("Custom: Int, prec 2: [%.2d]\n", 42424242);
	printf("Printf = %d, ft_printf = %d\n\n", x, y);

	x = printf("Printf: Int, prec 42: [%.42d]\n", 42424242);
	fflush(stdout);
	y = ft_printf("Custom: Int, prec 42: [%.42d]\n", 42424242);
	printf("Printf = %d, ft_printf = %d\n\n", x, y);
}

// void	test_invalid_spec(void)
// {
// 	int x, y;

// 	x = 0;
// 	y = 0;
// 	printf("\nTEST: INVALID TYPE\n\n");

// 	x = printf("Printf: Invalid: [%%w] = [%w]\n");
// 	fflush(stdout);
// 	y = ft_printf("Custom: Invalid: [%%w] = [%w]\n");
// 	printf("\nPrintf = %d, ft_printf = %d\n\n", x, y);

// 	x = printf("Printf: Invalid: [%%0] = [%0]\n");
// 	fflush(stdout);
// 	y = ft_printf("Custom: Invalid: [%%0] = [%0]\n");
// 	printf("Printf = %d, ft_printf = %d\n\n", x, y);

// 	x = printf("Printf: Invalid: [%%14k] = [%14k]\n");
// 	fflush(stdout);
// 	y = ft_printf("Custom: Invalid: [%%14k] = [%14k]\n");
// 	printf("Printf = %d, ft_printf = %d\n\n", x, y);

// 	x = printf("Printf: Invalid: [%%-14k] = [%-14k]\n");
// 	fflush(stdout);
// 	y = ft_printf("Custom: Invalid: [%%-14k] = [%-14k]\n");
// 	printf("Printf = %d, ft_printf = %d\n\n", x, y);

// 	x = printf("Printf: Invalid: [%%wawa] = [%wawa]\n");
// 	fflush(stdout);
// 	y = ft_printf("Custom: Invalid: [%%wawa] = [%wawa]\n");
// 	printf("Printf = %d, ft_printf = %d\n\n", x, y);
// }
