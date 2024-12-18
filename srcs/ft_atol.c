/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 20:54:51 by faventur          #+#    #+#             */
/*   Updated: 2023/02/13 16:57:24 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_atol() function converts the initial portion of the string pointed to
** by nptr to long long int.
**
** Return Value: The converted value. If it is greater than LONG_LONG_MAX or
** less than LONG_LONG_MIN it will return, respectively, LONG_LONG_MAX and
** LONG_LONG_MIN.
*/

#include "libft.h"

long long	progress_bar(const char *nptr, size_t i, long long res) {
	while ((nptr[i] >= '0' && nptr[i] <= '9') && nptr[i]
			&& (res * 10 + (nptr[i] - '0')) <= LONG_LONG_MAX
			&& (res * 10 + (nptr[i] - '0')) != LONG_LONG_MIN) {
		res = res * 10 + (nptr[i++] - '0');
	}
	if (nptr[i] != '\0')
		return (LONG_LONG_MAX);
	return (res);
}

long long	ft_atol_op(const char *nptr, size_t i, long long res,
	long long define)
{
	res = progress_bar(nptr, i, res);
	if (define == LONG_LONG_MIN)
	{
		if (res == LONG_LONG_MAX)
			return (define);
	}
	else
		if (res < 0)
			return (define);
	return (res);
}

long long	ft_atol(const char *nptr)
{
	size_t          counter;
	size_t          i;
	long long	res;

	counter = 0;
	i = 0;
	res = 0;
	while (nptr[i] && ft_isspace(nptr[i]))
		i++;
	if ((nptr[i] && nptr[i] == '-' && counter++ == 0)
		|| (nptr[i] && nptr[i] == '+'))
		i++;
	if (counter == 1)
		return (ft_atol_op(nptr, i, res, LONG_LONG_MIN));
	else
		return (ft_atol_op(nptr, i, res, LONG_LONG_MAX));
}
