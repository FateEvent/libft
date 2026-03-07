/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fab <faventur@student.42mulhouse.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 15:00:26 by faventur          #+#    #+#             */
/*   Updated: 2026/03/07 14:50:02 by fab              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_dprintf(int fd, const char *format, ...)
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
