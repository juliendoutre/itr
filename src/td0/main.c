/**
 * @file
 * Example program for @ref td0.
 * @anchor td0_main
 **/

#include <stdlib.h>
#include <stdio.h>

int main()
{
    // `volatile` enables bypassing eventual compiler optimizations.
    volatile int *ports = (int *)0xfc000000;
    printf("%x", ports[0]);
    printf("%x", ports[1]);
    printf("%x", ports[2]);

    for (int i = 1; i < 1000; i += 2)
    {
        ports[0] = i;
    }

    int size = ports[2];
    int *tab = malloc(size);

    for (int i = 0; i < size; i++)
    {
        tab[i] = ports[1];
    }

    free(tab);

    return 0;
}
