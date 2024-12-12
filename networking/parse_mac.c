#include "networking.h"

int	parse_mac(char *mac)
{
	char	**arr;
	int		i;
	int		j;

	arr = ft_split(mac, ':');
	i = 0;
	while (arr[i])
	{
		if (ft_strlen(arr[i]) != 2)
		{
			ft_puterror("Parsing error!");
			ft_arr_freer(arr);
			exit(1);
		}
		if (arr[i][0] == '0' && arr[i][1] != '0') {
			ft_puterror("Parsing error!");
			ft_arr_freer(arr);
			exit(1);
		}
		j = 0;
		while (arr[i][j]) {
			if (is_hex(arr[i][j])) {
				ft_puterror("Parsing error!");
				ft_arr_freer(arr);
				exit(1);
			}
			j++;
		}
		i++;
	}
	if (i != 6)
	{
		ft_puterror("Incorrect MAC address!");
		ft_arr_freer(arr);
		exit(1);
	}
	ft_arr_freer(arr);
	return (0);
}
