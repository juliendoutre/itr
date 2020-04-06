/**
 * @page td0 TD 0
 *
 * @section Summary
 * Example of communication on a bus with a hardware peripheral storing numbers in a fifo data structure.
 * - `0xfc000000` is the device writing port address.
 * - `0xfc000004` is the device reading port address.
 * - `0xfc000008` is the address of a port giving the number of elements stored in the queue.
 * @section Purpose
 * This demonstrates the use of the `volatile` keyword, telling the compiler a variable \
 * can be overwritten with values at anytime and that this behavior should not be optimized.
 * @section files Related files
 * -  @ref td0_main "src/td0/main.c"
 * */

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
