/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _functions.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 16:02:09 by faventur          #+#    #+#             */
/*   Updated: 2026/03/04 18:55:50 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FUNCTIONS_H
# define _FUNCTIONS_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <errno.h>
# include "libft.h"
# include "get_next_line.h"

typedef struct s_map_reader
{
	char	**arr;
	char	*buffer;
	char	*temp;
	int		fd;
	int		i;
}				t_map_reader;

int		ft_strstrbool(const char *haystack, const char *needle);
int		ft_strnstrbool(const char *haystack, const char *needle,
			size_t len);
int		ft_strcasecmp(const char *s1, const char *s2);
int		void_star_cmp(void *s1, void *s2);
void	ft_printerror(char *program, char *pathname);
void	ft_fatal(char *msg);
char	**ft_map_reader(char *filename);

#endif