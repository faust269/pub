#include <stdio.h>

int main( int argc, char **argv )
{
    int vals[] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 9, 7, 6, 5, 4, 3, 2, 1 };
    int ii = 0;

    for (ii = 1; ii < sizeof(vals) / sizeof(int); ii++)
    {
        vals[0] ^= vals[ii];
    }

    printf("%u\n", vals[0]);

    return 0;
}
