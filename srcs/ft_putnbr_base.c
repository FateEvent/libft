/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 20:24:31 by faventur          #+#    #+#             */
/*   Updated: 2024/03/05 19:03:22 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check_base(char *base)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	len = ft_strlen(base);
	if (len == 0 || len == 1)
		return (0);
	while (base[i])
	{
		j = i + 1;
		if (base[i] == '-' || base[i] == '+' || base[i] < 32 || base[i] > 126)
			return (0);
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	convert_base(long int num, char *base)
{
	long int	len;

	len = ft_strlen(base);
	if (num >= len)
		convert_base(num / len, base);
	ft_putchar(base[num % len]);
}

void	ft_putnbr_base(int nbr, char *base)
{
	long int	x;

	if (!base)
		return ;
	x = nbr;
	if (check_base(base))
	{
		if (nbr < 0)
		{
			write(1, "-", 1);
			x = -x;
		}
		convert_base(x, base);
	}
}
