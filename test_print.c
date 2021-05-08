#include "libft.h"

size_t	local_strlen(const char *s)
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

void	ft_print_error(const char *message)
{
	size_t	taille;

	taille = local_strlen(message);
	write(1, "\033[0;31m", 7);
	write(1, message, taille);
	write(1, "\033[0;39m\n", 8);
}

void	ft_print_success(const char *message)
{
	size_t	taille;

	taille = local_strlen(message);
	write(1, "\033[0;32m", 7);
	write(1, message, taille);
	write(1, "\033[0;39m\n", 8);
}
