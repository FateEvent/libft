/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fab <faventur@student.42mulhouse.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 15:00:26 by faventur          #+#    #+#             */
/*   Updated: 2026/03/10 10:11:14 by fab              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	manage_specs(t_specs *specs, char *str, long long value)
{
	size_t  len;

	if (!str || !specs)
		return (0);

	// 1. DETERMINE THE PREFIX FIRST
	specs->prefix = ""; // Default
	if (specs->format_flag == 'd' || specs->format_flag == 'i')
	{
		if (value < 0)
			specs->prefix = "-";
		else if (specs->plus_flag)
			specs->prefix = "+";
		else if (specs->space_flag)
			specs->prefix = " ";
	}
	else if (specs->hash_flag && value != 0)
	{
		if (specs->format_flag == 'x')
			specs->prefix = "0x";
		else if (specs->format_flag == 'X')
			specs->prefix = "0X";
		else if (specs->format_flag == 'o')
			specs->prefix = "0";
	}
	else if (specs->format_flag == 'p')
		specs->prefix = "0x";

	specs->prefix_size = ft_strlen(specs->prefix);

	// 2. REST OF YOUR LOGIC (Precision and Width)
	len = ft_strlen(str);

	// Case value 0 and precision 0
	if (specs->has_precision && specs->precision == 0 && value == 0)
		len = 0;

	// Precision zeros (don't subtract prefix_size here!)
	if (specs->precision > len && specs->format_flag != 's')
		specs->precision_zeroes = specs->precision - len;
	else
		specs->precision_zeroes = 0;

	// Width padding (subtract EVERYTHING here)
	int total_occupied = specs->prefix_size + specs->precision_zeroes + len;
	if (specs->width > (size_t)total_occupied)
		specs->width = specs->width - total_occupied;
	else
		specs->width = 0;

	// Pad character logic...
	if (specs->zero_pad)
		specs->pad_char = '0';
	else
		specs->pad_char = ' ';
	return (1);
}

int	print_n_chars(char c, int n, int fd)
{
	int	i;

	i = 0;
	while (i < n)
	{
		ft_putchar_fd(c, fd);
		i++;
	}
	return (i); // Très utile pour ton return final de ft_printf
}

int	write_formatted_output(char *str, t_specs specs, int fd)
{
	size_t	count;
	size_t	len;
	size_t	index;

	count = 0;
	index = 0;
	len = ft_strlen(str);
	// Adjust len for the special case: value 0 and precision 0
	if (specs.has_precision && specs.precision == 0 && !ft_strncmp(str, "0", 1))
		len = 0;

	// 1. RIGHT ALIGNMENT: Print spaces first (if not left-justified)
	if (!specs.left_justify && specs.pad_char == ' ')
		count += print_n_chars(' ', specs.width, fd);

	// 2. THE PREFIX: Print '-', '+', ' ', or '0x'
	if (specs.prefix_size > 0 && ft_strncmp(specs.prefix, str, specs.prefix_size))
		count += write(fd, specs.prefix, specs.prefix_size);
	else if (specs.prefix_size > 0 && !ft_strncmp(specs.prefix, str, specs.prefix_size)) {
		count += write(fd, specs.prefix, specs.prefix_size);
		index = specs.prefix_size;
	}

	// 3. ZERO PADDING: Print '0' from either width (if flag 0) or precision
	if (!specs.left_justify && specs.pad_char == '0')
		count += print_n_chars('0', specs.width, fd);
	count += print_n_chars('0', specs.precision_zeroes, fd);

	// 4. THE CONTENT: Print the actual digits
	if (len > 0)
		count += write(fd, &str[index], len);

	// 5. LEFT ALIGNMENT: Print spaces last (if left-justified)
	if (specs.left_justify)
		count += print_n_chars(' ', specs.width, fd);

	return (count);
}

int	handle_string(char *str, t_specs specs, int fd)
{
	int count = 0;
	if (!str) str = "(null)";

	size_t len = ft_strlen(str);
	
	// For %s, precision is the MAXIMUM length
	if (specs.has_precision && specs.precision < len)
		len = specs.precision;

	size_t spaces = (specs.width > len) ? specs.width - len : 0;

	if (!specs.left_justify)
		count += print_n_chars(' ', spaces, fd);
	count += write(1, str, len);
	if (specs.left_justify)
		count += print_n_chars(' ', spaces, fd);

	return (count);
}

int handle_char(char c, t_specs specs, int fd)
{
	int count = 0;
	int spaces = (specs.width > 1) ? specs.width - 1 : 0;

	if (!specs.left_justify)
		count += print_n_chars(' ', spaces, fd);
	
	count += write(fd, &c, 1);
	
	if (specs.left_justify)
		count += print_n_chars(' ', spaces, fd);
		
	return (count);
}

int handle_alpha(va_list arg_p, int fd, char flag, t_specs specs)
{
	if (flag == 'c')
		return (handle_char(va_arg(arg_p, int), specs, fd));
	if (flag == 's')
		return (handle_string(va_arg(arg_p, char *), specs, fd));
	if (flag == '%')
		return (handle_char('%', specs, fd)); // Le % est traité comme un char
	return (0);
}

int handle_digit(va_list arg_p, int fd, char flag, t_specs specs)
{
	char      *str;
	int       count;
	long long val; // long long pour gérer INT_MIN proprement

	specs.format_flag = flag;
	if (flag == 'u')
		val = va_arg(arg_p, unsigned int);
	else
		val = va_arg(arg_p, int);

	// On génère la string SANS le signe (on gérera le signe via le préfixe)
	if (val < 0)
		str = ft_utoa_base(-val, "0123456789");
	else
		str = ft_utoa_base(val, "0123456789");

	// On prépare les specs (calcul du préfixe, precision_zeros, width)
	manage_specs(&specs, str, val);
	
	// On écrit tout dans l'ordre
	count = write_formatted_output(str, specs, fd);
	
	free(str);
	return (count);
}

int handle_hex(va_list arg_p, int fd, char flag, t_specs specs)
{
	char           *str;
	unsigned long  val;
	int            count;

	specs.format_flag = flag;
	if (flag == 'p')
		val = va_arg(arg_p, unsigned long);
	else
		val = va_arg(arg_p, unsigned int);

	// On génère la base
	if (flag == 'o')
		str = ft_utoa_base(val, "01234567");
	else if (flag == 'p')
		str = ft_utoa_addr(val);
	else
		str = ft_utoa_base(val, "0123456789abcdef");
	
	// Si c'est %X, on met en majuscules
	if (flag == 'X')
	{
		char *tmp = ft_str_toupper(str);
		free(str);
		str = tmp;
	}

	manage_specs(&specs, str, val);
	count = write_formatted_output(str, specs, fd);
	
	free(str);
	return (count);
}

int	manage_print_args(va_list arg_p, int fd, const char *format, size_t *i)
{
	t_specs	specs;

	ft_bzero(&specs, sizeof(specs));
	if (ft_isdigit(format[*i]) || ft_strchr("0-# +", format[*i]))
	{
		while (ft_strchr("0-# +", format[*i]))
		{
			if (format[*i] == '0')
				specs.zero_pad = 1;
			else if (format[*i] == '-')
				specs.left_justify = 1;
			else if (format[*i] == '#')
				specs.hash_flag = 1;
			else if (format[*i] == '+')
				specs.plus_flag = 1;
			else if (format[*i] == ' ')
				specs.space_flag = 1;
			(*i)++;
		}
		if (specs.left_justify)
			specs.zero_pad = 0;
		specs.width = ft_atoi(&format[*i]);
		while (ft_isdigit(format[*i]))
			(*i)++;
	}
	if (format[*i] == '.')
	{
		(*i)++;
		specs.has_precision = 1;
		specs.precision = ft_atoi(&format[*i]);
		while (ft_isdigit(format[*i]))
			(*i)++;
	}
	if (format[*i] == 'c' || format[*i] == 's' || format[*i] == '%')
		return (handle_alpha(arg_p, fd, format[*i], specs));
	if (format[*i] == 'd' || format[*i] == 'i' || format[*i] == 'u')
		return (handle_digit(arg_p, fd, format[*i], specs));
	if (format[*i] == 'x' || format[*i] == 'X' || format[*i] == 'p' 
		|| format[*i] == 'o')
		return (handle_hex(arg_p, fd, format[*i], specs));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	size_t	i;
	int		total_printed;

	va_start(args, format);
	total_printed = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			// 1. Reset specs to 0
			// 2. Parse flags, width, and precision into specs
			// 3. Update format pointer to the flag char (d, s, x...)
			total_printed += manage_print_args(args, 1, format, &i);
		}
		else
			total_printed += write(1, &format[i], 1);
		i++;
	}
	va_end(args);
	return (total_printed);
}
