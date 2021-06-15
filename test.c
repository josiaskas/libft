#include "includes/ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int i = ft_printf("--0*%0*.0d*0 0*%0*.10d*0-- ", -21, 2147483647, 21, -2147483648);
	int j = printf("--0*%0*.0d*0 0*%0*.10d*0-- ", -21, 2147483647, 21, -2147483648);
	return (0);
}
