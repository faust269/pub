#include <stdio.h>

int array[] = { 7, 8, 9, 0, 1, 2, 3, 4, 5, 6 };

int bin_search( int start_idx, int end_idx, int val )
{
    int mid_idx = (start_idx + end_idx) / 2;

    if (val == array[mid_idx])
    {
        return mid_idx;
    }
    else if (start_idx == end_idx)
    {
        return -1;
    }
    else if (val < array[mid_idx])
    {
        return bin_search(start_idx, mid_idx - 1, val);
    }
    else
    {
        return bin_search(mid_idx + 1, end_idx, val);
    }
}

int find_idx( int start_idx, int end_idx, int val )
{
    int mid_idx = (start_idx + end_idx) / 2;
    int idx = 0;

    if (array[start_idx] < array[end_idx])
    {
        /*
         ** normal binary search
         */
        idx = bin_search(start_idx, end_idx, val);
    }
    else if ((idx = find_idx(start_idx, mid_idx, val)) == -1)
    {
        idx = find_idx(mid_idx + 1, end_idx, val);
    }

    return idx;
}

int main( int argc, char **argv )
{
    int idx = 0;

    idx = find_idx(0, sizeof(array) / sizeof(int) - 1, atoi(argv[1]));

    if (idx == -1)
    {
        printf("Index not found\n");
    }
    else
    {
        printf("Index is: %u\n", idx);
    }

    return 0;
}
