/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arr_freer_index.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fab <faventur@student.42mulhouse.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 16:44:33 by faventur          #+#    #+#             */
/*   Updated: 2026/10/19 22:20:12 by fab              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_arr_freer_index(char **arr, ssize_t index)
{
	ssize_t	i;

	if (!arr)
		return (NULL);
	i = index - 1;
	while (i >= 0)
	{
		free(arr[i]);
		arr[i] = NULL;
		i--;
	}
	free(arr);
	return (NULL);
}

char	**ft_arr_freer_reverse_index(char **arr, size_t index, size_t size)
{
	size_t	i;

	if (!arr)
		return (NULL);
	i = index + 1;
	while (i < size)
	{
		free(arr[i]);
		arr[i] = NULL;
		i++;
	}
	free(arr);
	return (NULL);
}
