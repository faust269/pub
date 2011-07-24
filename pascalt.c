#include <stdio.h>

long double factorial(int col)
{
	long double fac = 1;

	for (int i = 1; i <= col; i++ )
	{
		fac *= i;
	}

	return fac;
}

int Pascal(int row, int col)
{
	long double val = row;

	if (col > row || col < 0 || row < 0)
	{
		return 0;
	}

	if (col == 0 || col == row)
	{
		return 1;
	}
	else if (col == 1)
	{
		return row + 1;
	}
	else if (row == 1)
	{
		return col + 1;
	}
    
	for (int i = row - 1; i >= (row - col + 1); i--)
	{
		val = val * i;
	}

	val = val / factorial(col);

	return (int)val;
}

int main(int argc, char **argv)
{
    if (argc < 3)
    {
        return -1;
    }

    printf("Value is: %u", Pascal(atoi(argv[1], atoi(argv[2]))));

    return 0;
}
