#include	"libft.h"

char	*ft_strdup(const char *s1)
{
	char	*heap_p;
	char	*p;
	size_t	len;

	len = 0;
	while (s1[len])
		len++;
	heap_p = malloc(len + 1);
	if (!heap_p)
		return (0);
	p = heap_p;
	while (*s1 != 0)
		*p++ = *s1++;
	*p = '\0';
	return (heap_p);
}
