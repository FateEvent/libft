/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atollu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 20:54:51 by faventur          #+#    #+#             */
/*   Updated: 2023/02/13 16:57:24 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_atollu() function converts the initial portion of the string
** pointed to by nptr to unsigned long long int.
**
** Return Value: The converted value, 0 if it fails, ULLONG_MAX if it
** overflows.
*/

#include "libft.h"

static unsigned long long	progress_bar_unsigned(const char *nptr, size_t i,
	unsigned long long res)
{
	unsigned long long	digit;

	while ((nptr[i] >= '0' && nptr[i] <= '9') && nptr[i])
	{
		digit = nptr[i] - '0';
		if (res > (ULLONG_MAX - digit) / 10)
			return (ULLONG_MAX);
		res = res * 10 + digit;
		i++;
	}
	if (nptr[i] != '\0')
		return (ULLONG_MAX);
	return (res);
}

static unsigned long long	ft_atollu_op(const char *nptr, size_t i,
	unsigned long long res)
{
	res = progress_bar_unsigned(nptr, i, res);
	if (res > ULLONG_MAX)
		return (-1);
	return (res);
}

unsigned long long	ft_atollu(const char *nptr)
{
	unsigned long long	i;
	unsigned long long	res;

	i = 0;
	res = 0;
	while (nptr[i] && ft_isspace(nptr[i]))
		i++;
	if (nptr[i] && nptr[i] == '-' && nptr[i + 1] && ft_isdigit(nptr[i + 1]))
		return (-1);
	else if (nptr[i] && nptr[i] == '+' && nptr[i + 1] && ft_isdigit(nptr[i + 1]))
		i++;
	else if (nptr[i] && nptr[i] == '-')
		return (0);
	else if (nptr[i] && nptr[i] == '+')
		return (0);
	return (ft_atollu_op(nptr, i, res));
}
