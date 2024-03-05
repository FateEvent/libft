/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 10:27:48 by faventur          #+#    #+#             */
/*   Updated: 2024/03/05 16:57:09 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_putchar_fd() function writes a character on the file descriptor. 
*/

#include "libft.h"

int	ft_putchar_fd(char c, int fd)
{
	int	i;

	i = 0;
	if (fd >= 0)
		i = write(fd, &c, 1);
	return (i);
}
