#include "includes/ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int i = 0;
	int j = 0;

	i = ft_printf("%-23X\n",10);
	j = printf("%-23X\n",10);

	return (0);
}
