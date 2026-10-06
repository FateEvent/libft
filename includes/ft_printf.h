/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fab <faventur@student.42mulhouse.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 13:18:37 by faventur          #+#    #+#             */
/*   Updated: 2026/10/06 17:26:12 by fab              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "libft.h"


typedef	struct s_specifiers {

	size_t	width;
	size_t	left_justify;
	size_t	zero_pad;
	size_t	pad_char;
	size_t	has_precision;
	size_t	precision;
	size_t	precision_zeroes;
	size_t	hash_flag;
	char	format_flag;
	char	*prefix;
	size_t	prefix_size;
	size_t	minus;
	size_t	plus_flag;
	size_t	space_flag;
}				t_specs;

typedef	struct s_writer {

	char	*buf;		// Pointer to buffer (NULL if counting only)
	size_t	size;		// Buffer capacity
	size_t	written;	// Counter incremented on every character
	int		fd;			// File descriptor (used if buf is NULL and fd >= 0)
}				t_writer;

extern t_writer	writer;


// ft_printf
int		ft_printf(const char *format, ...);
int		manage_print_args(va_list arg_p, int fd, const char *format, int *i);
char	*ft_utoa_addr(unsigned long long n);

// ft_dprintf
int		ft_dprintf(int fd, const char *format, ...);

// ft_vasprintf
int		ft_vasprintf(char **sptr, const char *format, va_list ap);
void	manage_print_args_for_buffer(va_list arg_p, const char *format, int *i);
void	write_char_to_buffer(char c);

// ft_asprintf
int		ft_asprintf(char **sptr, const char *format, ...);


#endif