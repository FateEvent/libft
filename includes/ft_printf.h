/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprintf.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 13:18:37 by faventur          #+#    #+#             */
/*   Updated: 2024/03/05 19:52:14 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "libft.h"

int		ft_put_unsigned(int nbr, char *base, int fd);
int		ft_putoctal(int nbr, char *base, int fd);
int		ft_puthex(unsigned int nbr, char *base, int fd);
int		ft_putaddr(unsigned long long nbr, int fd);
int		manage_print_args(va_list arg_p, int fd, const char *format, int i);
int		ft_fprintf(int fd, const char *format, ...);
int		ft_printf(const char *format, ...);

#endif