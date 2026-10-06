#include "ft_printf.h"

int	manage_specs_for_buffer(t_specs *specs, char *str, long long value)
{
	size_t  len;

	if (!str || !specs)
		return (0);

	specs->prefix = "";
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

	len = ft_strlen(str);

	if (specs->has_precision && specs->precision == 0 && value == 0)
		len = 0;

	if (specs->format_flag == 'p')
		len -= specs->prefix_size;
	if (specs->precision > len && specs->format_flag != 's')
		specs->precision_zeroes = specs->precision - len;
	else
		specs->precision_zeroes = 0;

	int total_occupied = specs->prefix_size + specs->precision_zeroes + len;
	if (specs->width > (size_t)total_occupied)
		specs->width = specs->width - total_occupied;
	else
		specs->width = 0;

	specs->pad_char = ' ';
	if (specs->zero_pad && !specs->has_precision)
		specs->pad_char = '0';
	return (1);
}

void	write_char_to_buffer(t_writer *w, char c)
{
	if (w->buf && w->written < w->size - 1) {
		w->buf[w->written] = c;
	}
	w->written++;
}

void	write_same_char_to_buffer(t_writer *w, char c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n) {
		write_char_to_buffer(w, c);
		i++;
	}
}

void	write_string_to_buffer(t_writer *w, char *str)
{
	size_t	i;
	size_t	len;

	len = ft_strlen(str);
	i = 0;
	while (i < len) {
		write_char_to_buffer(w, str[i]);
		i++;
	}
}

void	write_n_chars_of_string_to_buffer(t_writer *w, char *str, size_t n)
{
	size_t	i;
	size_t	len;

	len = ft_strlen(str) < n ? ft_strlen(str) : n;
	i = 0;
	while (i < len) {
		write_char_to_buffer(w, str[i]);
		i++;
	}
}

int	write_formatted_output_to_buffer(t_writer *writer, char *str, t_specs specs)
{
	size_t	count;
	size_t	len;
	size_t	index;

	count = 0;
	index = 0;
	len = ft_strlen(str);
	if (specs.has_precision && specs.precision == 0 && !ft_strncmp(str, "0", 1))
		len = 0;

	if (!specs.left_justify && specs.pad_char == ' ')
		write_same_char_to_buffer(writer, ' ', specs.width);

	if (specs.prefix_size > 0 && ft_strncmp(specs.prefix, str, specs.prefix_size))
		write_n_chars_of_string_to_buffer(writer, specs.prefix, specs.prefix_size);
	else if (specs.prefix_size > 0 && !ft_strncmp(specs.prefix, str, specs.prefix_size)) {
		write_n_chars_of_string_to_buffer(writer, specs.prefix, specs.prefix_size);
		index = specs.prefix_size;
	}

	if (!specs.left_justify && specs.pad_char == '0')
		write_same_char_to_buffer(writer, '0', specs.width);
	write_same_char_to_buffer(writer, '0', specs.precision_zeroes);

	if (len > 0)
		write_n_chars_of_string_to_buffer(writer, &str[index], len);

	if (specs.left_justify)
		write_same_char_to_buffer(writer, ' ', specs.width);

	return (count);
}

void	handle_string_for_buffer(t_writer *writer, char *str, t_specs specs)
{
	if (!str) str = "(null)";

	size_t len = ft_strlen(str);

	if (specs.has_precision && specs.precision < len)
		len = specs.precision;

	size_t spaces = (specs.width > len) ? specs.width - len : 0;

	if (!specs.left_justify)
		write_same_char_to_buffer(writer, ' ', spaces);
	write_n_chars_of_string_to_buffer(writer, str, len);
	if (specs.left_justify)
		write_same_char_to_buffer(writer, ' ', spaces);
}

void	handle_char_for_buffer(t_writer *writer, char c, t_specs specs)
{
	int spaces = (specs.width > 1) ? specs.width - 1 : 0;

	if (!specs.left_justify)
		write_same_char_to_buffer(writer, ' ', spaces);

	write_char_to_buffer(writer, c);

	if (specs.left_justify)
		write_same_char_to_buffer(writer, ' ', spaces);
}

void	handle_alpha_for_buffer(t_writer *writer, va_list arg_p, char flag, t_specs specs)
{
	if (flag == 'c')
		handle_char_for_buffer(writer, va_arg(arg_p, int), specs);
	else if (flag == 's')
		handle_string_for_buffer(writer, va_arg(arg_p, char *), specs);
	else if (flag == '%')
		handle_char_for_buffer(writer, '%', specs);
}

void	handle_digit_for_buffer(t_writer *writer, va_list arg_p, char flag, t_specs specs)
{
	char		*str;
	long long	val;

	specs.format_flag = flag;
	if (flag == 'u')
		val = va_arg(arg_p, unsigned int);
	else
		val = va_arg(arg_p, int);

	if (val < 0)
		str = ft_utoa_base(-val, "0123456789");
	else
		str = ft_utoa_base(val, "0123456789");

	manage_specs_for_buffer(&specs, str, val);
	write_formatted_output_to_buffer(writer, str, specs);

	free(str);
}

void	handle_hex_for_buffer(t_writer *writer, va_list arg_p, char flag, t_specs specs)
{
	char			*str;
	unsigned long	val;

	specs.format_flag = flag;
	if (flag == 'p')
		val = va_arg(arg_p, unsigned long);
	else
		val = va_arg(arg_p, unsigned int);

	if (flag == 'o')
		str = ft_utoa_base(val, "01234567");
	else if (flag == 'p')
		str = ft_utoa_addr(val);
	else
		str = ft_utoa_base(val, "0123456789abcdef");

	if (flag == 'X')
	{
		char *tmp = ft_str_toupper(str);
		free(str);
		str = tmp;
	}

	manage_specs_for_buffer(&specs, str, val);
	write_formatted_output_to_buffer(writer, str, specs);

	free(str);
}

void	manage_print_args_for_buffer(t_writer *writer, va_list arg_p, const char *format, int *i)
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
		handle_alpha_for_buffer(writer, arg_p, format[*i], specs);
	else if (format[*i] == 'd' || format[*i] == 'i' || format[*i] == 'u')
		handle_digit_for_buffer(writer, arg_p, format[*i], specs);
	else if (format[*i] == 'x' || format[*i] == 'X' || format[*i] == 'p' 
		|| format[*i] == 'o')
		handle_hex_for_buffer(writer, arg_p, format[*i], specs);
}
