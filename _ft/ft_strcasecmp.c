#include "_functions.h"

int	ft_strcasecmp(const char *s1, const char *s2)
{
	while (1) {
		char u1 = ft_tolower((int)(unsigned char)(*s1++));
		char u2 = ft_tolower((int)(unsigned char)(*s2++));
		if (u1 != u2)
			return u1 - u2;
		if (u1 == '\0')
			return 0;
	}
}
