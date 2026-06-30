#include "networking.h"

int	str_ipcheck(const char *str)
{
	size_t	i;
	size_t	dot_count;
	size_t	start;
	int		value;

	i = 0;
	dot_count = 0;
	start = 0;
	while (ft_isdigit(str[i]) || str[i] == '.')
	{
		while (ft_isdigit(str[i])) {
			i++;
			fprintf(stderr, "ft_ping: 1\n");
		}
		if (str[i] == '.' || str[i] == '\0')
		{
			fprintf(stderr, "ft_ping: ...\n");
			value = ft_atoi(ft_substr(str, start, i - start));
			fprintf(stderr, "ft_ping: %d\n", value);
			if (value < 0 || value > 255)
				return (1);
			if (str[i] == '.')
			{
				dot_count++;
				start = i + 1;
				i++;
			}
		}
	}
	if (str[i] != '\0' || (dot_count != 3 && dot_count != 1))
		return (1);
	return (0);
}
