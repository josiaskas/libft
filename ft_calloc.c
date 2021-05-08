#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*heap_p;

	if ((size == 0) || (count == 0))
		return (0);
	heap_p = malloc(count * size);
	if (!heap_p)
		return (0);
	ft_bzero(heap_p, count * size);
	return (heap_p);
}
