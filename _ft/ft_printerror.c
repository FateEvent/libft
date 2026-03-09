/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printerror.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 15:37:19 by faventur          #+#    #+#             */
/*   Updated: 2026/03/09 11:15:47 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_functions.h"

void	ft_printerror(char *program, char *pathname)
{
	ft_dprintf(2, "%s: %s: %s\n", program, pathname, strerror(errno));
	exit(1);
}
