/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 11:13:40 by faventur          #+#    #+#             */
/*   Updated: 2024/03/05 16:57:31 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_putstr_fd() function writes a string on the file descriptor. 
*/

#include "libft.h"

int	ft_putstr_fd(char const *str, int fd)
{
	int	i;

	i = 0;
	if (fd >= 0 && str)
	{
		while (i >= 0 && str[i])
		{
			if (ft_putchar_fd(str[i], fd))
				i = -1;
			else
				i++;
		}
	}
	return (i);
}
