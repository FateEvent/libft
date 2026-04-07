/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 11:01:43 by fab               #+#    #+#             */
/*   Updated: 2026/04/07 15:44:42 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putaddr_fd(void *addr, int fd)
{
	unsigned long long	nbr;
	int					i;
	unsigned char		memory[20];
	int					ret;
	int					j;

	i = 0;
	j = 0;
	nbr = (unsigned long long)addr;
	if (nbr == 0)
		return (ft_putstr_fd("0x0", fd));
	while (nbr)
	{
		memory[i] = nbr & 0xF;	// Retrieve the last 4 bits
		nbr >>= 4;				// Right-shift the last 4 bits
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
