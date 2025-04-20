# 42 Printf

This project is a re-creation of the C standard library `printf` function, built from scratch to handle a subset of data type conversions and format specifiers. It introduces a key programming concept — **variadic functions** — and serves as a solid first exercise in low-level logic, data structures, and manual parsing.

## Status

- ✅ Validated: 01.11.2024.
- 🎓 Grade: 125/100.
- 🚦 Compliant with [42 Norm](#note) rules.

## Project Requirements

### Basic

`ft_printf` must not implement the original `printf`’s buffer management. It needs to support the following conversions:

| Specifier | Description                                                                 |
|-----------|-----------------------------------------------------------------------------|
| `%c`      | Prints a single character.                                                  |
| `%s`      | Prints a string (as defined by the common C convention).                   |
| `%p`      | Prints a `void *` pointer in hexadecimal format.                           |
| `%d`      | Prints a signed decimal (base 10) number.                                   |
| `%i`      | Prints a signed integer in base 10.                                         |
| `%u`      | Prints an unsigned decimal (base 10) number.                                |
| `%x`      | Prints a number in lowercase hexadecimal (base 16) format.                 |
| `%X`      | Prints a number in uppercase hexadecimal (base 16) format.                 |
| `%%`      | Prints a percent sign.                                                      |

### Advanced

The extended version of `ft_printf` can handle multiple format specifiers in any combination. These are optional and follow the format: `%[flags][width][.precision]specifier`.

The supported format specifiers are:

#### Flags

| Flag   | Description |
|--------|-------------|
| `-`    | Left-aligns the output within the given width. By default, content is right-aligned. |
| `+`    | Forces a plus sign (`+`) in front of positive numbers. Normally, only negative numbers get a sign. |
| (space) | Adds a space before positive numbers if no sign is going to be printed. Ignored if `+` is used. |
| `#`    | Alters output for certain conversions: adds `0x`/`0X` prefix for hex (`%x`, `%X`) if the value isn’t zero. |
| `0`    | Pads numeric output with leading zeros instead of spaces (ignored if `-` is present). |

#### Width

| Value     | Description |
|-----------|-------------|
| `(number)` | Sets the minimum number of characters to print. If the output is shorter, it's padded with spaces. No truncation happens if it's longer. |
| `*`       | Width is passed as an argument instead of being hardcoded in the format string. |

#### Precision

| Value     | Description |
|-----------|-------------|
| `.(number)` | - For `%d`, `%i`, `%u`, `%x`, `%X`: sets the minimum number of digits. Pads with leading zeros if needed. If the number is 0 and precision is 0, nothing is printed. <br> - For `%s`: sets the max number of characters to print. <br> - Has no effect for `%c`. |
| `.(*)`       | Precision is passed as an argument rather than being defined in the format string.


## Usage

`ft_printf` is not a standalone program — it’s a library you use inside your own C programs.

Use `make` or `make bonus` to compile the library.

Compile your `main.c` file with the `ft_printf` library and run the program:

```
cc main.c libftprintf.a && ./a.out
```

Example `main.c`:

``` c
#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int		num = 42;
	char		c = 'A';
	char		*str = "Hello, world!";
	unsigned int	u = 4294967295;
	void		*ptr = &num;

	ft_printf("Custom ft_printf:\n");
	ft_printf("Char: %c\n", c);
	ft_printf("String: %s\n", str);
	ft_printf("Pointer: %p\n", ptr);
	ft_printf("Decimal: %d\n", num);
	ft_printf("Integer: %i\n", num);
	ft_printf("Unsigned: %u\n", u);
	ft_printf("Hex (lower): %x\n", num);
	ft_printf("Hex (upper): %X\n", num);
	ft_printf("Percent: %%\n");
	ft_printf("Right-aligned (default): |%10d|\n", num);
	ft_printf("Left-aligned with '-':   |%-10d|\n", num);
	ft_printf("Zero-padded with '0':    |%010d|\n", num);
	ft_printf("Width from arg:          |%*s|\n", 8, "Hi");
	ft_printf("Precision + width:       |%10.5d|\n", 42);
	ft_printf("Hash flag with HEX:      |%#X|\n", 42);

	printf("\nStandard printf:\n");
	printf("Char: %c\n", c);
	printf("String: %s\n", str);
	printf("Pointer: %p\n", ptr);
	printf("Decimal: %d\n", num);
	printf("Integer: %i\n", num);
	printf("Unsigned: %u\n", u);
	printf("Hex (lower): %x\n", num);
	printf("Hex (upper): %X\n", num);
	printf("Percent: %%\n");
	printf("Right-aligned (default): |%10d|\n", num);
	printf("Left-aligned with '-':   |%-10d|\n", num);
	printf("Zero-padded with '0':    |%010d|\n", num);
	printf("Width from arg:          |%*s|\n", 8, "Hi");
	printf("Precision + width:       |%10.5d|\n", 42);
	printf("Hash flag with HEX:      |%#X|\n", 42);

	return (0);
}
```

This lets you compare the custom `ft_printf` implementation with the standard `printf` and verify output accuracy.


### Constraints

<a id="note"></a>

> 🛠️ **Note:**
> 42 project requirements that impact structure and readability:
> - Functions must be no longer than 25 lines.
> - A file may contain a maximum of 5 functions.
> - `for`, `do..while`, `switch`, ternary operators, and VLAs are forbidden.
> - Standard C library functions are not allowed (unless a few specific ones are explicitly permitted for a project).
> - Variables cannot be declared and assigned in the same line.

⚠️ P.S. Don't copy, learn!

Made by: nkhamich@student.codam.nl | LinkedIn: [nkhamichonak](https://www.linkedin.com/in/nkhamichonak/)
