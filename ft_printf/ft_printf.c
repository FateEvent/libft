/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fab <faventur@student.42mulhouse.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 15:00:26 by faventur          #+#    #+#             */
/*   Updated: 2026/03/08 13:17:52 by fab              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	manage_specs_right(t_specs specs, size_t len, int fd)
{
	size_t	j;
	int		ret;
	char	c;

	j = 0;
	ret = 0;
	if (specs.width && specs.left_justify) {
		c = ' ';
		while (len < specs.width) {
			ret += ft_putchar_fd(c, fd);
			if (ret != -1)
				j += ret;
			else
				return (-1);
			len++;
		}
	}
	return (j);
}

int	manage_specs_left(t_specs specs, size_t len, int fd)
{
	size_t	j;
	int		ret;
	char	c;

	j = 0;
	ret = 0;
	if (specs.width && !specs.left_justify) {
		c = ' ';
		if (specs.zero_pad && (specs.format_flag == 'd' || specs.format_flag == 'i'
			|| specs.format_flag == 'u' || specs.format_flag == 'o'
			|| specs.format_flag == 'x' || specs.format_flag == 'X'
			|| specs.format_flag == 'p'))
			c = '0';
		while (len < specs.width) {
			ret += ft_putchar_fd(c, fd);
			if (ret != -1)
				j += ret;
			else
				return (-1);
			len++;
		}
	}
	return (j);
}

static int	handle_alpha(va_list arg_p, int fd, char c, t_specs specs)
{
	char	*str;
	int		ret;
	int		j;
	int		k;

	j = 0;
	k = 0;
	specs.format_flag = c;
	if (c == '%')
		return (ft_putchar_fd('%', fd));
	if (c == 'c')
	{
		j = manage_specs_left(specs, 1, fd);
		ret = ft_putchar_fd(va_arg(arg_p, int), fd);
		k = manage_specs_right(specs, 1, fd);
		return ((j == -1 || ret == -1 || k == -1) ? -1 : j + ret + k);
	}
	str = va_arg(arg_p, char *);
	if (!str)
		str = "(null)";
	j = manage_specs_left(specs, ft_strlen(str), fd);
	ret = ft_putstr_fd(str, fd);
	k = manage_specs_right(specs, ft_strlen(str), fd);
	return ((j == -1 || ret == -1 || k == -1) ? -1 : j + ret + k);
}

static int	handle_digit(va_list arg_p, int fd, char c, t_specs specs)
{
	char	*str;
	int		ret;
	int		j;
	int		k;

	specs.format_flag = c;
	if (c == 'u')
		str = ft_itoa_u(va_arg(arg_p, unsigned int));
	else
		str = ft_itoa(va_arg(arg_p, int));
	if (!str)
		return (-1);
	j = manage_specs_left(specs, ft_strlen(str), fd);
	ret = ft_putstr_fd(str, fd);
	k = manage_specs_right(specs, ft_strlen(str), fd);
	free(str);
	return ((j == -1 || ret == -1 || k == -1) ? -1 : j + ret + k);
}

static int	handle_hex(va_list arg_p, int fd, char c, t_specs specs)
{
	char	*str;
	int		ret;
	int		j;
	int		k;

	specs.format_flag = c;
	if (c == 'x')
		str = ft_itoa_base_u(va_arg(arg_p, unsigned int), "0123456789abcdef");
	else if (c == 'X')
		str = ft_itoa_base_u(va_arg(arg_p, unsigned int), "0123456789ABCDEF");
	else if (c == 'o')
		str = ft_itoa_base(va_arg(arg_p, int), "01234567");
	else
		str = ft_itoa_addr(va_arg(arg_p, unsigned long long));
	if (!str)
		return (-1);
	j = manage_specs_left(specs, ft_strlen(str), fd);
	ret = ft_putstr_fd(str, fd);
	k = manage_specs_right(specs, ft_strlen(str), fd);
	free(str);
	return ((j == -1 || ret == -1 || k == -1) ? -1 : j + ret + k);
}

int	manage_print_args(va_list arg_p, int fd, const char *format, size_t *i)
{
	t_specs	specs;

	ft_bzero(&specs, sizeof(specs));
	if (ft_isdigit(format[*i]) || format[*i] == '-')
	{
		while (format[*i] == '0' || format[*i] == '-')
		{
			if (format[*i] == '0')
				specs.zero_pad = 1;
			else
				specs.left_justify = 1;
			(*i)++;
		}
		specs.width = ft_atoi(&format[*i]);
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
	va_list	arg_p;
	size_t	i;
	size_t	j;
	int		ret;

	i = 0;
	j = 0;
	va_start(arg_p, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			ret = manage_print_args(arg_p, 1, format, &i);
			if (ret != -1)
				j += ret;
			else
				return (-1);
		}
		else
		{
			ret = ft_putchar_fd(format[i], 1);
			if (ret != -1)
				j += ret;
			else
				return (-1);
		}
		i++;
	}
	va_end(arg_p);
	return (j);
}
