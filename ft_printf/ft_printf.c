/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fab <faventur@student.42mulhouse.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 15:00:26 by faventur          #+#    #+#             */
/*   Updated: 2026/03/08 10:48:32 by fab              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	manage_specs(t_specs specs, size_t len, int fd) {

	size_t	j;
	int		ret;

	j = 0;
	ret = 0;
	if (specs.width) {

		while (len < specs.width) {

			ret += ft_putchar_fd(' ', fd);
			if (ret != -1)

				j += ret;
			else

				return (-1);
			len++;
		}
	}
	return (j);
}

int	manage_print_args(va_list arg_p, int fd, const char *format, size_t *i) {

	t_specs	specs;
	size_t	j;
	size_t	count;
	int		ret;

	j = 0;
	count = 0;
	ft_bzero(&specs, sizeof(specs));
	if (ft_isdigit(format[*i])) {

		specs.width = ft_atoi(&format[*i]);
		while (ft_isdigit(format[*i])) {

			count++;
			(*i)++;
		}
	}
	if (format[*i] == '%') {

		ret = ft_putchar_fd('%', fd);
		if (ret != -1)

			j += ret;
		else

			return (-1);
	} else if (format[*i] == 'c') {

		ret = manage_specs(specs, 1, fd);
		if (ret != -1)

			j += ret;
		else

			return (-1);
		ret = ft_putchar_fd(va_arg(arg_p, int), fd);
		if (ret != -1)

			j += ret;
		else

			return (-1);
	} else if (format[*i] == 'd' || format[*i] == 'i') {

		char	*str;
		size_t	len;

		str = ft_itoa(va_arg(arg_p, int));
		if (!str)

			return (-1);
		len = ft_strlen(str);
		ret = manage_specs(specs, len, fd);
		if (ret != -1)

			j += ret;
		else {

			free(str);
			return (-1);
		}
		ret = ft_putstr_fd(str, fd);
		if (ret != -1)

			j += ret;
		else {

			free(str);
			return (-1);
		}
	} else if (format[*i] == 's') {

		char	*str;
		size_t	len;

		str = va_arg(arg_p, char *);
		len = ft_strlen(str);
		ret = manage_specs(specs, len, fd);
		if (ret != -1)

			j += ret;
		else

			return (-1);
		ret = ft_putstr_fd(str, fd);
		if (ret != -1)

			j += ret;
		else

			return (-1);
	} else if (format[*i] == 'o') {

		char	*str;
		size_t	len;

		str = ft_itoa_base(va_arg(arg_p, int), "01234567");
		if (!str)

			return (-1);
		len = ft_strlen(str);
		ret = manage_specs(specs, len, fd);
		if (ret != -1)

			j += ret;
		else {

			free(str);
			return (-1);
		}
		ret = ft_putstr_fd(str, fd);
		if (ret != -1)

			j += ret;
		else {

			free(str);
			return (-1);
		}
	} else if (format[*i] == 'u') {

		char	*str;
		size_t	len;

		str = ft_itoa_u(va_arg(arg_p, unsigned int));
		if (!str)

			return (-1);
		len = ft_strlen(str);
		ret = manage_specs(specs, len, fd);
		if (ret != -1)

			j += ret;
		else {

			free(str);
			return (-1);
		}
		ret = ft_putstr_fd(str, fd);
		if (ret != -1)

			j += ret;
		else {

			free(str);
			return (-1);
		}
	} else if (format[*i] == 'x') {

		char	*str;
		size_t	len;

		str = ft_itoa_base_u(va_arg(arg_p, unsigned int), "0123456789abcdef");
		if (!str)

			return (-1);
		len = ft_strlen(str);
		ret = manage_specs(specs, len, fd);
		if (ret != -1)

			j += ret;
		else {

			free(str);
			return (-1);
		}
		ret = ft_putstr_fd(str, fd);
		if (ret != -1)

			j += ret;
		else {

			free(str);
			return (-1);
		}
	} else if (format[*i] == 'X') {

		char	*str;
		size_t	len;

		str = ft_itoa_base_u(va_arg(arg_p, unsigned int), "0123456789ABCDEF");
		if (!str)

			return (-1);
		len = ft_strlen(str);
		ret = manage_specs(specs, len, fd);
		if (ret != -1)

			j += ret;
		else {

			free(str);
			return (-1);
		}
		ret = ft_putstr_fd(str, fd);
		if (ret != -1)

			j += ret;
		else {

			free(str);
			return (-1);
		}
	} else if (format[*i] == 'p') {

		char	*str;
		size_t	len;

		str = ft_itoa_addr(va_arg(arg_p, unsigned long long));
		if (!str)

			return (-1);
		len = ft_strlen(str);
		ret = manage_specs(specs, len, fd);
		if (ret != -1)

			j += ret;
		else {

			free(str);
			return (-1);
		}
		ret = ft_putstr_fd(str, fd);
		if (ret != -1)

			j += ret;
		else {

			free(str);
			return (-1);
		}
	}
	return (j);
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
	while (format[i] != '\0') {

		if (format[i] == '%') {

			i++;
			ret = manage_print_args(arg_p, 1, format, &i);
			if (ret != -1)

				j += ret;
			else

				return (-1);
		} else {

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
