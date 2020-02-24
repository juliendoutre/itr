#include <assert.h>
#include <iostream>

void incr(unsigned int nLoops, double *pCounter)
{
    for (unsigned int i = 0; i < nLoops; i++)
    {
        *pCounter += 1.0;
    }
}

int main(int argc, char *argv[])
{
    unsigned int nLoops;
    if (argc > 1)
    {
        nLoops = atoi(argv[1]);
    }
    else
    {
        nLoops = 0;
    }

    double counter = 0.0;

    incr(nLoops, &counter);

    std::cout << counter << std::endl;

    return 0;
}
