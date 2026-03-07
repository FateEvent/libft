/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fab <faventur@student.42mulhouse.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 13:18:37 by faventur          #+#    #+#             */
/*   Updated: 2026/03/07 18:28:36 by fab              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "libft.h"

typedef struct s_specifiers {

	size_t	zero;
	size_t	sharp;
	size_t	minus;
	size_t	width;
	size_t	precision;
}				t_specs;

int		ft_put_unsigned(int nbr, char *base, int fd);
int		ft_putoctal(int nbr, char *base, int fd);
int		ft_puthex(unsigned int nbr, char *base, int fd);
int		ft_putaddr(unsigned long long nbr, int fd);
int		manage_print_args(va_list arg_p, int fd, const char *format, size_t *i);
int		ft_dprintf(int fd, const char *format, ...);
int		ft_printf(const char *format, ...);

#endif