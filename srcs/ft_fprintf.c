/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 15:00:26 by faventur          #+#    #+#             */
/*   Updated: 2024/03/05 20:17:14 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	manage_print_args(va_list arg_p, int fd, const char *format, int i)
{
	int	ret;
	int	j;

	j = 0;
	if (format[i] == '%')
	{
		ret = ft_putchar_fd('%', fd);
		if (ret != -1)
			j += ret;
		else
			return (-1);
	}
	else if (format[i] == 'c')
	{
		ret = ft_putchar_fd(va_arg(arg_p, int), fd);
		if (ret != -1)
			j += ret;
		else
			return (-1);
	}
	else if (format[i] == 'd' || format[i] == 'i')
	{
		ret = ft_putnbr_fd(va_arg(arg_p, int), fd);
		if (ret != -1)
			j += ret;
		else
			return (-1);
	}
	else if (format[i] == 's')
	{
		ret = ft_putstr_fd(va_arg(arg_p, char *), fd);
		if (ret != -1)
			j += ret;
		else
			return (-1);
	}
	else if (format[i] == 'o')
	{
		ret = ft_putoctal(va_arg(arg_p, int), "01234567", fd);
		if (ret != -1)
			j += ret;
		else
			return (-1);
	}
	else if (format[i] == 'u')
	{
		ret = ft_put_unsigned(va_arg(arg_p, int), "0123456789", fd);
		if (ret != -1)
			j += ret;
		else
			return (-1);
	}
	else if (format[i] == 'x')
	{
		ret = ft_puthex(va_arg(arg_p, unsigned int), "0123456789abcdef", fd);
		if (ret != -1)
			j += ret;
		else
			return (-1);
	}
	else if (format[i] == 'X')
	{
		ret = ft_puthex(va_arg(arg_p, unsigned int), "0123456789ABCDEF", fd);
		if (ret != -1)
			j += ret;
		else
			return (-1);
	}
	else if (format[i] == 'p')
	{
		ret = ft_putaddr(va_arg(arg_p, unsigned long long), fd);
		if (ret != -1)
			j += ret;
		else
			return (-1);
	}
	else
	{
		ret = ft_putchar_fd(format[i], fd);
		if (ret != -1)
			j += ret;
		else
			return (-1);
	}
	return (j);
}

int	ft_fprintf(int fd, const char *format, ...)
{
	va_list	arg_p;
	int		i;
	int		ret;
	int		j;

	if (fd >= 0)
	{
		i = 0;
		j = 0;
		va_start(arg_p, format);
		while (format[i] != '\0')
		{
			if (format[i] == '%')
			{
				i++;
				ret = manage_print_args(arg_p, fd, format, i);
				if (ret != -1)
					j += ret;
				else
					return (-1);
			}
			else
			{
				ret = ft_putchar_fd(format[i], fd);
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
	return (-1);
}
