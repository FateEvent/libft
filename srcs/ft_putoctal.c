/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putoctal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fab <faventur@student.42mulhouse.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 10:58:58 by fab               #+#    #+#             */
/*   Updated: 2026/03/08 11:07:23 by fab              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putoctal(int nbr, char *base, int fd)
{
	int	i;
	int	memory[100];
	int	ret;
	int	j;

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
	if (nbr < 0)
	{
		nbr *= -1;
		if (ft_putchar_fd('-', fd) >= 0)
			i++;
		else
			return (-1);
	}
	while (nbr > 0)
	{
		memory[i] = nbr % 8;
		nbr /= 8;
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
