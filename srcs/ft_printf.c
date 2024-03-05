/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 15:00:26 by faventur          #+#    #+#             */
/*   Updated: 2024/03/05 20:07:37 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	arg_p;
	int		i;
	int		ret;
	int		j;

	i = 0;
	j = 0;
	va_start(arg_p, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			ret = manage_print_args(arg_p, 1, format, i);
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
