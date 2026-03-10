#include "libft.h"

char	*ft_str_toupper(char *str)
{
	size_t	i;
	size_t	len;
	char	*new;

	if (str)
	{
		len = ft_strlen(str);
		new = malloc(len + 1);
		if (new) {
			i = 0;
			while (str[i])
			{
				new[i] = ft_toupper(str[i]);
				i++;
			}
			return (new);
		}
	}
	return (NULL);
}
