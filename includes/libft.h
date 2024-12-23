/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 22:19:34 by faventur          #+#    #+#             */
/*   Updated: 2024/03/05 17:10:17 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include "ft_printf.h"
# include "get_next_line.h"

# ifndef LONG_LONG_MAX
#  define LONG_LONG_MAX 9223372036854775807
# endif

# ifndef LONG_LONG_MIN
#  define LONG_LONG_MIN -9223372036854775808
# endif

typedef struct s_matrix
{
	size_t	i;
	size_t	j;
	size_t	k;
	size_t	num_len;
	size_t	res;
}				t_matrix;

typedef struct s_split
{
	ssize_t	i;
	ssize_t	j;
	ssize_t	k;
	ssize_t	tab_size;
	ssize_t	str_len;
	char	**strtab;
}				t_split;

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

// Libc standard functions
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_isspace(int c);
size_t				ft_strlen(const char *str);
void				*ft_memset(void *s, int c, size_t n);
void				ft_bzero(void *s, size_t n);
void				*ft_memalloc(size_t size);
void				*ft_memcpy(void *dst, const void *src, size_t size);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strclear(char *s);
void				ft_strdel(char **as);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strncpy(char *dest, const char *src, size_t n);
size_t				ft_strlcpy(char *dest, const char *src, size_t size);
char				*ft_strcat(char *dest, const char *src);
char				*ft_strncat(char *dest, const char *src, size_t n);
size_t				ft_strlcat(char *dest, const char *src, size_t size);
int					ft_toupper(int c);
int					ft_tolower(int c);
char				*ft_strchr(const char *str, int c);
char				*ft_strrchr(const char *str, int c);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strnstr(const char *haystack, const char *needle, size_t len);
int					ft_strequ(const char *s1, const char *s2);
int					ft_strnequ(const char *s1, const char *s2, size_t n);
int					ft_atoi(const char *nptr);
void				*ft_calloc(size_t nmemb, size_t size);
char				*ft_strdup(const char *src);
long long			ft_atol(const char *nptr);
unsigned long long	ft_atoll_u(const char *nptr);

// Supplementary functions
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(const char *s1, const char *s2);
char				*ft_strtrim(char const *s, char const *set);
char				*ft_spacetrim(char const *s);
char				**ft_split(char const *s, char c);
char				*ft_itoa(int n);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_putchar(char c);
int					ft_putstr(char const *str);
int					ft_putendl(char const *s);
int					ft_putnbr(int nb);
int					ft_putchar_fd(char c, int fd);
int					ft_putstr_fd(char const *str, int fd);
int					ft_putendl_fd(char const *s, int fd);
int					ft_putnbr_fd(int nb, int fd);
void				ft_putnbr_base(int nbr, char *base);

// Bonus functions
t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
void				ft_lstsort(t_list **begin_list, int (*cmp)());
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

// Addenda
int					strnumcheck(const char *str);
void				ft_sort_int_tab(int	*tab, int size);
void				ft_sort_chartab(char **tab);
size_t				ft_chartab_len(char **arr);
int					ft_power(int n, int power);
char				ft_binary2char(char *binary);
int					ft_strtolol(const char *str);
void				ft_arr_freer(char **arr);
char				**ft_arr_freer_index(char **arr, ssize_t *index);
char				**ft_arr_freer_reverse_index(char **arr, size_t *index, size_t size);
void				ft_puterror(const char *str);
char				**ft_arrdup(char **arr);
size_t				ft_arrlen(char **array);
void				ft_arr_display(char **arr);
void				ft_arr_display_size(char **arr, size_t size);
void				ft_intarr_freer(int **arr);
void				ft_intarr_freer_index(int **arr, ssize_t index);
void				ft_matrix_display(int **arr, size_t len);

#endif