#include "includes/ft_printf.h"
#include <stdio.h>

int	main(void)
{
	char	c;
	char	t;

	c = 'b';
	t = 'r';
	ft_printf("s%03ctx %c\n", 98, t);
	printf("s%03ctx %c\n", 98, t);
	return (0);
}
