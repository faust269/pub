#include <stdio.h>

int main( int argc, char **argv )
{
    long val = 255;
    int ii = 0;

#ifdef SIMPLE
    while (val)
    {
        val &= val - 1;
        ii++;
    }
#else
    val = val - ((val >> 1) & 0x55555555);
    val = (val & 0x33333333) + ((val >> 2) & 0x33333333);
    ii = ((val + (val >> 4) & 0xF0F0F0F) * 0x1010101) >> 24;
#endif

    printf("%d\n", ii);

    return 0;
}
