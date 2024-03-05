/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 11:29:35 by faventur          #+#    #+#             */
/*   Updated: 2024/03/05 16:57:17 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_putendl_fd() function writes a string on the file descriptor
** followed by a carriage return.
*/

#include "libft.h"

int	ft_putendl_fd(char const *s, int fd)
{
	int	i;

	i = 0;
	if (fd >= 0 && s)
	{
		i = ft_putstr_fd(s, fd);
		if (i > -1)
			i += write(fd, "\n", 1);	
	}
	return (i);
}
