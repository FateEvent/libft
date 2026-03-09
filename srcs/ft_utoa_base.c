/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fab <faventur@student.42mulhouse.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 10:12:32 by fab               #+#    #+#             */
/*   Updated: 2026/03/08 10:54:53 by fab              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	len_calculator_base_u(unsigned int n, long unsigned int base_len)
{
	unsigned int	i;

	i = 0;
	if (n == 0)
		i = 1;
	while (n != 0)
	{
		n /= base_len;
		i++;
	}
	return (i);
}

char	*ft_utoa_base(unsigned int n, char *base)
{
	unsigned int		i;
	long unsigned int	x;
	long unsigned int	base_len;
	unsigned int		len;
	char	        	*res;

	if (!base)
		return (NULL);
	if (check_base(base)) {

		i = 0;
		x = (long) n;
		base_len = ft_strlen(base);
		len = len_calculator_base_u(n, base_len);
		res = (char *)malloc(sizeof(char) * (len + 1));
		if (!res)
			return (NULL);
		while (i < len_calculator_base_u(n, base_len) && x != 0)
		{
			res[i++] = (base[x % base_len]);
			x /= base_len;
		}
		res[i] = '\0';
		ft_rev_str(res);
		write_zeroes(res, n);
		return (res);
	}
	return (NULL);
}
