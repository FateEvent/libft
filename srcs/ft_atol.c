/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 20:54:51 by faventur          #+#    #+#             */
/*   Updated: 2026/03/11 11:53:39 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_atol() function converts the initial portion of the string pointed to
** by nptr to long long int.
**
** Return Value: The converted value. If it is greater than LLONG_MAX or
** less than LLONG_MIN it will return, respectively, LLONG_MAX and
** LLONG_MIN.
*/

#include "libft.h"

long long	progress_bar(const char *nptr, size_t i, long long res) {
	while ((nptr[i] >= '0' && nptr[i] <= '9') && nptr[i]
			&& (res * 10 + (nptr[i] - '0')) <= LLONG_MAX
			&& (res * 10 + (nptr[i] - '0')) != LLONG_MIN) {
		res = res * 10 + (nptr[i++] - '0');
	}
	if (nptr[i] != '\0')
		return (LLONG_MAX);
	return (res);
}

long long	ft_atol_op(const char *nptr, size_t i, long long res,
	long long define)
{
	res = progress_bar(nptr, i, res);
	if (define == LLONG_MIN)
	{
		if (res == LLONG_MAX)
			return (define);
		return (-res);
	}
	else
		if (res < 0)
			return (define);
	return (res);
}

long	ft_atol(const char *nptr)
{
	size_t		counter;
	size_t		i;
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
		return (ft_atol_op(nptr, i, res, LLONG_MIN));
	else
		return (ft_atol_op(nptr, i, res, LLONG_MAX));
}
