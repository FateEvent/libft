/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 20:54:51 by faventur          #+#    #+#             */
/*   Updated: 2023/02/13 16:57:24 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_atoll_u() function converts the initial portion of the string
** pointed to by nptr to long long unsigned int.
**
** Return Value: The converted value.
*/

#include "libft.h"

static unsigned long long	progress_bar_unsigned(const char *nptr, size_t i,
	unsigned long long res) {
	while ((nptr[i] >= '0' && nptr[i] <= '9') && nptr[i]) {
		res = res * 10 + (nptr[i++] - '0');
	}
	return (res);
}

static unsigned long long	ft_atoll_u_op(const char *nptr, size_t i,
	unsigned long long res)
{
	res = progress_bar_unsigned(nptr, i, res);
	if (res > LONG_LONG_MAX)
		return (-1);
	return (res);
}

unsigned long long	ft_atoll_u(const char *nptr)
{
	unsigned long long	i;
	unsigned long long	res;

	i = 0;
	res = 0;
	while (nptr[i] && ft_isspace(nptr[i]))
		i++;
	if (nptr[i] && nptr[i] == '-')
		return (-1);
	if (nptr[i] && nptr[i] == '+')
		i++;
	return (ft_atoll_u_op(nptr, i, res));
}
