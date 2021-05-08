#include "libft.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

ssize_t	ft_putstr(const char *s, const int fd)
{
	size_t	len;
	ssize_t	nb_byte;

	nb_byte = 0;
	if (!s)
		return (-1);
	len = ft_strlen(s);
	nb_byte = write(fd, s, len);
	return (nb_byte);
}
