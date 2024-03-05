/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 10:35:34 by faventur          #+#    #+#             */
/*   Updated: 2024/03/05 17:36:08 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr(int nb)
{
	int	i;
	int	ret;

	i = 0;
	if (nb == -2147483648)
		return (write(1, "-2147483648", 11));
	else
	{
		if (nb < 0)
		{
			nb = -nb;
			if (write(1, "-", 1) >= 0)
				i++;
			else
				return (-1);
		}
		if (nb >= 10)
		{
			ret = ft_putnbr(nb / 10);
			if (ret != -1)
				i += ret;
			else
				return (-1);
			ret = ft_putnbr(nb % 10);
			if (ret != -1)
				i += ret;
			else
				return (-1);
		}
		else
		{
			ret = ft_putchar(nb + '0');
			if (ret != -1)
				i += ret;
			else
				return (-1);
		}
		return (i);
	}
}
