/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_unsigned_fd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fab <faventur@student.42mulhouse.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 11:06:12 by fab               #+#    #+#             */
/*   Updated: 2026/04/03 21:16:00 by fab              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_put_unsigned_fd(size_t nbr, char *base, int fd)
{
	int		i;
	int		memory[100];
	int		ret;
	int		j;
	size_t	x;

	x = (unsigned int)nbr;
	i = 0;
	j = 0;
	if (nbr == 0)
	{
		ret = ft_putchar_fd(0 + '0', fd);
		if (ret != -1)
			j += ret;
		else
			return (-1);
	}
	while (x > 0)
	{
		memory[i] = x % 10;
		x /= 10;
		i++;
	}
	while (--i >= 0)
	{
		ret = ft_putchar_fd(base[memory[i]], fd);
		if (ret != -1)
			j += ret;
		else
			return (-1);
	}
	return (j);
}
