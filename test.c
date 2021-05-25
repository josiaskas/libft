#include "includes/ft_printf.h"

int	main(void)
{
	char	c;
	char	t;

	c = 'b';
	t = 'r';
	ft_printf("s%03ctx %c", c, t);
	return (0);
}
