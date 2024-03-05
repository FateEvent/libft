/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 10:49:08 by faventur          #+#    #+#             */
/*   Updated: 2024/03/05 16:57:34 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr(char const *str)
{
	int	i;

	i = 0;
	if (str)
	{
		while (i >= 0 && str[i])
		{
			if (ft_putchar(str[i]) == -1)
				i = -1;
			else
				i++;
		}
	}
	return (i);
}
