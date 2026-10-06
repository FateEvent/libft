/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_asprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fab <faventur@student.42mulhouse.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 15:00:26 by faventur          #+#    #+#             */
/*   Updated: 2026/10/06 17:16:09 by fab              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_writer	writer;

int	ft_asprintf(char **sptr, const char *format, ...)
{
	va_list		ap;
	va_list		ap_copy;
	int			i;

	ft_bzero(&writer, sizeof(t_writer));
	va_start(ap, format);

	// Copy the va_list because the first pass will consume arguments
	va_copy(ap_copy, ap);
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			manage_print_args_for_buffer(ap_copy, format, &i);
		}
		else
			write_char_to_buffer(format[i]);
		i++;
	}
	va_end(ap_copy);

	size_t	len = writer.written;

	writer.buf = malloc(writer.written + 1);
	if (!writer.buf) {
		*sptr = NULL;
		return (-1);
	}
	writer.size = len + 1;
	writer.written = 0;

	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			manage_print_args_for_buffer(ap, format, &i);
		}
		else
			write_char_to_buffer(format[i]);
		i++;
	}
	writer.buf[writer.written] = '\0';
	*sptr = writer.buf;
	va_end(ap);
	return (writer.written);
}
