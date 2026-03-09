/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fab <faventur@student.42mulhouse.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 10:06:35 by fab               #+#    #+#             */
/*   Updated: 2026/03/08 10:53:26 by fab              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	len_calculator_u(unsigned int n)
{
	unsigned int	i;

	i = 0;
	if (n == 0)
		i = 1;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_utoa(unsigned int n)
{
	unsigned int		i;
	long unsigned int	x;
	unsigned int		len;
	char				*res;

	i = 0;
	x = (long unsigned int)n;
	len = len_calculator_u(n);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	while (i < len_calculator_u(n) && x != 0)
	{
		res[i++] = 48 + (x % 10);
		x /= 10;
	}
	res[i] = '\0';
	ft_rev_str(res);
	write_zeroes(res, n);
	return (res);
}
