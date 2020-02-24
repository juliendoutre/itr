#include <stdlib.h>

// Example of communication on a bus with a hardware peripheral storing numbers in a fifo data structure.
// 0xfc000000 is the address of the writing port of the device.
// 0xfc000004 is the address of the reading port of the device.
// 0xfc000008 is the address of a port giving the number of elements stored in the queue.

int main()
{
    // volatile allows to bypass eventual compiler optimizations.
    volatile int ports[3] = 0xfc000000;

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
