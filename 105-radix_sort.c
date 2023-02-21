#include "sort.h"
int get_lsd(int num)
{
    if (num < 10)
    {
        return (num);
    }
    else
    {
        return (num % 10);
    }
}
int *set_up_counts(int *array, size_t size)
{
    int *counts;
    size_t i;
    int j, lsd;
    static int div = 1;
    counts = malloc(sizeof(int) * 10);
    if (counts == NULL)
        return (NULL);
    for (j = 0; j < 10; j++) /* memset counts array to 0 */
        counts[j] = 0;
    for (i = 0; i < size; i++) /* input counts */
    {
        lsd = get_lsd(array[i] / div);
        counts[lsd] += 1;
    }
    for (j = 0; j < 9; j++) /* update counts array */
    {
        counts[j + 1] += counts[j];
    }
    for (i = 9; i > 0; i--)
    {
        counts[i] = counts[i - 1];
    }
    counts[0] = 0;
    div *= 10;
    return (counts);
}
void radix_sort(int *array, size_t size)
{
    size_t i;
    int j, k, len_max = 0, lsd, div = 1;
    int *counts, *sorted;
    if (array == NULL || size < 2)
        return;
    k = array[0]; /* find max num to malloc size of new array */
    for (i = 1; i < size; i++)
    {
        if (array[i] > k)
            k = array[i];
    }
    for (i = 1; k / i; i *= 10)
        len_max++;
    sorted = malloc(sizeof(int) * size);
    if (!sorted)
        return;
    while (len_max)
    {
        counts = set_up_counts(array, size);
        for (i = 0; i < size; i++)
        {
            lsd = get_lsd(array[i] / div);
            j = counts[lsd];
            sorted[j] = array[i];
            counts[lsd] += 1;
        }
        print_array(sorted, size);
        for (i = 0; i < size; i++)
        {
            array[i] = sorted[i];
        }
        div *= 10;
        len_max--;
    }
    free(sorted);
    free(counts);
}
