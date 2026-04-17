#include "networking.h"

int	str_ipcheck(const char *str)
{
	size_t	i;

	i = 0;
	while (ft_isdigit(str[i]) || str[i] == '.')
	{
		i++;
	}
	if (str[i] != '\0')
		return (1);
	return (0);
}
