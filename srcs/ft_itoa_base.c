/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fab <faventur@student.42mulhouse.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 20:07:35 by fab               #+#    #+#             */
/*   Updated: 2026/03/07 20:08:17 by fab              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len_calculator(int n)
{
	int	i;

	i = 0;
	if (n == -2147483648)
		return (11);
	if (n <= 0)
		i = 1;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static char	*ft_rev_str(char *res)
{
	int		start;
	int		end;
	char	temp;

	start = 0;
	end = ft_strlen(res) - 1;
	while (start < end)
	{
		temp = res[start];
		res[start] = res[end];
		res[end] = temp;
		start++;
		end--;
	}
	return (res);
}

static void	write_zeroes(char *res, int n)
{
	if (n == 0)
	{
		res[0] = '0';
		res[1] = '\0';
	}
}

char	*ft_itoa(int n)
{
	int			i;
	long int	x;
	int			len;
	char		*res;

	i = 0;
	x = (long) n;
	len = len_calculator(n);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	if (n < 0)
		x = -x;
	while (i < len_calculator(n) && x != 0)
	{
		res[i++] = 48 + (x % 10);
		x /= 10;
	}
	if (n < 0)
		res[i++] = '-';
	res[i] = '\0';
	ft_rev_str(res);
	write_zeroes(res, n);
	return (res);
}
