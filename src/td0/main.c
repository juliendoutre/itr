/**
 * @file
 * Example of communication on a bus with a hardware peripheral storing numbers in a fifo data structure.
 * - 0xfc000000 is the device writing port address.
 * - 0xfc000004 is the device reading port address.
 * - 0xfc000008 is the address of a port giving the number of elements stored in the queue.
 * */

#include <stdlib.h>
#include <stdio.h>

/**
 * This program writes number to the fifo, get its size to allocate memory to an array and then fetch the numbers back into it.
 * */
int main()
{
    volatile int *ports = (int *)0xfc000000; // `volatile` enables bypassing eventual compiler optimizations.
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
