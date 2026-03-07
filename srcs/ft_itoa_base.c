/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fab <faventur@student.42mulhouse.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 20:07:35 by fab               #+#    #+#             */
/*   Updated: 2026/03/07 22:14:32 by fab              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len_calculator_base(int n, long int base_len)
{
	int	i;

	i = 0;
	if (n <= 0)
		i = 1;
	while (n != 0)
	{
		n /= base_len;
		i++;
	}
	return (i);
}

char	*ft_itoa_base(int n, char *base)
{
	int			i;
	long int	x;
	long int	base_len;
	int			len;
	char		*res;

	if (!base)
		return (NULL);
	if (check_base(base)) {

		i = 0;
		x = (long) n;
		base_len = ft_strlen(base);
		len = len_calculator_base(n, base_len);
		res = (char *)malloc(sizeof(char) * (len + 1));
		if (!res)
			return (NULL);
		if (n < 0)
			x = -x;
		while (i < len_calculator_base(n, base_len) && x != 0)
		{
			res[i++] = (base[x % base_len]);
			x /= base_len;
		}
		if (n < 0)
			res[i++] = '-';
		res[i] = '\0';
		ft_rev_str(res);
		write_zeroes(res, n);
		return (res);
	}
	return (NULL);
}
