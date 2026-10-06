/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fab <faventur@student.42mulhouse.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 15:00:26 by faventur          #+#    #+#             */
/*   Updated: 2026/10/06 14:25:18 by fab              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_dprintf(int fd, const char *format, ...)
{
	va_list	args;
	int		i;
	int		total_printed;

	if (fd >= 0)
	{
		va_start(args, format);
		total_printed = 0;
		i = 0;
		while (format[i])
		{
			if (format[i] == '%')
			{
				i++;
				total_printed += manage_print_args(args, fd, format, &i);
			}
			else
				total_printed += ft_putchar_fd(format[i], fd);
			i++;
		}
		va_end(args);
		return (total_printed);
	}
	return (-1);
}
