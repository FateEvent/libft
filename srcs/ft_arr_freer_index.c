/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arr_freer_index.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 16:44:33 by faventur          #+#    #+#             */
/*   Updated: 2023/03/18 13:16:03 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_arr_freer_index(char **arr, ssize_t *index)
{
	ssize_t	i;

	if (!arr)
		return (NULL);
	i = *index - 1;
	while (i >= 0)
	{
		free(arr[i]);
		arr[i] = NULL;
		i--;
	}
	free(arr);
	arr = NULL;
	return (arr);
}

char	**ft_arr_freer_reverse_index(char **arr, size_t *index, size_t size)
{
	size_t	i;

	if (!arr)
		return (NULL);
	i = *index + 1;
	while (i < size)
	{
		free(arr[i]);
		arr[i] = NULL;
		i++;
	}
	free(arr);
	arr = NULL;
	return (arr);
}
