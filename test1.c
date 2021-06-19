#include "./includes/ft_printf.h"
#include <stdio.h>

int main(void)
{
    int i, j = 0;

    i = ft_printf("%% *.5i 42 == |% *.5i|\n", 4, 42);
    j = printf("%% *.5i 42 == |% *.5i|\n", 4, 42);
    return (0);
}

