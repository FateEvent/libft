/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fab <faventur@student.42mulhouse.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 14:56:34 by faventur          #+#    #+#             */
/*   Updated: 2026/03/10 09:34:31 by fab              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned int	len_calculator_addr(unsigned long long n)
{
	unsigned long long	i;

	i = 0;
	if (n == 0)
		i = 3;
	while (n != 0)
	{
		n /= 16;
		i++;
	}
	return (i + 2);
}

char	*ft_utoa_addr(unsigned long long n)
{
	unsigned long long	i;
	unsigned long long	x;
	unsigned long long	len;
	char				*base;
	char	        	*res;

	base = "0123456789abcdef";

	i = 0;
	x = n;
	len = len_calculator_addr(n);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	if (x == 0) {
		return (ft_strcpy(res, "0x0"));
	}
	while (i < len_calculator_addr(n) && x != 0)
	{
		res[i++] = (base[x % 16]);
		x /= 16;
	}
	res[i++] = 'x';
	res[i++] = '0';
	res[i] = '\0';
	ft_rev_str(res);
	write_zeroes(res, n);
	return (res);
}
