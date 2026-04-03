/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fab <faventur@student.42mulhouse.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 11:01:43 by fab               #+#    #+#             */
/*   Updated: 2026/04/03 12:22:56 by fab              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putaddr_fd(void *addr, int fd)
{
	unsigned long long	nbr;
	int					i;
	int					memory[100];
	int					ret;
	int					j;

	i = 0;
	j = 0;
	nbr = (unsigned long long)addr;
	if (nbr == 0)
		return (ft_putstr_fd("0x0", fd));
	while (nbr)
	{
		memory[i] = nbr % 16;
		nbr /= 16;
		i++;
	}
	ret = ft_putstr_fd("0x", fd);
	if (ret != -1)
		j += ret;
	else
		return (-1);
	while (--i >= 0)
	{
		ret = ft_putchar_fd("0123456789abcdef"[memory[i]], fd);
		if (ret != -1)
			j += ret;
		else
			return (-1);
	}
	return (j);
}
