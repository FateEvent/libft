/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 14:56:34 by faventur          #+#    #+#             */
/*   Updated: 2024/03/05 19:57:07 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_unsigned(int nbr, char *base, int fd)
{
	int				i;
	int				memory[100];
	int				ret;
	int				j;
	unsigned int	x;

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

int	ft_puthex(unsigned int nbr, char *base, int fd)
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
	while (nbr > 0)
	{
		memory[i] = nbr % 16;
		nbr /= 16;
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

int	ft_putaddr(unsigned long long nbr, int fd)
{
	int	i;
	int	memory[100];
	int	ret;
	int	j;

	i = 0;
	j = 0;
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
