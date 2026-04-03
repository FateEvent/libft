/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddr_endl_fd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fab <faventur@student.42mulhouse.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 11:01:43 by fab               #+#    #+#             */
/*   Updated: 2026/04/03 12:27:57 by fab              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putaddr_endl_fd(void *addr, int fd)
{
	int	i;

	i = ft_putaddr_fd(addr, fd);
	if (i > -1)
		i += ft_putchar_fd('\n', fd);
	return (i);
}
