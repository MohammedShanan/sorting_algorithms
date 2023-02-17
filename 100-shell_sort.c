#include "sort.h"
void shell_sort(int *array, size_t size)
{
    size_t gap = 1, i;
    int tmp;
    if (array == NULL || size < 2)
        return;
    while (gap < size / 3)
    {
        gap = gap * 3 + 1;
    }
    while (gap)
    {
        for (i = gap; i < size; i++)
        {
            
        }

        gap / 2;
    }
}