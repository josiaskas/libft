#include "includes/ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int i = ft_printf("%.d\n", 0);
	int j = printf("%.d\n", 0);
	return (0);
}
