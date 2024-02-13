/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chartab_len.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 15:27:15 by faventur          #+#    #+#             */
/*   Updated: 2023/03/18 14:01:21 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_chartab_len(char **arr)
{
	size_t	i;

	if (!arr || !*arr)
		return (0);
	i = 0;
	while (arr[i] != NULL)
		i++;
	return (i);
}
