/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fab <faventur@student.42mulhouse.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 13:18:37 by faventur          #+#    #+#             */
/*   Updated: 2026/03/10 00:07:09 by fab              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "libft.h"

typedef struct s_specifiers {

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

char	*ft_utoa_addr(unsigned long long n);
int		manage_print_args(va_list arg_p, int fd, const char *format, size_t *i);
int		ft_dprintf(int fd, const char *format, ...);
int		ft_printf(const char *format, ...);

#endif