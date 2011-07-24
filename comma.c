#include <stdio.h>

#define POS

struct S0 
{
    unsigned f1 : 1;
};
 
struct S0 s;
 
int main( void ) 
{
#ifdef POS
    int x = 3;
#else
    int x = -3;
#endif
    int y = x >= (0, s.f1); 

    printf ("%d\n", y);

    return 0;
}
