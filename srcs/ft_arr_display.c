/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arr_display.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 13:24:33 by faventur          #+#    #+#             */
/*   Updated: 2023/03/18 17:13:01 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_arr_display(char **arr)
{
	size_t	i;

	if (!arr || !*arr)
		return ;
	i = 0;
	while (arr[i])
	{
		ft_printf("%s\n", arr[i]);
		i++;
	}
}

static size_t	num_len_check(int **arr, size_t len)
{
	t_matrix	m;

	if (!arr || !*arr || !len)
		return (0);
	m.i = 0;
	m.res = 0;
	while (arr[m.i])
	{
		m.j = 0;
		while (m.j < len)
		{
			m.num_len = ft_strlen(ft_itoa(arr[m.i][m.j]));
			if (m.res < m.num_len)
				m.res = m.num_len;
			m.j++;
		}
		m.i++;
	}
	return (m.res);
}

void	ft_matrix_display(int **arr, size_t len)
{
	t_matrix	m;

	if (!arr || !*arr || !len)
		return ;
	m.i = -1;
	m.num_len = num_len_check(arr, len);
	while (arr[++m.i])
	{
		m.j = -1;
		while (++m.j < len)
		{
			m.k = ft_strlen(ft_itoa(arr[m.i][m.j]));
			while (m.k < m.num_len)
			{
				write(1, " ", 1);
				++m.k;
			}
			ft_printf("%d ", arr[m.i][m.j]);
			if (m.j + 1 != len)
				write(1, " ", 1);
		}
		write(1, "\n", 1);
	}
}
