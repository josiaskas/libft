#include "includes/ft_printf.h"
#include <stdio.h>

int	main(void)
{
	char	str[] = "hello world!";

	ft_printf("%s\n", str);
	printf("%s\n", str);
	return (0);
}
