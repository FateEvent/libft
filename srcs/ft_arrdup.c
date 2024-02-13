/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 16:08:04 by albaur            #+#    #+#             */
/*   Updated: 2023/03/18 13:19:29 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_arrdup(char **arr)
{
	char	**dup;
	size_t	arr_len;
	size_t	i;

	dup = NULL;
	if (!arr)
		return (NULL);
	arr_len = ft_arrlen(arr);
	if (!arr_len)
		return (NULL);
	i = arr_len;
	dup = (char **)malloc(sizeof(char *) * (arr_len + 1));
	if (!dup)
		return (NULL);
	dup[arr_len] = NULL;
	while (arr_len--)
	{
		dup[arr_len] = ft_strdup(arr[arr_len]);
		if (!dup[arr_len])
			return (ft_arr_freer_reverse_index(dup, &arr_len, i));
	}
	return (dup);
}
