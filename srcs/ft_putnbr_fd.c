/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 10:35:34 by faventur          #+#    #+#             */
/*   Updated: 2024/03/05 17:49:47 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_putnbr_fd() function writes an integer on the file descriptor.
*/

#include "libft.h"

int	ft_putnbr_fd(int nb, int fd)
{
	int	i;
	int	ret;

	i = 0;
	if (fd >= 0)
	{
		if (nb == -2147483648)
			return (write(fd, "-2147483648", 11));
		else
		{
			if (nb < 0)
			{
				nb = -nb;
				if (write(fd, "-", 1) >= 0)
					i++;
				else
					return (-1);
			}
			if (nb >= 10)
			{
				ret = ft_putnbr_fd(nb / 10, fd);
				if (ret != -1)
					i += ret;
				else
					return (-1);
				ret = ft_putnbr_fd(nb % 10, fd);
				if (ret != -1)
					i += ret;
				else
					return (-1);
			}
			else
			{
				ret = ft_putchar_fd(nb + '0', fd);
				if (ret != -1)
					i += ret;
				else
					return (-1);
			}
		}
	}
	return (i);
}
