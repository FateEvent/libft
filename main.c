#include "./includes/libft.h"
#include "./includes/ft_printf.h"

int main()
{
	int i = ft_putnbr_fd(456, 1);
	ft_printf("\n%d\n", i);
	i = ft_putnbr_fd(563737, 1);
	ft_printf("\n%d\n", i);
	i = ft_putnbr_fd(55555555, 1);
	ft_printf("\n%d\n", i);
	i = ft_putnbr_fd(65653, 1);
	ft_printf("\n%d\n", i);
	i = ft_putnbr_fd(5, 1);
	ft_printf("\n%d\n", i);
	i = ft_putnbr_fd(-2147483648, 1);
	ft_printf("\n%d\n", i);
	char *s = NULL;
	char *t = "Je vais faire les courses";
	ft_printf("%d\n", ft_printf("%s\t%p\n", s, s));
	ft_printf("%d\n", ft_printf("%s\t%p\n", t, t));
	printf("%d\n", printf("%s\t%p\n", s, s));
	printf("%d\n", printf("%s\t%p\n", t, t));

	printf("%ld\n", atol("-9223372036854775808"));
	printf("%lld\n", ft_atol("-9223372036854775808"));
	printf("%ld\n", atol("9223372036854775807"));
	printf("%lld\n", ft_atol("9223372036854775807"));
	printf("%llu\n", ft_atollu("-9223372036854775808"));
	printf("%llu\n", ft_atollu("9223372036854775807"));

	printf("%#0.0s empty string\n", "house");
	ft_printf("%#0.0s empty string\n", "house");
}