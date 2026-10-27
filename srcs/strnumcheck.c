#include "libft.h"

int	strnumcheck(const char *str)
{
	size_t	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (ft_isdigit(str[i]))
	{
		i++;
	}
	if (str[i] != '\0')
		return (1);
	return (0);
}