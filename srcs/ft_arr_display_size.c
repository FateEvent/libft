/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arr_display_size.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fab <faventur@student.42mulhouse.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 13:24:33 by faventur          #+#    #+#             */
/*   Updated: 2026/03/07 15:02:40 by fab              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_arr_display_size() displays, one by one, the strings contained
** in a non-NULL-terminated array of strings. It does not display empty
** strings (i.e., strings starting with the '\0' character).
*/

#include "libft.h"

void	ft_arr_display_size(char **arr, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		if (arr[i][0])
			ft_putendl(arr[i]);
		i++;
	}
}
