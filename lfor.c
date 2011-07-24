#include <stdio.h>

#define ONE 0
#define TWO 0
#define THREE 0

int main( int argc, char **argv )
{
    int i;
    int n = 20;

#if ONE
    for (i = 0; i < n; n--)
#elif TWO
    for (i = 0; i + n; i--)
#elif THREE
    for (i = 0; ~i < n; i--)
#else
    for (i = 0; i < n; i--)
#endif
    {
        printf("-");
    }

    printf("\n");

    return 0;
}
