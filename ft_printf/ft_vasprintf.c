#include "ft_printf.h"

t_writer	writer;

int	ft_vasprintf(char **sptr, const char *format, va_list ap)
{
	va_list		ap_copy;
	int			i;

	if (!format)
		return (-1);

	ft_bzero(&writer, sizeof(t_writer));
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

	size_t	total_len = writer.written;

	writer.buf = malloc(total_len + 1);
	if (!writer.buf)
	{
		*sptr = NULL;
		return (-1);
	}
	writer.size = total_len + 1;
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

	return (writer.written);
}
