#include "network.h"

int	parse_ip(char *ip)
{
	char	**arr;
	int		i;

	arr = ft_split(ip, '.');
	i = 0;
	while (arr[i])
	{
		if (arr[i][0] == '0' && strlen(arr[i]) > 1)
		{
			ft_puterror("Parsing error!");
			ft_arr_freer(arr);
			exit(1);
		}
		if (ft_atoi(arr[i]) < 0 || ft_atoi(arr[i]) > 255)
		{
			ft_puterror("Parsing error!");
			ft_arr_freer(arr);
			exit(1);
		}
		i++;
	}
	if (i != 4)
	{
		ft_puterror("Incorrect IP address!");
		ft_arr_freer(arr);
		exit(1);
	}
	ft_arr_freer(arr);
	return (0);
}
