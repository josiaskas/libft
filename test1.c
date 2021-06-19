#include "./includes/ft_printf.h"
#include <stdio.h>

int main(void)
{
    int i, j = 0;

    i = ft_printf("Hello world !%c",10);
    j = printf("hello world !%c",10);
    return (0);
}