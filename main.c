#include "./includes/libft.h"

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
}