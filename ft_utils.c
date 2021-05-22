#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (i);
	while (*s != 0)
	{
		s++;
		i++;
	}
	return (i);
}
